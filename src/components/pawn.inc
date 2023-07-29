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


forward dpp_processpawn(funcgroup[][],args[][],args_const[][]);
public dpp_processpawn(funcgroup[][],args[][],args_const[][])
{
    if(!strcmp(funcgroup[0], "pawn"))
    {
        if(dpp_config[pawn_comp] == 0)
        {
            dpp_error("Component \"pawn\" is not imported.",);
            return 1;
        }
        // If the function used it "print"
        if(!strcmp(funcgroup[1], "callfunction"))
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
            if(isnull(funcgroup[2]))
            {
                CallRemoteFunction(args[0], "");
            }

            if(!strcmp(funcgroup[2], "local"))
            {
                CallLocalFunction(args[0], "");
            }
            if(!strcmp(funcgroup[2], "remote"))
            {
                CallRemoteFunction(args[0], "");
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