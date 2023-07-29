/*
*
* D++ Scripting Language
*     Made for a SA:MP server
*
* Support for constants
*
* 
* - by: DEntisT, (c) 2022
*
*/

stock dpp_argarraycheck(arg[])
{
    new newvalue[dpp_argcharsize];
    for(new i; i < dpp_maxconst; i++)
    {
        if(!strcmp(dpp_constdata[i][const_name], arg))
        {
            if(dpp_constdata[i][const_valid] == 1)
            {
                if(dpp_constdata[i][const_type] == dpp_const_type_int)
                {
                    format(newvalue, dpp_argcharsize, "%i", 
                        dpp_constdata[i][integervalue]);
                }
                if(dpp_constdata[i][const_type] == dpp_const_type_bool)
                {
                    if(dpp_constdata[i][boolvalue] == 1)
                    {
                        strmid(arg, "true", 0, dpp_argcharsize, dpp_argcharsize);
                    }
                    if(dpp_constdata[i][boolvalue] == 0)
                    {
                        strmid(arg, "false", 0, dpp_argcharsize, dpp_argcharsize);
                    }
                }
                if(dpp_constdata[i][const_type] == dpp_const_type_str)
                {
                    format(newvalue, dpp_argcharsize, "\"%s\"", 
                        dpp_constdata[i][stringvalue]);
                }
                if(dpp_constdata[i][const_type] == dpp_const_type_double)
                {
                    format(newvalue, dpp_argcharsize, "%f", 
                        dpp_constdata[i][floatvalue]);
                }
                if(dpp_constdata[i][const_type] == dpp_const_type_char)
                {
                    format(newvalue, dpp_argcharsize, "'%c'", 
                        dpp_constdata[i][charvalue]);
                }

                dpp_debug("argarraycheck debug\n\tarr : '%s'\n\targ : '%s'\n\tnewvalue : '%s'", dpp_constdata[i][const_name], arg, newvalue);
                if(dpp_constdata[i][const_type] != dpp_const_type_bool)
                {
                    strmid(arg, newvalue, 0, dpp_argcharsize, dpp_argcharsize);
                }
                dpp_debug("argarraycheck debug 2\n\tarr : '%s'\n\targ : '%s'\n\tnewvalue : '%s'", dpp_constdata[i][const_name], arg, newvalue);
                return 1;
            }
        }
    }
    return 1;
}

///////////////////////////CREATE/////////////////////////////

stock dpp_createintconst(name[], value)
{
    for(new i; i < dpp_maxconst; i++)
    {
        if(dpp_constdata[i][const_valid] == 0)
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
                format(newvalue,sizeof(newvalue),"DPPCc@%s_%s",dpp_classname[dpp_workingclassid],name);
                strmid(name, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            }

            dpp_debug("Constant \"%s\" assigned a value : %i",name,value);
            strmid(dpp_constdata[i][const_name], name, 0, 64);
            dpp_constdata[i][integervalue] = value;
            dpp_constdata[i][const_type] = dpp_const_type_int;
            dpp_constdata[i][const_valid] = 1;
            return 1;
        }
    }
    return 1;
}

stock dpp_createboolconst(name[], value)
{
    for(new i; i < dpp_maxconst; i++)
    {
        if(dpp_constdata[i][const_valid] == 0)
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
                format(newvalue,sizeof(newvalue),"DPPCc@%s_%s",dpp_classname[dpp_workingclassid],name);
                strmid(name, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            }

            dpp_debug("Constant \"%s\" assigned a value : %s",name,value ? "true" : "false");
            strmid(dpp_constdata[i][const_name], name, 0, 64);
            dpp_constdata[i][boolvalue] = value;
            dpp_constdata[i][const_type] = dpp_const_type_bool;
            dpp_constdata[i][const_valid] = 1;
            return 1;
        }
    }
    return 1;
}

stock dpp_createstrconst(name[], const value[])
{
    for(new i; i < dpp_maxconst; i++)
    {
        if(dpp_constdata[i][const_valid] == 0)
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
                format(newvalue,sizeof(newvalue),"DPPCc@%s_%s",dpp_classname[dpp_workingclassid],name);
                strmid(name, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            }

            dpp_debug("Constant \"%s\" assigned a value : \"%s\"",name,value);
            strmid(dpp_constdata[i][const_name], name, 0, 64);
            strmid(dpp_constdata[i][stringvalue], value, 0, 256);
            dpp_constdata[i][const_type] = dpp_const_type_str;
            dpp_constdata[i][const_valid] = 1;
            return 1;
        }
    }
    return 1;
}

