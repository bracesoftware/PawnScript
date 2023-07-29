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


forward dpp_processfiles(funcgroup[][],args[][],args_const[][]);
public dpp_processfiles(funcgroup[][],args[][],args_const[][])
{
    if(!strcmp(funcgroup[0], "files"))
    {
        if(dpp_config[files_comp] == 0)
        {
            dpp_error("Component \"files\" is not imported.",);
            return 1;
        }
        if(!strcmp(funcgroup[1], "delete"))
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

            fremove(args[0]);
            return 1;
        }
        if(!strcmp(funcgroup[1], "open_for_append"))
        {
            if(dpp_fhandleused == 1)
            {
                dpp_error("Another file handle is opened already.",);
                return 1;
            }
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

            dpp_filehandle = fopen(args[0], io_append);
            dpp_fhandleused = 1;
            return 1;
        }
        if(!strcmp(funcgroup[1], "open_for_read"))
        {
            if(dpp_fhandleused == 1)
            {
                dpp_error("Another file handle is opened already.",);
                return 1;
            }
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

            dpp_filehandle = fopen(args[0], io_read);
            dpp_fhandleused = 1;
            return 1;
        }
        if(!strcmp(funcgroup[1], "open_for_write"))
        {
            if(dpp_fhandleused == 1)
            {
                dpp_error("Another file handle is opened already.",);
                return 1;
            }
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

            dpp_filehandle = fopen(args[0], io_write);
            dpp_fhandleused = 1;
            return 1;
        }
        if(!strcmp(funcgroup[1], "close"))
        {
            if(dpp_fhandleused == 0)
            {
                dpp_error("No file handle is opened.",);
                return 1;
            }
            fclose(dpp_filehandle);
            dpp_fhandleused = 0;
            return 1;
        }
        if(!strcmp(funcgroup[1], "write"))
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

            fwrite(dpp_filehandle, args[0]);
            return 1;
        }
        if(!strcmp(funcgroup[1], "read"))
        {
            new foundvar = -1;

            for(new i; i < dpp_maxvar; i++)
            {
                if(!strcmp(dpp_vardata[i][var_name], args_const[0]))
                {
                    if(dpp_vardata[i][var_type] == dpp_var_type_str)
                    {
                        if(dpp_vardata[i][var_valid] == 1)
                        {
                            foundvar = i;
                            break;
                        }
                    }
                }
            }
            if(foundvar == -1)
            {
                dpp_error("Cannot find a destination string variable : \"%s\"",args_const[0]);
                return 1;
            }

            fread(dpp_filehandle, dpp_vardata[foundvar][stringvalue]);
            return 1;
        }

        else
        {
            dpp_error("Unknown form in the component \"files\".",);
            return 0;
        }
    }
    return 0;
}