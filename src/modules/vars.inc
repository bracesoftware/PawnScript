/*
*
* D++ Scripting Language
*     Made for a SA:MP server
*
* Support for vars
*
* 
* - by: DEntisT, (c) 2022
*
*/


stock dpp_argvarcheck(arg[])
{
    new newvalue[dpp_argcharsize];
    for(new i; i < dpp_maxvar; i++)
    {
        if(!strcmp(dpp_vardata[i][var_name], arg))
        {
            if(dpp_vardata[i][var_valid] == 1)
            {
                if(dpp_vardata[i][var_type] == dpp_var_type_int)
                {
                    format(newvalue, dpp_argcharsize, "%i", 
                        dpp_vardata[i][integervalue]);
                }
                if(dpp_vardata[i][var_type] == dpp_var_type_bool)
                {
                    if(dpp_vardata[i][boolvalue] == 1)
                    {
                        strmid(arg, "true", 0, dpp_argcharsize, dpp_argcharsize);
                    }
                    if(dpp_vardata[i][boolvalue] == 0)
                    {
                        strmid(arg, "false", 0, dpp_argcharsize, dpp_argcharsize);
                    }
                }
                if(dpp_vardata[i][var_type] == dpp_var_type_str)
                {
                    format(newvalue, dpp_argcharsize, "\"%s\"", 
                        dpp_vardata[i][stringvalue]);
                }
                if(dpp_vardata[i][var_type] == dpp_var_type_double)
                {
                    format(newvalue, dpp_argcharsize, "%f", 
                        dpp_vardata[i][floatvalue]);
                }
                if(dpp_vardata[i][var_type] == dpp_var_type_char)
                {
                    format(newvalue, dpp_argcharsize, "'%c'", 
                        dpp_vardata[i][charvalue]);
                }

                dpp_debug("argarraycheck debug\n\tarr : '%s'\n\targ : '%s'\n\tnewvalue : '%s'", dpp_vardata[i][var_name], arg, newvalue);
                if(dpp_vardata[i][var_type] != dpp_var_type_bool)
                {
                    strmid(arg, newvalue, 0, dpp_argcharsize, dpp_argcharsize);
                }
                dpp_debug("argarraycheck debug 2\n\tarr : '%s'\n\targ : '%s'\n\tnewvalue : '%s'", dpp_vardata[i][var_name], arg, newvalue);
                return 1;
            }
        }
    }
    return 1;
}

////////////////////utils////////////////

stock dpp_findvar(const name[], dest)
{
    for(new i; i < dpp_maxvar; i++)
    {
        if(!strcmp(name, dpp_vardata[i][var_name]))
        {
            if(dpp_vardata[i][var_valid] == 1)
            {
                dest = i;
                return 1;
            }
        }
    }
    return 0;
}

///////////////////////////CREATE/////////////////////////////

stock dpp_createintvar(name[], value, obj = -1, staticvar = 0, baseform = -1, unsigned = 0)
{
    for(new i; i < dpp_maxvar; i++)
    {
        if(dpp_vardata[i][var_valid] == 0)
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
                dpp_error("Invalid symbol name.",);
                return 1;
            }

            if(dpp_workingclassid != dpp_invalidclass)
            {
                new newvalue[dpp_argcharsize];
                format(newvalue,sizeof(newvalue),"DPPCv@%s_%s",dpp_classname[dpp_workingclassid],name);
                strmid(name, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            }

            dpp_debug("variable \"%s\" assigned a value : %i",name,value);
            strmid(dpp_vardata[i][var_name], name, 0, 64);
            dpp_vardata[i][integervalue] = value;
            dpp_vardata[i][var_type] = dpp_var_type_int;
            dpp_vardata[i][var_valid] = 1;
            dpp_vardata[i][var_object] = obj;

            dpp_vardata[i][var_static] = staticvar;
            dpp_vardata[i][var_baseformid] = baseform;
            if(staticvar == 1)
            {
                //dpp_warning("Created a static var '%s' [%i]",dpp_vardata[i][var_name],i);
            }

            dpp_vardata[i][var_unsigned] = unsigned;
            
            if(dpp_objectid != -1)
            {
                dpp_vardata[i][var_object] = dpp_objectid;
                dpp_objectid = -1;
                //dpp_warning("Assigned object '%i' to a variable '%s'[%i]",dpp_vardata[i][var_object], dpp_vardata[i][var_name],i);
            }
            return 1;
        }
    }
    return 1;
}