stock dpp_createdoubleconst(name[], Float:value)
{
    for(new i; i < dpp_maxconst; i++)
    {
        if(dpp_constdata[i][const_valid] == 0)
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
                format(newvalue,sizeof(newvalue),"DPPCc@%s_%s",dpp_classname[dpp_workingclassid],name);
                strmid(name, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            }

            dpp_debug("Constant \"%s\" assigned a value : %f",name,value);
            strmid(dpp_constdata[i][const_name], name, 0, 64);
            dpp_constdata[i][floatvalue] = value;
            dpp_constdata[i][const_type] = dpp_const_type_double;
            dpp_constdata[i][const_valid] = 1;
            return 1;
        }
    }
    return 1;
}


stock dpp_createcharconst(name[], value)
{
    for(new i; i < dpp_maxconst; i++)
    {
        if(dpp_constdata[i][const_valid] == 0)
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
                format(newvalue,sizeof(newvalue),"DPPCc@%s_%s",dpp_classname[dpp_workingclassid],name);
                strmid(name, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            }

            dpp_debug("Constant \"%s\" assigned a value : %c",name,value);
            strmid(dpp_constdata[i][const_name], name, 0, 64);
            dpp_constdata[i][charvalue] = value;
            dpp_constdata[i][const_type] = dpp_const_type_char;
            dpp_constdata[i][const_valid] = 1;
            return 1;
        }
    }
    return 1;
}

///////////////////////////DELETE///////////////////////


stock dpp_deleteintconst(const name[])
{
    for(new i; i < dpp_maxconst; i++)
    {
        if(!strcmp(dpp_constdata[i][const_name], name))
        {
            if(dpp_constdata[i][const_valid] == 1)
            {
                if(dpp_constdata[i][const_type] != dpp_const_type_int)
                {
                    //dpp_error("Constant \"%s\" is not an integer.", name);
                    return 1;
                }

                strmid(dpp_constdata[i][const_name], "unknown", 0, 64);
                dpp_constdata[i][const_valid] = 0;
                dpp_constdata[i][integervalue] = 0;
                return 1;
            }
        }
        //dpp_error("Constant \"%s\" not found.", name);
    }
    return 1;
}

stock dpp_deleteboolconst(const name[])
{
    for(new i; i < dpp_maxconst; i++)
    {
        if(!strcmp(dpp_constdata[i][const_name], name))
        {
            if(dpp_constdata[i][const_valid] == 1)
            {
                if(dpp_constdata[i][const_type] != dpp_const_type_bool)
                {
                    //dpp_error("Constant \"%s\" is not a boolean.", name);
                    return 1;
                }

                strmid(dpp_constdata[i][const_name], "unknown", 0, 64);
                dpp_constdata[i][const_valid] = 0;
                dpp_constdata[i][boolvalue] = 0;
                return 1;
            }
        }
        //dpp_error("Constant \"%s\" not found.", name);
    }
    return 1;
}

stock dpp_deletestrconst(const name[])
{
    for(new i; i < dpp_maxconst; i++)
    {
        if(!strcmp(dpp_constdata[i][const_name], name))
        {
            if(dpp_constdata[i][const_valid] == 1)
            {
                if(dpp_constdata[i][const_type] != dpp_const_type_str)
                {
                    //dpp_error("Constant \"%s\" is not a string.", name);
                    return 1;
                }

                strmid(dpp_constdata[i][const_name], "unknown", 0, 64);
                dpp_constdata[i][const_valid] = 0;
                strmid(dpp_constdata[i][stringvalue], "empty", 0, 256);
                return 1;
            }
        }
        //dpp_error("Constant \"%s\" not found.", name);
    }
    return 1;
}

stock dpp_deletedoubleconst(const name[])
{
    for(new i; i < dpp_maxconst; i++)
    {
        if(!strcmp(dpp_constdata[i][const_name], name))
        {
            if(dpp_constdata[i][const_valid] == 1)
            {
                if(dpp_constdata[i][const_type] != dpp_const_type_double)
                {
                    //dpp_error("Constant \"%s\" is not a boolean.", name);
                    return 1;
                }

                strmid(dpp_constdata[i][const_name], "unknown", 0, 64);
                dpp_constdata[i][const_valid] = 0;
                dpp_constdata[i][floatvalue] = 0.0;
                return 1;
            }
        }
        //dpp_error("Constant \"%s\" not found.", name);
    }
    return 1;
}

stock dpp_deletecharconst(const name[])
{
    for(new i; i < dpp_maxconst; i++)
    {
        if(!strcmp(dpp_constdata[i][const_name], name))
        {
            if(dpp_constdata[i][const_valid] == 1)
            {
                if(dpp_constdata[i][const_type] != dpp_const_type_char)
                {
                    //dpp_error("Constant \"%s\" is not a boolean.", name);
                    return 1;
                }

                strmid(dpp_constdata[i][const_name], "unknown", 0, 64);
                dpp_constdata[i][const_valid] = 0;
                dpp_constdata[i][charvalue] = '0';
                return 1;
            }
        }
        //dpp_error("Constant \"%s\" not found.", name);
    }
    return 1;
}