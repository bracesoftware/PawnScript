/*

Version: MPL 1.1

The contents of this file are subject to the Mozilla Public License Version 
1.1 the "License"; you may not use this file except in compliance with 
the License. You may obtain a copy of the License at 
http://www.mozilla.org/MPL/

Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
for the specific language governing rights and limitations under the
License.

Portions created by the Initial Developer are Copyright (c) 2022
the Initial Developer. All Rights Reserved.

*/



#define dpp_ismathoperator(%0) (%0=='+'||%0=='-'||%0=='*'||%0=='/'||%0=='^')
#define dpp_isinrange(%0,%1,%2) (((%0)-((%1)+cellmin))<((%2)-((%1)+cellmin))) 
// creds Y_Less



stock levenstein(const a[], const b[]) { //southclaws
    new
        aLength = strlen(a),
        bLength = strlen(b),
        cache[256],
        index = 0,
        bIndex = 0,
        distance,
        bDistance,
        result,
        code;

    if (!strcmp(a, b)) {
        return 0;
    }

    if (aLength == 0) {
        return bLength;
    }

    if (bLength == 0) {
        return aLength;
    }

    while (index < aLength) {
        cache[index] = index + 1;
        index++;
    }

    while (bIndex < bLength) {
        code = b[bIndex];
        result = distance = bIndex++;
        index = -1;

        while (++index < aLength) {
            bDistance = code == a[index] ? distance : distance + 1;
            distance = cache[index];

            cache[index] = result = distance > result
            ? bDistance > result
                ? result + 1
                : bDistance
            : bDistance > distance
                ? distance + 1
                : bDistance;
        }
    }

    return result;
}


enum string_edges {
    edge_left  = 1,
    edge_right = 2,
    edge_both = edge_left | edge_right
};

// Big thanks to Slice (oscar broman), without him
// PawnScript would not exist the way it does now
stock dpp_codetrim(string[], const chars[] = !"", string_edges:edge = edge_both) 
{
    new bool:packed = ispacked(string);
    
    // If "chars" is empty, trim whitespace
    if (!(ispacked(chars) ? chars{0} : chars[0])) {
        // Should the left side be trimmed?
        if (edge & edge_left) {
            new i = 0;
            
            if (packed)
                while (0 < string{i} <= ' ') i++;
            else
                while (0 < string[i] <= ' ') i++;
            
            if (i) {
                strdel(string, 0, i);
            }
        }
        
        // Should the right side be trimmed?
        if (edge & edge_right) {
            new i = strlen(string);
            
            if (i) {
                if (packed) {
                    while (--i && 0 < string{i} <= ' ') {}
                    
                    string{i + 1} = '\0';
                } else {
                    while (--i && 0 < string[i] <= ' ') {}
                    
                    string[i + 1] = '\0';
                }
            }
        }
    } else {
        // Should the left side be trimmed?
        if (edge & edge_left) {
            new i = 0, sub[2];
            
            if (packed) {
                while ((sub[0] = string{i})) {
                    if (strfind(chars, sub) == -1)
                        break;
                    
                    i++;
                }
                
                if (i) {
                    strdel(string, 0, i);
                }
            } else {
                while ((sub[0] = string[i])) {
                    if (strfind(chars, sub) == -1)
                        break;
                    
                    i++;
                }
                
                if (i) strdel(string, 0, i);
            }
        }
        
        // Should the right side be trimmed?
        if (edge & edge_right) {
            new i = strlen(string), sub[2];
            
            if (i >= 0) {
                if (packed) {
                    while (i--) {
                        sub[0] = string{i};
                        
                        if (strfind(chars, sub) == -1)
                            break;
                    }
                    
                    string{i + 1} = '\0';
                } else {
                    while (i--) {
                        sub[0] = string[i];
                        
                        if (strfind(chars, sub) == -1)
                            break;
                    }
                    
                    string[i + 1] = '\0';
                }
            }
        }
    }
}


stock bool:dpp_isnumeric(const str[]) // creds Y_Less
{
    new
        i = -1;
    if (ispacked(str))
    {
        if (str{0} == '-') ++i;
        while (dpp_isinrange(str{++i}, '0', '9' + 1)) {}
        return !str{i};
    }
    else
    {
        if (str[0] == '-') ++i;
        while (dpp_isinrange(str[++i], '0', '9' + 1)) {}
        return !str[i];
    }
}

stock bool:dpp_isfloat(const str[])
{
    new numerals[2][64];
    dpp_parseline(str, numerals, '.');
    if(dpp_isnumeric(numerals[0]) && dpp_isnumeric(numerals[1]))
    {
        return true;
    }
    return false;
}

stock dpp_isargstr(const argument[]) // creds DEntisT
{
    new mul;
    for(new i; i < strlen(argument); i++)
    {
        if(argument[i] == '\"') mul++;
    }
    if(mul == 0)
    {
        return 0;
    }
    if(mul != 2)
    {
        return 0;
    }
    return 1;
}

stock dpp_strreplace(string[], const search[], const replacement[], bool:ignorecase = false, pos = 0, limit = -1, maxlength = sizeof(string)) // creds Slice
{
    // No need to do anything if the limit is 0.
    if (limit == 0)
        return 0;
    
    new
             sublen = strlen(search),
             replen = strlen(replacement),
        bool:packed = ispacked(string),
             maxlen = maxlength,
             len = strlen(string),
             count = 0
    ;
    
    
    // "maxlen" holds the max string length (not to be confused with "maxlength", which holds the max. array size).
    // Since packed strings hold 4 characters per array slot, we multiply "maxlen" by 4.
    if (packed)
        maxlen *= 4;
    
    // If the length of the substring is 0, we have nothing to look for..
    if (!sublen)
        return 0;
    
    // In this line we both assign the return value from "strfind" to "pos" then check if it's -1.
    while (-1 != (pos = strfind(string, search, ignorecase, pos))) {
        // Delete the string we found
        strdel(string, pos, pos + sublen);
        
        len -= sublen;
        
        // If there's anything to put as replacement, insert it. Make sure there's enough room first.
        if (replen && len + replen < maxlen) {
            strins(string, replacement, pos, maxlength);
            
            pos += replen;
            len += replen;
        }
        
        // Is there a limit of number of replacements, if so, did we break it?
        if (limit != -1 && ++count >= limit)
            break;
    }
    
    return count;
}

stock bool:dpp_strcmp(const str1[], const str2[], bool:ignorecase = false) //creds slice
{
    new
        c1 = (str1[0] > 255) ? str1{0} : str1[0],
        c2 = (str2[0] > 255) ? str2{0} : str2[0]
    ;

    if (!c1 != !c2)
        return false;

    return !strcmp(str1, str2, ignorecase);
}