stock dpp_createboolvar(name[], value, obj = -1, staticvar = 0, baseform = -1)
{
    for(new i; i < dpp_maxvar; i++)
    {
        if(dpp_vardata[i][var_valid] == 0)
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
                dpp_error("Invalid symbol name.",);
                return 1;
            }

            if(dpp_workingclassid != dpp_invalidclass)
            {
                new newvalue[dpp_argcharsize];
                format(newvalue,sizeof(newvalue),"DPPCv@%s_%s",dpp_classname[dpp_workingclassid],name);
                strmid(name, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            }

            dpp_debug("variable \"%s\" assigned a value : %s",name,value ? "true" : "false");
            strmid(dpp_vardata[i][var_name], name, 0, 64);
            dpp_vardata[i][boolvalue] = value;
            dpp_vardata[i][var_type] = dpp_var_type_bool;
            dpp_vardata[i][var_valid] = 1;
            dpp_vardata[i][var_object] = obj;

            dpp_vardata[i][var_static] = staticvar;
            dpp_vardata[i][var_baseformid] = baseform;
            if(staticvar == 1)
            {
                //dpp_warning("Created a static var '%s' [%i]",dpp_vardata[i][var_name],i);
            }

            
            if(dpp_objectid != -1)
            {
                dpp_vardata[i][var_object] = dpp_objectid;
                dpp_objectid = -1;
            }
            return 1;
        }
    }
    return 1;
}

stock dpp_createstrvar(name[], const value[], obj = -1, staticvar = 0, baseform = -1)
{
    for(new i; i < dpp_maxvar; i++)
    {
        if(dpp_vardata[i][var_valid] == 0)
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
                dpp_error("Invalid symbol name.",);
                return 1;
            }

            if(dpp_workingclassid != dpp_invalidclass)
            {
                new newvalue[dpp_argcharsize];
                format(newvalue,sizeof(newvalue),"DPPCv@%s_%s",dpp_classname[dpp_workingclassid],name);
                strmid(name, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            }

            dpp_debug("variable \"%s\" assigned a value : \"%s\"",name,value);
            strmid(dpp_vardata[i][var_name], name, 0, 64);
            strmid(dpp_vardata[i][stringvalue], value, 0, 256);
            dpp_vardata[i][var_type] = dpp_var_type_str;
            dpp_vardata[i][var_valid] = 1;
            dpp_vardata[i][var_object] = obj;

            dpp_vardata[i][var_static] = staticvar;
            dpp_vardata[i][var_baseformid] = baseform;
            if(staticvar == 1)
            {
                //dpp_warning("Created a static var '%s' [%i]",dpp_vardata[i][var_name],i);
            }

            
            if(dpp_objectid != -1)
            {
                dpp_vardata[i][var_object] = dpp_objectid;
                dpp_objectid = -1;
            }
            return 1;
        }
    }
    return 1;
}

stock dpp_createdoublevar(name[], Float:value, obj = -1, staticvar = 0, baseform = -1)
{
    for(new i; i < dpp_maxvar; i++)
    {
        if(dpp_vardata[i][var_valid] == 0)
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
                dpp_error("Invalid symbol name.",);
                return 1;
            }

            if(dpp_workingclassid != dpp_invalidclass)
            {
                new newvalue[dpp_argcharsize];
                format(newvalue,sizeof(newvalue),"DPPCv@%s_%s",dpp_classname[dpp_workingclassid],name);
                strmid(name, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            }

            dpp_debug("variable \"%s\" assigned a value : %f",name,value);
            strmid(dpp_vardata[i][var_name], name, 0, 64);
            dpp_vardata[i][floatvalue] = value;
            dpp_vardata[i][var_type] = dpp_var_type_double;
            dpp_vardata[i][var_valid] = 1;
            dpp_vardata[i][var_object] = obj;

            dpp_vardata[i][var_static] = staticvar;
            dpp_vardata[i][var_baseformid] = baseform;
            if(staticvar == 1)
            {
                //dpp_warning("Created a static var '%s' [%i]",dpp_vardata[i][var_name],i);
            }

            
            if(dpp_objectid != -1)
            {
                dpp_vardata[i][var_object] = dpp_objectid;
                dpp_objectid = -1;
            }
            return 1;
        }
    }
    return 1;
}

