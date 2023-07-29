/*
*
* D++ Scripting Language
*     Made for a SA:MP server
*
*  Iterator and Foreach System
*
* 
* - by: DEntisT, (c) 2022
*
*/

stock dpp_createiter(const name[], size)
{
    for(new i; i < dpp_maxiter; i++)
    {
        if(dpp_validiter[i] == 0)
        {
            dpp_validiter[i] = 1;
            strmid(dpp_itername[i], name, 0, dpp_maxsymbolchar, dpp_maxsymbolchar);
            if(dpp_workingclassid != dpp_invalidclass)
            {
                new newvalue[dpp_argcharsize];
                format(newvalue,sizeof(newvalue),"DPPCi@%s_%s",dpp_classname[dpp_workingclassid],name);
                strmid(dpp_itername[i], newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            }
            dpp_itersize[i] = size;
            for(new itervalid; itervalid < size; itervalid++)
            {
                dpp_itervalues[i][itervalid] = dpp_invaliditerval;
            }
            //dpp_error("Created an iter '%s'",name);
            return 1;
        }
    }
    return 1;
}

stock dpp_addvalue(const name[], value)
{
    new iterid = -1;
    for(new i; i < dpp_maxiter; i++)
    {
        if(dpp_strcmp(name, dpp_itername[i]))
        {
            if(dpp_validiter[i] == 1)
            {
                iterid = i;
                break;   
            }
        }
    }
    if(iterid == -1)
    {
        dpp_error("Iterator '%s' could not be found.",name);
        return 1;
    }
    for(new i; i < dpp_itersize[iterid]; i++)
    {
        if(dpp_itervalues[iterid][i] == dpp_invaliditerval)
        {
            dpp_itervalues[iterid][i] = value;
            break;   
        }
    }
    //dpp_error("Added a value '%i' to an iter '%s'",value,name);
    return 1;
}

stock dpp_removevalue(const name[], value)
{
    new iterid = -1;
    for(new i; i < dpp_maxiter; i++)
    {
        if(dpp_strcmp(name, dpp_itername[i]))
        {
            if(dpp_validiter[i] == 1)
            {
                iterid = i;
                break;   
            }
        }
    }
    if(iterid == -1)
    {
        dpp_error("Iterator '%s' could not be found.",name);
        return 1;
    }
    for(new i; i < dpp_itersize[iterid]; i++)
    {
        if(dpp_itervalues[iterid][i] == value)
        {
            dpp_itervalues[iterid][i] = dpp_invaliditerval;
            break;   
        }
    }
    //dpp_error("Removed a value '%i' from an iter '%s'",value,name);
    return 1;
}


stock dpp_deleteiter(const name[])
{
    for(new i; i < dpp_maxiter; i++)
    {
        if(dpp_strcmp(name, dpp_itername[i]))
        {
            if(dpp_validiter[i] == 1)
            {
                dpp_validiter[i] = 0;
                return 1;   
            }
        }
    }
    //dpp_error("Iterator '%s' could not be found.",name);
    return 0;
}