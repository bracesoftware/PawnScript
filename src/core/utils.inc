/*
*
* PawnScript Scripting Language
*     Made for a SA:MP server
*
* Error System
*
* 
* - by: DEntisT, (c) 2022
*
*/

#define dpp_fatalerror__(%1)    printf("*** [PawnScript] FATAL ERROR - Info: "%1)

stock dpp_fatalerror(errorid)
{
    if(errorid == 1)
    {
        dpp_fatalerror__("Attempted to modify a constexpr namespace.");
        dpp_terminated = 1;
        dpp_info("Process has been terminated to prevent further complications.");
        return 1;
    }
    return 0;
}