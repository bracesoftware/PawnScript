/*
*
* D++ Scripting Language
*     Made for a SA:MP server
*
* Component impl: console
*
* 
* - by: DEntisT, (c) 2022
*
*/


forward dpp_processconsole(funcgroup[][],args[][]);
public dpp_processconsole(funcgroup[][],args[][])
{
    if(!strcmp(funcgroup[0], "console"))
    {
        if(dpp_config[console_comp] == 0)
        {
            dpp_error("Component \"console\" is not imported.",);
            return 1;
        }
        // If the function used it "print"
        if(!strcmp(funcgroup[1], "println"))
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

            //dpp_debug("Line \"%s\" successfully executed.", line);
            print(args[0]);

            if(!strcmp(funcgroup[2], "log"))
            {
                dpp_savelog(DPP_LOG_FILE, args[0]);
            }
            return 1;
        }

        if(!strcmp(funcgroup[1], "cout"))
        {
            new coutargerr = 0;

            for(new i; i < strlen(args[0]); i++)
            {
                if(args[0][i] == '\"') coutargerr = 1;
                if(args[0][i] == ' ') coutargerr = 1;
                if(args[0][i] == '\t') coutargerr = 1;
            }

            if(coutargerr == 1)
            {
                dpp_error("Invalid symbols in the argument 1.",);
            }
            //dpp_debug("Line \"%s\" successfully executed.", line);
            print(args[0]);

            if(!strcmp(funcgroup[2], "log"))
            {
                dpp_savelog(DPP_LOG_FILE, args[0]);
            }
            return 1;
        }
        else
        {
            dpp_error("Unknown form in the component \"console\".",);
            return 1;
        }
    }
    return 0;
}