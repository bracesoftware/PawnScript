/*
*
* D++ Scripting Language
*     Made for a SA:MP server
*
* Component impl: math
*
* 
* - by: DEntisT, (c) 2022
*
*/


forward dpp_processmath(funcgroup[][],args[][]);
public dpp_processmath(funcgroup[][],args[][])
{
    if(!strcmp(funcgroup[0], "math"))
    {
        if(dpp_config[math_comp] == 0)
        {
            dpp_error("Component \"math\" is not imported.",);
            dpp_internal<return>(0);
        }
        if(!strcmp(funcgroup[1], "func"))
        {
            dpp_internal<return>(1);
        }

        else
        {
            dpp_error("Unknown form in the component \"math\".",);
            dpp_internal<return>(0);
        }
    }
    return 0;
}