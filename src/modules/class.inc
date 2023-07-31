/*
*
* D++ Scripting Language
*     Made for a SA:MP server
*
*  Class and Object System
*
* 
* - by: DEntisT, (c) 2022
*
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

    //dpp_debug("Class backtrace 4:\n\tclassvalid : '%i'\n\tclasselementvalid[0] : '%i'\n\tclasselementvalid[1] : '%i'\n\tclasselementvalid[2] : '%i'",classvalid,classelementvalid[0],classelementvalid[1],classelementvalid[2]);

    return 1;
}


//////////UTIL//////////

stock dpp_createoclass(const name[])
{
    for(new i; i < dpp_maxoclass; i++)
    {
        if(dpp_validoclass[i] == 0)
        {
            dpp_validoclass[i] = 1;
            strmid(dpp_oclassname[i], name, 0, dpp_maxsymbolchar, dpp_maxsymbolchar);
            dpp_usedclassid = i;
            return 1;
        }
    }
    return 1;
}


stock dpp_createobject(const name[], const classname[])
{
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

    dpp_subexecute2(dpp_oclassblock[classid]);
    dpp_currentobject = DPP_INVALID_OBJECT_ID;
    return 1;
}