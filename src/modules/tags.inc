/*
*
* D++ Scripting Language
*     Made for a SA:MP server
*
*  Tag System
*
* 
* - by: DEntisT, (c) 2022
*
*/


stock dpp_createtag(name[])
{
    for(new i; i < dpp_maxtag; i++)
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


dpp_argtagcheck(arg[]);
public dpp_argtagcheck(arg[])
{
    new 
        newvalue[64],
        tagid = -1;

    dpp_argclasscheck(arg);
    dpp_argoclasscheck(arg);

    for(new i; i < dpp_maxtag; i++)
    {
        if(dpp_validobj[i] == 1 && !strcmp(arg, dpp_objname[i]))
        {
            tagid = i;
            break;
        }
    }

    if(tagid == -1)
    {
        return 1;
    }

    format(newvalue, sizeof newvalue, "%i", tagid);

    strmid(arg, newvalue, 0, dpp_maxsymbolchar, dpp_maxsymbolchar);
    return 1;
}