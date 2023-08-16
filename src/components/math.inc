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
        if(!strcmp(funcgroup[1], "vectorsize"))
        {
            if(!dpp_isfloat(args[0]))
            {
                dpp_error("Argument is supposed to be a double.",);
                dpp_internal<Float:return>(0.0);
            }
            if(!dpp_isfloat(args[1]))
            {
                dpp_error("Argument is supposed to be a double.",);
                dpp_internal<Float:return>(0.0);
            }
            if(!dpp_isfloat(args[2]))
            {
                dpp_error("Argument is supposed to be a double.",);
                dpp_internal<Float:return>(0.0);
            }
            if(!dpp_isfloat(args[3]))
            {
                dpp_error("Argument is supposed to be a double.",);
                dpp_internal<Float:return>(0.0);
            }
            if(!dpp_isfloat(args[4]))
            {
                dpp_error("Argument is supposed to be a double.",);
                dpp_internal<Float:return>(0.0);
            }
            if(!dpp_isfloat(args[5]))
            {
                dpp_error("Argument is supposed to be a double.",);
                dpp_internal<Float:return>(0.0);
            }

            new Float:dist = dpp_math__vectorsize(floatstr(args[0]),
                                                  floatstr(args[1]),
                                                  floatstr(args[2]),
                                                  floatstr(args[3]),
                                                  floatstr(args[4]),
                                                  floatstr(args[5]));

            dpp_internal<Float:return>(dist);
        }

        else
        {
            dpp_error("Unknown form in the component \"math\".",);
            dpp_internal<return>(0);
        }
    }
    return 0;
}