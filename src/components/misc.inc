/*
*
* D++ Scripting Language
*     Made for a SA:MP server
*
* Component impl: misc
*
* 
* - by: DEntisT, (c) 2022
*
*/


forward dpp_processmisc(funcgroup[][],args[][],args_const[][]);
public dpp_processmisc(funcgroup[][],args[][],args_const[][])
{
    if(!strcmp(funcgroup[0], "misc"))
    {
        if(dpp_config[misc_comp] == 0)
        {
            dpp_error("Component \"misc\" is not imported.",);
            dpp_internal<return>(0);
        }
        if(!strcmp(funcgroup[1], "swap"))
        {
            new 
                dpp_var1 = -1,
                dpp_var2 = -1,
                oldval_int,
                oldval_bool,
                oldval_str[256],
                Float:oldval_double,
                oldval_char;

            for(new i; i < dpp_maxvar; i++)
            {
                if(!strcmp(args_const[0], dpp_vardata[i][var_name]))
                {
                    if(dpp_vardata[i][var_valid] == 1)
                    {
                        dpp_var1 = i;
                        break;
                    }
                }
            }

            for(new i; i < dpp_maxvar; i++)
            {
                if(!strcmp(args_const[1], dpp_vardata[i][var_name]))
                {
                    if(dpp_vardata[i][var_valid] == 1)
                    {
                        dpp_var2 = i;
                        break;
                    }
                }
            }

            if(dpp_var1 == -1 || dpp_var2 == -1)
            {
                dpp_error("Unknown variable; swap not possible.",);
                return 1;
            }

            oldval_int = dpp_vardata[dpp_var1][integervalue];
            oldval_bool = dpp_vardata[dpp_var1][boolvalue];
            strmid(oldval_str, dpp_vardata[dpp_var1][stringvalue], 0, 256, 256);
            oldval_double = dpp_vardata[dpp_var1][floatvalue];
            oldval_char = dpp_vardata[dpp_var1][charvalue];

            dpp_vardata[dpp_var1][integervalue] = dpp_vardata[dpp_var2][integervalue];
            dpp_vardata[dpp_var1][boolvalue] = dpp_vardata[dpp_var2][boolvalue];
            strmid(dpp_vardata[dpp_var1][stringvalue], dpp_vardata[dpp_var2][stringvalue], 0, 256, 256);
            dpp_vardata[dpp_var1][floatvalue] = dpp_vardata[dpp_var2][floatvalue];
            dpp_vardata[dpp_var1][charvalue] = dpp_vardata[dpp_var2][charvalue];

            dpp_vardata[dpp_var2][integervalue] = oldval_int;
            dpp_vardata[dpp_var2][boolvalue] = oldval_bool;
            strmid(dpp_vardata[dpp_var2][stringvalue], oldval_str, 0, 256, 256);
            dpp_vardata[dpp_var2][floatvalue] = oldval_double;
            dpp_vardata[dpp_var2][charvalue] = oldval_char;
            dpp_internal<return>(1);
        }

        else
        {
            dpp_error("Unknown form in the component \"misc\".",);
            dpp_internal<return>(0);
        }
    }
    return 0;
}