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


stock Float:dpp_math__vectorsize(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2)
{
    new
        Float:a = x1 < x2 ? x2 - x1 : x1 - x2,
        Float:b = y1 < y2 ? y2 - y1 : y1 - y2,
        Float:h = z1 < z2 ? z2 - z1 : z1 - z2,
        Float:base_hyp = floatsqroot(a*a+b*b);

    return floatsqroot(h*h + base_hyp*base_hyp); 
}


stock dpp_data__strdist(const a[], const b[])
{
    new 
        dist, 
        lena = strlen(a), 
        lenb = strlen(b);

    if(!strcmp(a, b))
    {
        return 0;
    }

    for(new i; i < (lena < lenb ? lena : lenb); i++)
    {
        if(a[i] != b[i])
        {
            dist = dist + 1;
        }
    }

    dist = dist + (lena < lenb ? lenb - lena : lena - lenb);

    return dist;
}

stock dpp_data__testfunc()
{
    if(dpp_lastdeco == dpp_deco_import)
    {
        dpp_info("dpp_data__testfunc IMPORT | typename : '%s' | to : '%s' | from : '%s'", dpp_typename__,dpp_to__,dpp_from__);
        new mul2;
        for(new i; i < strlen(dpp_from__); i++)
        {
            if(dpp_from__[i] == '\"') mul2++, strdel(dpp_from__, i, i+1);
        }
        if(mul2 == 0)
        {
            dpp_error("You need to use '\"' to start a string.",);
            return 0;
        }
        if(mul2 != 2)
        {
            dpp_error("Argument error; [%i] \"%s\"", mul2, dpp_from__);
            return 0;
        }

        new varid = -1;

        for(new i; i < dpp_maxvar; i++)
        {
            if(!strcmp(dpp_vardata[i][var_name], dpp_to__))
            {
                if(dpp_vardata[i][var_valid] == 1)
                {
                    varid = i;
                    break;
                }
            }
        }
        
        if(varid == -1)
        {
            dpp_error("Invalid variable specified ('%s').",dpp_to__);
            return 1;
        }

        if(!strcmp(dpp_typename__, "int")) //if(!strcmp(structgroup[1],"int"))
        {
            dpp_importint(dpp_from__,varid);
            return 1;
        }
        if(!strcmp(dpp_typename__, "bool")) //if(!strcmp(structgroup[1], "bool"))
        {
            dpp_importbool(dpp_from__,varid);
            return 1;
        }
        if(!strcmp(dpp_typename__, "str")) //if(!strcmp(structgroup[1], "str"))
        {
            dpp_importstr(dpp_from__,varid);
            return 1;
        }
        if(!strcmp(dpp_typename__, "double")) //if(!strcmp(structgroup[1], "double"))
        {
            dpp_importdouble(dpp_from__,varid);
            return 1;
        }
        if(!strcmp(dpp_typename__, "char")) //if(!strcmp(structgroup[1], "char"))
        {
            dpp_importchar(dpp_from__,varid);
            return 1;
        }

        dpp_error("Invalid data type specified.",);
        return 1;
    }

    if(dpp_lastdeco == dpp_deco_export)
    {
        dpp_info("dpp_data__testfunc EXPORT | typename : '%s' | to : '%s' | from : '%s'", dpp_typename__,dpp_to__,dpp_from__);
        new mul2;
        for(new i; i < strlen(dpp_to__); i++)
        {
            if(dpp_to__[i] == '\"') mul2++, strdel(dpp_to__, i, i+1);
        }
        if(mul2 == 0)
        {
            dpp_error("You need to use '\"' to start a string.",);
            return 0;
        }
        if(mul2 != 2)
        {
            dpp_error("Argument error; [%i] \"%s\"", mul2, dpp_to__);
            return 0;
        }

        new varid = -1;

        for(new i; i < dpp_maxvar; i++)
        {
            if(!strcmp(dpp_vardata[i][var_name], dpp_from__))
            {
                if(dpp_vardata[i][var_valid] == 1)
                {
                    varid = i;
                    break;
                }
            }
        }

        if(varid == -1)
        {
            dpp_error("Invalid variable specified ('%s').",dpp_from__);
            return 1;
        }

        if(!strcmp(dpp_typename__, "int"))
        {
            dpp_exportint(dpp_to__,dpp_vardata[varid][integervalue]);
            return 1;
        }
        if(!strcmp(dpp_typename__, "bool"))
        {
            dpp_exportbool(dpp_to__,dpp_vardata[varid][boolvalue]);
            return 1;
        }
        if(!strcmp(dpp_typename__, "str"))
        {
            dpp_exportstr(dpp_to__,dpp_vardata[varid][stringvalue]);
            return 1;
        }
        if(!strcmp(dpp_typename__, "double"))
        {
            dpp_exportdouble(dpp_to__,dpp_vardata[varid][floatvalue]);
            return 1;
        }
        if(!strcmp(dpp_typename__, "char"))
        {
            dpp_exportchar(dpp_to__,dpp_vardata[varid][charvalue]);
            return 1;
        }

        dpp_error("Invalid data type specified.",);
        return 1;
    }
    return 1;
}