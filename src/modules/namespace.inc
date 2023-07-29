/*
*
* D++ Scripting Language
*     Made for a SA:MP server
*
* Support for classes
*
* 
* - by: DEntisT, (c) 2022
*
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

    for(new i; i < dpp_maxobj; i++)
    {
        if(!strcmp(dpp_objname[i],newvalue) && dpp_validobj[i] == 1)
        {
            strmid(arg, newvalue, 0, dpp_argcharsize,dpp_argcharsize);//classelementvalid[dpp_classelement_var] = 1;
            break;
        }
    }

    //dpp_debug("Class backtrace 4:\n\tclassvalid : '%i'\n\tclasselementvalid[0] : '%i'\n\tclasselementvalid[1] : '%i'\n\tclasselementvalid[2] : '%i'",classvalid,classelementvalid[0],classelementvalid[1],classelementvalid[2]);


    dpp_debug("Namespace backtrace 4:\n\tfuncgroup[0] : '%s'\n\tfuncgroup[1] : '%s'\n\targ : '%s'",funcgroup[0],funcgroup[1],arg);
    return 1;
}

stock dpp_createclass(const name[])
{
    for(new i; i < dpp_maxclass; i++)
    {
        if(dpp_validclass[i] == 0)
        {
            new name_error;

            for(new x; x < strlen(name); x++)
            {
                if(name[x] == '\"') name_error = 1;
                if(name[x] == ' ') name_error = 1;
                if(name[x] == '\t') name_error = 1;
            }
            if(dpp_isnumeric(name)) name_error = 1;
            if(name_error == 1)
            {
                dpp_error("Invalid namespace name.",);
                return 1;
            }

            dpp_validclass[i] = 1;
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
            dpp_lastclass = i;
            return 1;
        }
    }
    dpp_error("Namespace \"%s\" does not exist.",name);
    return 1;
}