stock dpp_createcharvar(name[], value, obj = -1, staticvar = 0, baseform = -1)
{
    for(new i; i < dpp_maxvar; i++)
    {
        if(dpp_vardata[i][var_valid] == 0)
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
                dpp_error("Invalid symbol name.",);
                return 1;
            }

            if(dpp_workingclassid != dpp_invalidclass)
            {
                new newvalue[dpp_argcharsize];
                format(newvalue,sizeof(newvalue),"DPPCv@%s_%s",dpp_classname[dpp_workingclassid],name);
                strmid(name, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            }

            dpp_debug("variable \"%s\" assigned a value : %c",name,value);
            strmid(dpp_vardata[i][var_name], name, 0, 64);
            dpp_vardata[i][charvalue] = value;
            dpp_vardata[i][var_type] = dpp_var_type_char;
            dpp_vardata[i][var_valid] = 1;
            dpp_vardata[i][var_object] = obj;

            dpp_vardata[i][var_static] = staticvar;
            dpp_vardata[i][var_baseformid] = baseform;
            if(staticvar == 1)
            {
                //dpp_warning("Created a static var '%s' [%i]",dpp_vardata[i][var_name],i);
            }

            if(dpp_objectid != -1)
            {
                dpp_vardata[i][var_object] = dpp_objectid;
                dpp_objectid = -1;
            }
            return 1;
        }
    }
    return 1;
}


///////////////////////////SET///////////////////////////////

stock dpp_setintvar(const name[], value)
{
    for(new i; i < dpp_maxvar; i++)
    {
        if(!strcmp(dpp_vardata[i][var_name], name) && dpp_vardata[i][var_valid] == 1)
        {
            dpp_debug("\"%s\" value changed to \"%i\"", name, value);
            if(dpp_vardata[i][var_unsigned])
            {
                dpp_vardata[i][integervalue] = value < 0 ? value*(-1) : value;
                return 1;    
            }
            dpp_vardata[i][integervalue] = value;
            return 1;
        }
    }
    dpp_error("INT : Unable to find a variable: '%s'",name);
    return 1;
}

stock dpp_setboolvar(const name[], value)
{
    for(new i; i < dpp_maxvar; i++)
    {
        if(!strcmp(dpp_vardata[i][var_name], name) && dpp_vardata[i][var_valid] == 1)
        {
            dpp_debug("\"%s\" value changed to \"%s\"", name, value ? "true" : "false");
            dpp_vardata[i][boolvalue] = value;
            return 1;
        }
    }
    dpp_error("BOOL : Unable to find a variable: '%s'",name);
    return 1;
}

stock dpp_setstrvar(const name[], const value[])
{
    for(new i; i < dpp_maxvar; i++)
    {
        if(!strcmp(dpp_vardata[i][var_name], name) && dpp_vardata[i][var_valid] == 1)
        {
            dpp_debug("\"%s\" value changed to \"%s\"", name, value);
            strmid(dpp_vardata[i][stringvalue], value, 0, 256);
            return 1;
        }
    }
    dpp_error("STR : Unable to find a variable: '%s'",name);
    return 1;
}

stock dpp_setdoublevar(const name[], Float:value)
{
    for(new i; i < dpp_maxvar; i++)
    {
        if(!strcmp(dpp_vardata[i][var_name], name) && dpp_vardata[i][var_valid] == 1)
        {
            dpp_debug("\"%s\" value changed to \"%f\"", name, value);
            dpp_vardata[i][floatvalue] = value;
            return 1;
        }
    }
    dpp_error("DOUBLE : Unable to find a variable: '%s'",name);
    return 1;
}

stock dpp_setcharvar(const name[], value)
{
    for(new i; i < dpp_maxvar; i++)
    {
        if(!strcmp(dpp_vardata[i][var_name], name) && dpp_vardata[i][var_valid] == 1)
        {
            dpp_debug("\"%s\" value changed to \"%c\"", name, value);
            dpp_vardata[i][charvalue] = value;
            return 1;
        }
    }
    dpp_error("CHAR : Unable to find a variable: '%s'",name);
    return 1;
}

