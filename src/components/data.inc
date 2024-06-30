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

forward dpp_processdata(funcgroup[][],args[][],args_const[][]);
public dpp_processdata(funcgroup[][],args[][],args_const[][])
{
    if(!strcmp(funcgroup[0], "data"))
    {
        if(dpp_config[data_comp] == 0)
        {
            dpp_error("Component \"data\" is not imported.",);
            dpp_internal<return>(0);
        }
        if(!strcmp(funcgroup[1], "sscanf"))
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

            //dpp_warning("sscanf debug 1",);

            for(new i = 1; i < dpp_maxargsc; i++)
            {
                dpp_argclasscheck(args_const[i]);
            }

            //dpp_warning("sscanf debug 2",);

            new args_sscanf[dpp_maxargsc][dpp_maxstrsize], dpp_varid[dpp_maxargsc];
            dpp_parseline(args[0], args_sscanf, '-');

            //dpp_warning("sscanf debug 3",);

            for(new i = 1; i < dpp_maxargsc; i++)
            {
                for(new j; j < dpp_maxvar; j++)
                {
                    if(!strcmp(args_const[i], dpp_vardata[j][var_name]))
                    {
                        if(dpp_vardata[j][var_valid] == 1)
                        {
                            dpp_varid[i] = j;
                            break;
                        }
                    }
                }
            }

            //dpp_warning("sscanf debug 4",);

            for(new i = 1; i < dpp_maxargsc; i++)
            {
                if(isnull(args_sscanf[i-1])) continue;
                dpp_vardata[dpp_varid[i]][integervalue] = strval(args_sscanf[i-1]);
                //dpp_error("var_name: '%s' | dpp_varid[%i]: '%i' | args_sscanf[%i]: '%s'",dpp_vardata[dpp_varid[i]][var_name],i,dpp_varid[i],i-2,args_sscanf[i-2]);
                strmid(dpp_vardata[dpp_varid[i]][stringvalue],args_sscanf[i-1],0,dpp_maxstrsize,dpp_maxstrsize);
            }

            //dpp_warning("sscanf debug 5",);
            dpp_internal<return>(1);
        }
        //dpp_data__strdist
        if(!strcmp(funcgroup[1], "strdist"))
        {
            new mul;
            for(new i; i < strlen(args[0]); i++)
            {
                if(args[0][i] == '\"') mul++, strdel(args[0], i, i+1);
            }
            if(mul == 0)
            {
                dpp_error("You need to use '\"' to start a string.",);
                dpp_internal<return>(65535);
            }
            if(mul != 2)
            {
                dpp_error("Argument error; [%i] \"%s\"", mul, args[0]);
                dpp_internal<return>(65535);
            }
            mul=0;
            for(new i; i < strlen(args[1]); i++)
            {
                if(args[1][i] == '\"') mul++, strdel(args[1], i, i+1);
            }
            if(mul == 0)
            {
                dpp_error("You need to use '\"' to start a string.",);
                dpp_internal<return>(65535);
            }
            if(mul != 2)
            {
                dpp_error("Argument error; [%i] \"%s\"", mul, args[1]);
                dpp_internal<return>(65535);
            }

            new dist = dpp_data__strdist(args[0], args[1]);

            dpp_internal<return>(dist);
        }
        //dpp_data__testfunc
        if(!strcmp(funcgroup[1], "testfunc"))
        {
            dpp_data__testfunc();
            dpp_internal<return>(1);
        }

        else
        {
            dpp_error("Unknown form in the component \"data\".",);
            dpp_internal<return>(0);
        }
    }
    return 0;
}