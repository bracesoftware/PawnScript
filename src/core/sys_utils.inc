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

#define dpp_fatalerror__(%1)    printf("*** [PawnScript] FATAL ERROR - Info: "%1)

stock dpp_fatalerror(errorid)
{
    if(errorid == 1)
    {
        dpp_fatalerror__("Attempted to modify a constexpr namespace.");
        dpp_terminated = 1;
        dpp_info("Process has been terminated to prevent further complication.");
        return 1;
    }
    return 0;
}