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


stock dpp_argoclasscheck(arg[])
{
    new 
        newvalue[dpp_argcharsize],
        objectvalid = 0,
        funcgroup[2][100];
    dpp_parseline(arg, funcgroup, '.');

    for(new i; i < dpp_maxobj; i++)
    {
        if(!strcmp(dpp_objectname[i],funcgroup[0]) && dpp_validobject[i] == 1)
        {
            objectvalid = 1;
            break;
        }
    }

    if(objectvalid == 0)
    {
        dpp_debug("Specified object is not a valid object.");
        return 1;
    }

    format(newvalue,sizeof(newvalue),"DPPOv@%s_%s",funcgroup[0],funcgroup[1]);

    for(new i; i < dpp_maxvar; i++)
    {
        if(!strcmp(dpp_vardata[i][var_name],newvalue) && dpp_vardata[i][var_valid] == 1)
        {
            strmid(arg, newvalue, 0, dpp_argcharsize,dpp_argcharsize);//classelementvalid[dpp_classelement_var] = 1;
            break;
        }
    }

    format(newvalue,sizeof(newvalue),"DPPOf@%s_%s",funcgroup[0],funcgroup[1]);

    for(new i; i < dpp_maxfuncs; i++)
    {
        if(!strcmp(dpp_funcname[i],newvalue) && dpp_validfunc[i] == 1)
        {
            strmid(arg, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            break;
        }
    }

    //dpp_debug("Class backtrace 4:\n\tclassvalid : '%i'\n\tclasselementvalid[0] : '%i'\n\tclasselementvalid[1] : '%i'\n\tclasselementvalid[2] : '%i'",classvalid,classelementvalid[0],classelementvalid[1],classelementvalid[2]);

    return 1;
}


//////////UTIL//////////

stock dpp_createoclass(name[])
{
    dpp_symbolcheck__(name);
    for(new i; i < dpp_maxoclass; i++)
    {
        if(dpp_validoclass[i] == 0)
        {
            dpp_validoclass[i] = 1;
            if(dpp_workingclassid != dpp_invalidclass)
            {
                new newvalue[dpp_argcharsize];
                format(newvalue,sizeof(newvalue),"DPPCoc@%s_%s",dpp_classname[dpp_workingclassid],name);
                strmid(name, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            }
            strmid(dpp_oclassname[i], name, 0, dpp_maxsymbolchar, dpp_maxsymbolchar);
            dpp_usedclassid = i;
            return 1;
        }
    }
    return 1;
}

stock bool:dpp_isvalidclass(name[])
{
    dpp_argclasscheck(name);
    for(new i; i < dpp_maxoclass; i++)
    {
        if(dpp_validoclass[i] == 1)
        {
            if(!strcmp(dpp_oclassname[i], name))
            {
                //dpp_error("CLASS BACKTRACE :: Class '%s' found.",name);
                return true;
            }
        }
    }
    //dpp_error("CLASS BACKTRACE :: Class '%s' not found.",name);
    return false;
}

stock dpp_setunion(const name[])
{
    if(!strcmp(name,"explicit"))
    {
        return 1;
    }
    if(!strcmp(name,"false"))
    {
        return 1;
    }
    strmid(dpp_currentunion, name, 0,dpp_unmsize,dpp_unmsize);
    return 1;
}

stock dpp_createobject(const name[], const classname[], const union[])
{
    //dpp_argclasscheck(classname);
    dpp_symbolcheck__(name);
    //dpp_error("Created a class '%s' -> '%s'",name,classname);
    new classid = -1;
    for(new i; i < dpp_maxoclass; i++)
    {
        if(dpp_validoclass[i] == 1 && !strcmp(dpp_oclassname[i],classname))
        {
            classid = i;
            break;
        }
    }

    if(classid == -1)
    {
        dpp_error("Invalid class specified.",);
        return 1;
    }

    for(new i; i < dpp_maxobj; i++)
    {
        if(dpp_validobject[i] == 0)
        {
            dpp_validobject[i] = 1;
            strmid(dpp_objectname[i], name, 0, dpp_maxsymbolchar, dpp_maxsymbolchar);
            dpp_currentobject = i;
            break;
        }
    }

    dpp_explicit__ = 0;
    if(!strcmp(union,"explicit"))
    {
        dpp_explicit__ = 1;
    }
    strmid(dpp_currentunion,"false",0,dpp_unmsize,dpp_unmsize);
    strmid(dpp_currentunionreq, union, 0,dpp_unmsize,dpp_unmsize);

    dpp_subexecute2(dpp_oclassblock[classid]);
    dpp_currentobject = DPP_INVALID_OBJECT_ID;
    return 1;
}