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



stock dpp_createenum(name[])
{
    dpp_symbolcheck__(name);
    for(new i; i < dpp_maxenum; i++)
    {
        if(dpp_validenum[i] == 0)
        {
            if(dpp_workingclassid != dpp_invalidclass)
            {
                new newvalue[dpp_argcharsize];
                format(newvalue,sizeof(newvalue),"DPPCe@%s_%s",dpp_classname[dpp_workingclassid],name);
                strmid(name, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            }
            dpp_validenum[i] = 1;
            dpp_currentenumid = i;
            strmid(dpp_enumname[i], name, 0, dpp_maxsymbolchar, dpp_maxsymbolchar);
            return 1;
        }
    }
    return 1;
}

stock dpp_addenumval(enumid, const valname[], value)
{
    for(new i; i < dpp_maxenumvals; i++)
    {
        if(dpp_enumvalues[enumid][i][e_valid] == 0)
        {
            dpp_enumvalues[enumid][i][e_valid] = 1;
            dpp_enumvalues[enumid][i][e_value] = value;
            strmid(dpp_enumvalues[enumid][i][e_valname], valname, 0, dpp_maxsymbolchar, dpp_maxsymbolchar);
            return 1;   
        }
    }
    return 0;
}

forward dpp_argenumcheck(arg[]);
public dpp_argenumcheck(arg[])
{
    new newvalue[dpp_argcharsize],
        enumdata[2][dpp_maxsymbolchar];

    dpp_parseline(arg,enumdata,'.');

    dpp_argclasscheck(enumdata[0]);

    new enumid = -1;
    for(new i; i < dpp_maxenum; i++)
    {
        if(!strcmp(dpp_enumname[i],enumdata[0]) && dpp_validenum[i] == 1)
        {
            enumid = i;
            break;
        }
    }

    if(enumid == -1)
    {
        return 1;
    }

    for(new i; i < dpp_maxenumvals; i++)
    {
        if(!strcmp(dpp_enumvalues[enumid][i][e_valname], enumdata[1]))
        {
            if(dpp_enumvalues[enumid][i][e_valid] == 1)
            {
                format(newvalue, sizeof newvalue, "%i", dpp_enumvalues[enumid][i][e_value]);
                break;
            }
        }
    }
    strmid(arg, newvalue, 0, dpp_argcharsize, dpp_argcharsize);
    return 1;
}