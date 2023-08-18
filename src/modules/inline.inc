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


dpp_createinline(name[], baseformid); public dpp_createinline(name[], baseformid)
{
    dpp_symbolcheck__(name);
    for(new i; i < dpp_maxinline; i++)
    {
        if(dpp_validinline[i] == 0)
        {
            dpp_validinline[i] = 1;
            strmid(dpp_inlinename[i], name, 0, 64, 64);
            dpp_inlinebaseform[i] = baseformid;
            dpp_currentinlineid = i;
            //dpp_error("Created an inline named '%s' [%i] with base form id '%i'",name,dpp_currentinlineid,baseformid);
            return 1;
        }
    }
    return 1;
}

stock dpp_clearformstack(formid)
{
    for(new i; i < dpp_maxinline; i++)
    {
        if(dpp_inlinebaseform[i] == formid)
        {
            dpp_validinline[i] = 0;
            @emit__ stk@pop ,.str=dpp_inlinename[i]
            strmid(dpp_inlinecodeblock[i],";",0,10,10);
            return 1;
        }
    }
    return 1;
}