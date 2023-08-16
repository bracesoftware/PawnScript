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


public OnRconCommand(cmd[])
{
    if(dpp_inputtype == DPP_INPUT_TYPE_NONE)
    {
        return 1;
    }
    if(dpp_inputtype == DPP_INPUT_TYPE_LINE)
    {
        strmid(dpp_vardata[dpp_inputdest][stringvalue], cmd, 0, 256, 256);
        dpp_inputtype = DPP_INPUT_TYPE_NONE;
        return 1;
    }
    if(dpp_inputtype == DPP_INPUT_TYPE_NONE)
    {
        dpp_vardata[dpp_inputdest][charvalue] = cmd[0];
        dpp_inputtype = DPP_INPUT_TYPE_NONE;
        return 1;
    }

    return 1;
}

forward dpp_processconsole(funcgroup[][],args[][],args_const[][]);
public dpp_processconsole(funcgroup[][],args[][],args_const[][])
{
    if(!strcmp(funcgroup[0], "console"))
    {
        if(dpp_config[console_comp] == 0)
        {
            dpp_error("Component \"console\" is not imported.",);
            dpp_internal<return>(0);
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
                dpp_internal<return>(0);
            }
            if(mul != 2)
            {
                dpp_error("Argument error; [%i] \"%s\"", mul, args[0]);
                dpp_internal<return>(0);
            }

            //dpp_debug("Line \"%s\" successfully executed.", line);
            print(args[0]);

            if(!strcmp(funcgroup[2], "log"))
            {
                dpp_savelog(DPP_LOG_FILE, args[0]);
            }
            dpp_internal<return>(1);
        }

        if(!strcmp(funcgroup[1], "inputln"))
        {
            if(isnull(args_const[0]))
            {
                dpp_error("Invalid destination variable.",);
                dpp_internal<return>(0);
            }

            dpp_codetrim(args_const[0]);
            for(new i; i < dpp_maxvar; i++)
            {
                if(!strcmp(args_const[0], dpp_vardata[i][var_name]))
                {
                    if(dpp_vardata[i][var_valid] == 1)
                    {
                        dpp_inputdest = i;
                        break;
                    }
                }
            }

            dpp_inputtype = DPP_INPUT_TYPE_LINE;
            dpp_internal<return>(1);
        }

        if(!strcmp(funcgroup[1], "cin"))
        {
            if(isnull(args_const[0]))
            {
                dpp_error("Invalid destination variable.",);
                dpp_internal<return>(0);
            }

            dpp_codetrim(args_const[0]);
            for(new i; i < dpp_maxvar; i++)
            {
                if(!strcmp(args_const[0], dpp_vardata[i][var_name]))
                {
                    if(dpp_vardata[i][var_valid] == 1)
                    {
                        dpp_inputdest = i;
                        break;
                    }
                }
            }

            dpp_inputtype = DPP_INPUT_TYPE_CHAR;
            dpp_internal<return>(1);
        }

        if(!strcmp(funcgroup[1], "cout"))
        {
            new mul2;
            for(new i; i < strlen(args[0]); i++)
            {
                if(args[0][i] == '\'') mul2++, strdel(args[1], i, i+1);
            }
            if(mul2 == 0)
            {
                dpp_error("You need to use \"'\" to start a char.",);
                //return 0;
                dpp_internal<return>(0);
            }
            if(mul2 != 2)
            {
                dpp_error("Argument error; [%i] \"%s\"", mul2, args[0]);
                //return 0;
                dpp_internal<return>(0);
            }

            print(args[0]);

            if(!strcmp(funcgroup[2], "log"))
            {
                dpp_savelog(DPP_LOG_FILE, args[0]);
            }
            dpp_internal<return>(1);
        }

        if(!strcmp(funcgroup[1], "rawout")) // Output of raw text: console.rawout(This will be printed!);
        {
            print(args[0]);

            if(!strcmp(funcgroup[2], "log"))
            {
                dpp_savelog(DPP_LOG_FILE, args[0]);
            }
            dpp_internal<return>(1);
        }
        else
        {
            dpp_error("Unknown form in the component \"console\".",);
            dpp_internal<return>(0); // Here we return 0 in PAWNSCRIPT
        }
    }
    return 0; // Here we want to return 0 in PAWN.
}