///////////////////////////DELETE///////////////////////


stock dpp_deleteintvar(const name[])
{
    for(new i; i < dpp_maxvar; i++)
    {
        if(!strcmp(dpp_vardata[i][var_name], name))
        {
            if(dpp_vardata[i][var_valid] == 1)
            {
                if(dpp_vardata[i][var_type] != dpp_var_type_int)
                {
                    //dpp_error("variable \"%s\" is not an integer.", name);
                    return 1;
                }

                strmid(dpp_vardata[i][var_name], "unknown", 0, 64);
                dpp_vardata[i][var_valid] = 0;
                dpp_vardata[i][integervalue] = 0;
                return 1;
            }
        }
        //dpp_error("variable \"%s\" not found.", name);
    }
    return 1;
}

stock dpp_deleteboolvar(const name[])
{
    for(new i; i < dpp_maxvar; i++)
    {
        if(!strcmp(dpp_vardata[i][var_name], name))
        {
            if(dpp_vardata[i][var_valid] == 1)
            {
                if(dpp_vardata[i][var_type] != dpp_var_type_bool)
                {
                    //dpp_error("variable \"%s\" is not a boolean.", name);
                    return 1;
                }

                strmid(dpp_vardata[i][var_name], "unknown", 0, 64);
                dpp_vardata[i][var_valid] = 0;
                dpp_vardata[i][boolvalue] = 0;
                return 1;
            }
        }
        //dpp_error("variable \"%s\" not found.", name);
    }
    return 1;
}

stock dpp_deletestrvar(const name[])
{
    for(new i; i < dpp_maxvar; i++)
    {
        if(!strcmp(dpp_vardata[i][var_name], name))
        {
            if(dpp_vardata[i][var_valid] == 1)
            {
                if(dpp_vardata[i][var_type] != dpp_var_type_str)
                {
                    //dpp_error("variable \"%s\" is not a string.", name);
                    return 1;
                }

                strmid(dpp_vardata[i][var_name], "unknown", 0, 64);
                dpp_vardata[i][var_valid] = 0;
                strmid(dpp_vardata[i][stringvalue], "empty", 0, 256);
                return 1;
            }
        }
        //dpp_error("variable \"%s\" not found.", name);
    }
    return 1;
}

stock dpp_deletedoublevar(const name[])
{
    for(new i; i < dpp_maxvar; i++)
    {
        if(!strcmp(dpp_vardata[i][var_name], name))
        {
            if(dpp_vardata[i][var_valid] == 1)
            {
                if(dpp_vardata[i][var_type] != dpp_var_type_double)
                {
                    //dpp_error("variable \"%s\" is not a string.", name);
                    return 1;
                }

                strmid(dpp_vardata[i][var_name], "unknown", 0, 64);
                dpp_vardata[i][var_valid] = 0;
                dpp_vardata[i][floatvalue] = 0.0;
                return 1;
            }
        }
        //dpp_error("variable \"%s\" not found.", name);
    }
    return 1;
}


stock dpp_deletecharvar(const name[])
{
    for(new i; i < dpp_maxvar; i++)
    {
        if(!strcmp(dpp_vardata[i][var_name], name))
        {
            if(dpp_vardata[i][var_valid] == 1)
            {
                if(dpp_vardata[i][var_type] != dpp_var_type_char)
                {
                    //dpp_error("variable \"%s\" is not a string.", name);
                    return 1;
                }

                strmid(dpp_vardata[i][var_name], "unknown", 0, 64);
                dpp_vardata[i][var_valid] = 0;
                dpp_vardata[i][charvalue] = '0';
                return 1;
            }
        }
        //dpp_error("variable \"%s\" not found.", name);
    }
    return 1;
}

///////////////////

stock dpp_deletestaticvars()
{
    for(new i; i < dpp_maxvar; i++)
    {
        if(dpp_vardata[i][var_valid] == 1)
        {
            if(dpp_vardata[i][var_static] == 1)
            {
                dpp_vardata[i][var_valid] = 0;
                //dpp_warning("Deleted a static var '%s' [%i]",dpp_vardata[i][var_name],i);
            }
        }
    }
    return 1;
}