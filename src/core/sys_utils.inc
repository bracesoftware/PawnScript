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

stock dpp_fatalerror(errorid, const fmat[] = "")
{
    if(errorid == 1)
    {
        dpp_fatalerror__("Attempted to modify a final code block.");
        dpp_terminated = 1;
        dpp_info("Process has been terminated to prevent further complication.");
        return 1;
    }
    if(errorid == 2)
    {
        dpp_fatalerror__("System encountered an invalid declaration.");
        dpp_terminated = 1;
        dpp_info("Process has been terminated to prevent further complication.");
        return 1;
    }
    if(errorid == 3)
    {
        dpp_fatalerror__("Invalid assembler instruction.");
        dpp_terminated = 1;
        dpp_info("Process has been terminated to prevent further complication.");
        return 1;
    }
    if(errorid == 4)
    {
        dpp_fatalerror__("Invalid memory access.");
        dpp_terminated = 1;
        dpp_info("Process has been terminated to prevent further complication.");
        return 1;
    }
    if(errorid == 5)
    {
        dpp_fatalerror__("Redefinition of a symbol: '%s'", fmat);
        dpp_terminated = 1;
        dpp_info("Process has been terminated to prevent further complication.");
        return 1;
    }
    if(errorid == 6)
    {
        dpp_fatalerror__("Invalid expression; assumed zero: '%s'", fmat);
        dpp_terminated = 1;
        dpp_info("Process has been terminated to prevent further complication.");
        return 1;
    }
    if(errorid == 7)
    {
        dpp_fatalerror__("Format system failed.");
        dpp_terminated = 1;
        dpp_info("Process has been terminated to prevent further complication.");
        return 1;
    }
    if(errorid == 8)
    {
        dpp_fatalerror__("Invalid object passed by reference.");
        dpp_terminated = 1;
        dpp_info("Process has been terminated to prevent further complication.");
        return 1;
    }
    if(errorid == 9)
    {
        dpp_fatalerror__("Memory container overflow - system is facing insufficient container size.");
        dpp_terminated = 1;
        dpp_info("Process has been terminated to prevent further complication.");
        return 1;
    }
    if(errorid == 10)
    {
        dpp_fatalerror__("Memory container underflow - system is facing insufficient container size.");
        dpp_terminated = 1;
        dpp_info("Process has been terminated to prevent further complication.");
        return 1;
    }
    return 0;
}