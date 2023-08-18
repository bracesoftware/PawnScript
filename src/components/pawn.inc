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


forward dpp_processpawn(funcgroup[][],args[][],args_const[][]);
public dpp_processpawn(funcgroup[][],args[][],args_const[][])
{
    if(!strcmp(funcgroup[0], "pawn"))
    {
        if(dpp_config[pawn_comp] == 0)
        {
            dpp_error("Component \"pawn\" is not imported.",);
            dpp_internal<return>(0);
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
                dpp_internal<return>(0);
            }
            if(mul != 2)
            {
                dpp_error("Argument error; [%i] \"%s\"", mul, args[0]);
                dpp_internal<return>(0);
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
            dpp_internal<return>(1);
        }
        else
        {
            dpp_error("Unknown form in the component \"pawn\".",);
            dpp_internal<return>(0);
        }
    }
    return 0;
}