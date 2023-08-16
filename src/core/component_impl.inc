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