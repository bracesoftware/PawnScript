/*
*
* D++ Scripting Language
*     Made for a SA:MP server
*
*  Object System
*
* 
* - by: DEntisT, (c) 2022
*
*/


stock dpp_createobj(name[])
{
    for(new i; i < dpp_maxobj; i++)
    {
        if(dpp_validobj[i] == 0)
        {
            dpp_validobj[i] = 1;
            strmid(dpp_objname[i], name, 0, dpp_maxsymbolchar, dpp_maxsymbolchar);

            if(dpp_workingclassid != dpp_invalidclass)
            {
                new newvalue[dpp_argcharsize];
                format(newvalue,sizeof(newvalue),"DPPCo@%s_%s",dpp_classname[dpp_workingclassid],name);
                strmid(name, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            }

            strmid(dpp_objname[i], name, 0, dpp_maxsymbolchar, dpp_maxsymbolchar);

            return 1;
        }
    }
    return 1;
}