/*
*
* D++ Scripting Language
*     Made for a SA:MP server
*
* Inline forms
*
* 
* - by: DEntisT, (c) 2022
*
*/

dpp_createinline(name[], baseformid); public dpp_createinline(name[], baseformid)
{
    for(new i; i < dpp_maxinline; i++)
    {
        if(dpp_validinline[i] == 0)
        {
            dpp_validinline[i] = 1;
            strmid(dpp_inlinename[i], name, 0, 64, 64);
            dpp_inlinebaseform[i] = baseformid;
            dpp_currentinlineid = i;
            //dpp_error("Created an inline named '%s' [%i] with base form id '%i'",name,dpp_currentinlineid,baseformid);
            return 1;
        }
    }
    return 1;
}

stock dpp_clearformstack(formid)
{
    for(new i; i < dpp_maxinline; i++)
    {
        if(dpp_inlinebaseform[i] == formid)
        {
            dpp_validinline[i] = 0;
            strmid(dpp_inlinecodeblock[i],";",0,10,10);
            return 1;
        }
    }
    return 1;
}