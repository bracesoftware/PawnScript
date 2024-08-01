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


stock dpp_argclasscheck(arg[])
{
    new 
        newvalue[dpp_argcharsize],
        classvalid = 0,
        funcgroup[2][100];
    dpp_parseline_2(arg, funcgroup, "::");

    for(new i; i < dpp_maxclass; i++)
    {
        if(!strcmp(dpp_classname[i],funcgroup[0]) && dpp_validclass[i] == 1)
        {
            classvalid = 1;
            break;
        }
    }

    if(classvalid == 0)
    {
        dpp_debug("Specified namespace is not a valid namespace.");
        return 1;
    }

    format(newvalue,sizeof(newvalue),"DPPCf@%s_%s",funcgroup[0],funcgroup[1]);
    dpp_debug("Class backtrace 1:\n\tnewvalue : '%s'",newvalue);

    for(new i; i < dpp_maxfuncs; i++)
    {
        if(!strcmp(dpp_funcname[i],newvalue) && dpp_validfunc[i] == 1)
        {
            strmid(arg, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            break;
        }
    }

    format(newvalue,sizeof(newvalue),"DPPCc@%s_%s",funcgroup[0],funcgroup[1]);
    dpp_debug("Class backtrace 2:\n\tnewvalue : '%s'",newvalue);

    for(new i; i < dpp_maxconst; i++)
    {
        if(!strcmp(dpp_constdata[i][const_name],newvalue) && dpp_constdata[i][const_valid] == 1)
        {
            strmid(arg, newvalue, 0, dpp_argcharsize,dpp_argcharsize);//classelementvalid[dpp_classelement_const] = 1;
            break;
        }
    }

    format(newvalue,sizeof(newvalue),"DPPCv@%s_%s",funcgroup[0],funcgroup[1]);
    dpp_debug("Class backtrace 3:\n\tnewvalue : '%s'",newvalue);

    for(new i; i < dpp_maxvar; i++)
    {
        if(!strcmp(dpp_vardata[i][var_name],newvalue) && dpp_vardata[i][var_valid] == 1)
        {
            strmid(arg, newvalue, 0, dpp_argcharsize,dpp_argcharsize);//classelementvalid[dpp_classelement_var] = 1;
            break;
        }
    }

    format(newvalue,sizeof(newvalue),"DPPCi@%s_%s",funcgroup[0],funcgroup[1]);
    dpp_debug("Class backtrace 3:\n\tnewvalue : '%s'",newvalue);

    for(new i; i < dpp_maxiter; i++)
    {
        if(!strcmp(dpp_itername[i],newvalue) && dpp_validiter[i] == 1)
        {
            strmid(arg, newvalue, 0, dpp_argcharsize,dpp_argcharsize);//classelementvalid[dpp_classelement_var] = 1;
            break;
        }
    }

    format(newvalue,sizeof(newvalue),"DPPCo@%s_%s",funcgroup[0],funcgroup[1]);
    dpp_debug("Class backtrace 3:\n\tnewvalue : '%s'",newvalue);

    for(new i; i < dpp_maxtag; i++)
    {
        if(!strcmp(dpp_objname[i],newvalue) && dpp_validobj[i] == 1)
        {
            strmid(arg, newvalue, 0, dpp_argcharsize,dpp_argcharsize);//classelementvalid[dpp_classelement_var] = 1;
            break;
        }
    }


    format(newvalue,sizeof(newvalue),"DPPCoc@%s_%s",funcgroup[0],funcgroup[1]);
    dpp_debug("Class backtrace 3:\n\tnewvalue : '%s'",newvalue);

    for(new i; i < dpp_maxoclass; i++)
    {
        if(!strcmp(dpp_oclassname[i],newvalue) && dpp_validoclass[i] == 1)
        {
            strmid(arg, newvalue, 0, dpp_argcharsize,dpp_argcharsize);//classelementvalid[dpp_classelement_var] = 1;
            break;
        }
    }

    format(newvalue,sizeof(newvalue),"DPPCy@%s_%s",funcgroup[0],funcgroup[1]);
    dpp_debug("Class backtrace 3:\n\tnewvalue : '%s'",newvalue);

    for(new i; i < dpp_maxvector; i++)
    {
        if(!strcmp(dpp_vectorname[i],newvalue) && dpp_validvector[i] == 1)
        {
            strmid(arg, newvalue, 0, dpp_argcharsize,dpp_argcharsize);//classelementvalid[dpp_classelement_var] = 1;
            break;
        }
    }

    format(newvalue,sizeof(newvalue),"DPPCe@%s_%s",funcgroup[0],funcgroup[1]);
    dpp_debug("Class backtrace 3:\n\tnewvalue : '%s'",newvalue);

    for(new i; i < dpp_maxenum; i++)
    {
        if(!strcmp(dpp_enumname[i],newvalue) && dpp_validenum[i] == 1)
        {
            strmid(arg, newvalue, 0, dpp_argcharsize,dpp_argcharsize);//classelementvalid[dpp_classelement_var] = 1;
            break;
        }
    }

    format(newvalue,sizeof(newvalue),"dppptrn@%s_%s",funcgroup[0],funcgroup[1]);
    dpp_debug("Class backtrace 3:\n\tnewvalue : '%s'",newvalue);

    for(new i; i < dpp_maxptr; i++)
    {
        if(!strcmp(dpp_ptrdata[i][ptr_name],newvalue) && dpp_ptrdata[i][ptr_valid] == 1)
        {
            strmid(arg, newvalue, 0, dpp_argcharsize,dpp_argcharsize);//classelementvalid[dpp_classelement_var] = 1;
            break;
        }
    }

    //dpp_debug("Class backtrace 4:\n\tclassvalid : '%i'\n\tclasselementvalid[0] : '%i'\n\tclasselementvalid[1] : '%i'\n\tclasselementvalid[2] : '%i'",classvalid,classelementvalid[0],classelementvalid[1],classelementvalid[2]);


    dpp_debug("Namespace backtrace 4:\n\tfuncgroup[0] : '%s'\n\tfuncgroup[1] : '%s'\n\targ : '%s'",funcgroup[0],funcgroup[1],arg);
    return 1;
}

stock dpp_createclass(const name[], constexpr = 0)
{
    dpp_symbolcheck__(name);
    for(new i; i < dpp_maxclass; i++)
    {
        if(dpp_validclass[i] == 0)
        {
            dpp_validclass[i] = 1;
            dpp_classconstexpr[i] = constexpr;
            strmid(dpp_classname[i], name, 0, 64,64);
            dpp_lastclass = i;
            return 1;
        }
    }
    return 1;
}

stock dpp_hookclass(const name[])
{
    for(new i; i < dpp_maxclass; i++)
    {
        if(!strcmp(dpp_classname[i],name) && dpp_validclass[i] == 1)
        {
            if(dpp_classconstexpr[i] == 1)
            {
                dpp_fatalerror(1);
                return 1;
            }
            dpp_lastclass = i;
            return 1;
        }
    }
    dpp_error("Namespace \"%s\" does not exist.",name);
    return 1;
}