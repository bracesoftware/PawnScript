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


forward dpp_processbitarr(funcgroup[][],args[][],args_const[][]);
public dpp_processbitarr(funcgroup[][],args[][],args_const[][])
{
    if(!strcmp(funcgroup[0], "bitarr"))
    {
        if(dpp_config[bitarr_comp] == 0)
        {
            dpp_error("Component \"bitarr\" is not imported.",);
            dpp_internal<return>(0);
        }
        new bitarrid = dpp_findbitarr(funcgroup[1]);
        if(bitarrid == -1)
        {
            dpp_fatalerror(8);
            dpp_internal<return>(0);
        }
        // If the function used it "print"
        if(!strcmp(funcgroup[2], "get_at"))
        {
            if(!dpp_isnumeric(args[0]))
            {
                dpp_error("Data type mismatch; unknown value.",);
                return 1;
            }
            dpp_internal<return>(dpp_getbitvalue(bitarrid, strval(args[0])));
        }
        if(!strcmp(funcgroup[2], "set_at"))
        {
            if(!dpp_isnumeric(args[0]))
            {
                dpp_error("Data type mismatch; unknown value.",);
                return 1;
            }
            if(!dpp_isnumeric(args[1]))
            {
                dpp_error("Data type mismatch; unknown value.",);
                return 1;
            }
            dpp_setbitvalue(bitarrid,strval(args[0]),strval(args[1]));
            dpp_internal<return>(1);
        }
        else
        {
            dpp_error("Unknown form in the component \"bitarr\".",);
            dpp_internal<return>(0);
        }
    }
    return 0;
}