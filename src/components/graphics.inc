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


forward dpp_processgraphics(funcgroup[][],args[][],args_const[][]);
public dpp_processgraphics(funcgroup[][],args[][],args_const[][])
{
    if(!strcmp(funcgroup[0], "graphics"))
    {
        if(dpp_config[graphics_comp] == 0)
        {
            dpp_error("Component \"graphics\" is not imported.",);
            dpp_internal<return>(0);
        }
        // If the function used it "show"
        if(!strcmp(funcgroup[1], "show"))
        {
            CallLocalFunction("dpp_graphics__show", "");
            dpp_internal<return>(1);
        }
        //cls
        if(!strcmp(funcgroup[1], "cls"))
        {
            CallLocalFunction("dpp_graphics__cls", "");
            dpp_internal<return>(1);
        }
        //showpicel
        if(!strcmp(funcgroup[1], "showpixel"))
        {
        	if(!dpp_isnumeric(args[0]))
            {
                dpp_error("Argument error; value must be an integer.",);
                return 1;
            }
            if(!dpp_isnumeric(args[1]))
            {
                dpp_error("Argument error; value must be an integer.",);
                return 1;
            }

            printf("showpixel\t\targs[0] : '%i'\targs[1] : '%i'", strval(args[0]),strval(args[1]));

            CallLocalFunction("dpp_graphics__showpixel", "ii", strval(args[0]),strval(args[1]));
            dpp_internal<return>(1);
        }
  
		else
        {
            dpp_error("Unknown function in the component \"graphics\".",);
            dpp_internal<return>(0); // Here we return 0 in PAWNSCRIPT
        }
    }
    return 0; // Here we want to return 0 in PAWN.
}