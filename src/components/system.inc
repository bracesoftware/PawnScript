/*
*
* D++ Scripting Language
*     Made for a SA:MP server
*
* Component impl: system
*
* 
* - by: DEntisT, (c) 2022
*
*/


forward dpp_processsystem(funcgroup[][],args[][],args_const[][]);
public dpp_processsystem(funcgroup[][],args[][],args_const[][])
{
    if(!strcmp(funcgroup[0], "system"))
    {
        if(dpp_config[system_comp] == 0)
        {
            dpp_error("Component \"system\" is not imported.",);
            return 1;
        }
        // If the function used it "print"
        if(!strcmp(funcgroup[1], "rem"))
        {
            new mul, str[dpp_argcharsize];
            strmid(str, args[0], 0, dpp_argcharsize);
            for(new i; i < strlen(args[0]); i++)
            {
                if(args[0][i] == '\"') mul++, strdel(args[0], i, i+1);
            }
            if(mul == 0)
            {
                dpp_error("You need to use '\"' to start a string.",);
                return 1;
            }
            if(mul != 2)
            {
                dpp_error("Argument error; [%i] \"%s\"", mul, args[0]);
                return 1;
            }

            // do nothing, this is a comment
            return 1;
        }
        if(!strcmp(funcgroup[1], "arginit"))
        {
            for(new i; i < dpp_maxfuncs; i++)
            {
                if(!strcmp(dpp_funcname[i], args_const[0]))
                {
                    if(dpp_hookform[i] == 0)
                    {
                        for(new argid; argid < dpp_maxformargs; argid++)
                        {
                            strmid(dpp_args[i][argid][dpp_argvalue],
                                args[argid+1],
                                0,
                                dpp_argcharsize,
                                dpp_argcharsize);
                        }
        
                        if(dpp_option_hooking == 1)
                        {
                            for(new hookfuncid; hookfuncid < dpp_maxfuncs; hookfuncid++)
                            {
                                if(!strcmp(dpp_funcname[hookfuncid], args_const[0]))
                                {
                                    if(dpp_hookform[hookfuncid] == 1)
                                    {
                                        for(new argid; argid < dpp_maxformargs; argid++)
                                        {
                                            /*strmid(dpp_args[hookfuncid][argid][dpp_argname],
                                                dpp_args[i][argid][dpp_argname],
                                                0,
                                                dpp_argcharsize,
                                                dpp_argcharsize);*/
                                            strmid(dpp_args[hookfuncid][argid][dpp_argvalue],
                                                args[argid+1],
                                                0,
                                                dpp_argcharsize,
                                                dpp_argcharsize);
                                        }
                                    }
                                }
                            }
                        }
                        return 1;
                    }
                }
            }
            dpp_error("Form \"%s\" is not registered.",args_const[0]);
        }
        else
        {
            dpp_error("Unknown form in the component \"system\".",);
            return 0;
        }
    }
    return 0;
}