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

// THIS IS A VERY IMPORTANT FILE!
// It pushes symbol names to the stack.

dpp_initstk();
public dpp_initstk()
{
    for(new i; i < DPP_STKSIZE; i++)
    {
        // Initial value doesn't matter, it'll be replaced.
        strmid(dpp_stkreg[i], DPP_STKNULL, 0, dpp_maxsymbolchar, dpp_maxsymbolchar);
    }
    return 1;
}

dpp__emitpush___(const value[]) //push
{
    if(dpp_allowcollision == 0)
    {
        for(new x; x < DPP_STKSIZE; x++)
        {
            if(strcmp(dpp_stkreg[x], value) == 0)
            {
                dpp_fatalerror(5, value); // Symbol is already found in the stack.
                return 0;
            } 
        }
    }
    dpp_allowcollision = 0;
    for(new x; x < DPP_STKSIZE; x++)
    {
        if(strcmp(dpp_stkreg[x], DPP_STKNULL) == 0)
        {
            strmid(dpp_stkreg[x], value, 0, dpp_maxsymbolchar, dpp_maxsymbolchar);
            return 0;
        } 
    }
    return 0;
}

dpp__emitpop___(const value[]) //pop
{
    for(new x; x < DPP_STKSIZE; x++)
    {
        if(strcmp(dpp_stkreg[x], value) == 0)
        {
            strmid(dpp_stkreg[x], DPP_STKNULL, 0, dpp_maxsymbolchar, dpp_maxsymbolchar);
        } 
    }
    return 0;
}