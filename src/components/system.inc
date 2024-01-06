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


forward dpp_processsystem(funcgroup[][],args[][],args_const[][]);
public dpp_processsystem(funcgroup[][],args[][],args_const[][])
{
    if(!strcmp(funcgroup[0], "system"))
    {
        if(dpp_config[system_comp] == 0)
        {
            dpp_error("Component \"system\" is not imported.",);
            dpp_internal<return>(0);
        }
        //ver
        if(!strcmp(funcgroup[1], "ver"))
        {
            printf("\tPawnScript   %i.%i.%i-R%i\tBrace Inc.", DPP_VERSION_MAJOR,DPP_VERSION_MINOR,DPP_VERSION_PATCH,DPP_VERSION_RELEASE);
            printf("\tPawn         %d.%02d.%02d\tITB CompuPhase", __Pawn >>> 8, __Pawn & 0xFF, __PawnBuild/*__pawn_build*/); // from YSI
            dpp_internal<return>(1);
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
                dpp_internal<return>(0);
            }
            if(mul != 2)
            {
                dpp_error("Argument error; [%i] \"%s\"", mul, args[0]);
                dpp_internal<return>(0);
            }

            // do nothing, this is a comment

            if(!strcmp(funcgroup[2], "log")) // we can log it tho.
            {
                dpp_savelog(DPP_LOG_FILE, args[0]);
            }
            dpp_internal<return>(1);
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
                        dpp_internal<return>(1);
                    }
                }
            }
            dpp_error("Form \"%s\" is not registered.",args_const[0]);
            dpp_internal<return>(0);
        }
        // current dir
        if(!strcmp(funcgroup[1], "cd"))
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

            strmid(dpp_curpath, args[0], 0, dpp_maxpathsize, dpp_maxpathsize);
            dpp_internal<return>(1);
        }
        else
        {
            dpp_error("Unknown form in the component \"system\".",);
            dpp_internal<return>(0);
        }
    }
    return 0;
}