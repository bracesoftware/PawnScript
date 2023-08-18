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

stock dpp_createtag(name[])
{
    //dpp_symbolcheck__(name);
    for(new i; i < dpp_maxtag; i++)
    {
        if(dpp_validobj[i] == 0)
        {
            dpp_validobj[i] = 1;

            if(dpp_workingclassid != dpp_invalidclass)
            {
                new newvalue[dpp_argcharsize];
                format(newvalue,sizeof(newvalue),"DPPCo@%s_%s",dpp_classname[dpp_workingclassid],name);
                strmid(name, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            }

            dpp_symbolcheck__(name);

            strmid(dpp_objname[i], name, 0, dpp_maxsymbolchar, dpp_maxsymbolchar);

            return 1;
        }
    }
    return 1;
}


dpp_argtagcheck(arg[]);
public dpp_argtagcheck(arg[])
{
    new 
        newvalue[64],
        tagid = -1;

    dpp_argclasscheck(arg);
    dpp_argoclasscheck(arg);

    for(new i; i < dpp_maxtag; i++)
    {
        if(dpp_validobj[i] == 1 && !strcmp(arg, dpp_objname[i]))
        {
            tagid = i;
            break;
        }
    }

    if(tagid == -1)
    {
        return 1;
    }

    format(newvalue, sizeof newvalue, "%i", tagid);

    strmid(arg, newvalue, 0, dpp_maxsymbolchar, dpp_maxsymbolchar);
    return 1;
}