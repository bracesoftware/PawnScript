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


stock dpp_createtypedef(name[], const replacement[])
{
    for(new i; i < dpp_maxtypedef; i++)
    {
        if(dpp_validtypedef[i] == 0)
        {
            if(dpp_workingclassid != dpp_invalidclass)
            {
                new newvalue[dpp_argcharsize];
                format(newvalue,sizeof(newvalue),"DPPCt@%s_%s",dpp_classname[dpp_workingclassid],name);
                strmid(name, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            }
            dpp_validtypedef[i] = 1;
            strmid(dpp_typedefname[i], name, 0, dpp_maxstrsize,dpp_maxstrsize);
            strmid(dpp_typedefrepl[i], replacement, 0, dpp_maxstrsize,dpp_maxstrsize);
            return 1;
        }
    }
    return 1;
}