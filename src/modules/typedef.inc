/*
*
* D++ Scripting Language
*     Made for a SA:MP server
*
* Support for typedef keyword
*
* 
* - by: DEntisT, (c) 2022
*
*/


stock dpp_createtypedef(const name[], const replacement[])
{
    for(new i; i < dpp_maxtypedef; i++)
    {
        if(dpp_validtypedef[i] == 0)
        {
            dpp_validtypedef[i] = 1;
            strmid(dpp_typedefname[i], name, 0, dpp_maxstrsize,dpp_maxstrsize);
            strmid(dpp_typedefrepl[i], replacement, 0, dpp_maxstrsize,dpp_maxstrsize);
            return 1;
        }
    }
    return 1;
}