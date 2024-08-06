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

stock dpp_createstk(const name[], size)
{
    if(size > dpp_maxstksize)
    {
        dpp_error("Invalid stack size specified.",);
        return 1;
    }
    //dpp_symbolcheck__(name);
    for(new i; i < dpp_maxstk; i++)
    {
        if(dpp_validstk[i] == 0)
        {
            dpp_validstk[i] = 1;
            strmid(dpp_stkname[i], name, 0, dpp_maxsymbolchar, dpp_maxsymbolchar);
            if(dpp_workingclassid != dpp_invalidclass)
            {
                new newvalue[dpp_argcharsize];
                format(newvalue,sizeof(newvalue),"DPPCstk@%s_%s",dpp_classname[dpp_workingclassid],name);
                strmid(dpp_stkname[i], newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            }
            dpp_symbolcheck__(name);
            dpp_stksize[i] = size;
            for(new stkvalid; stkvalid < size; stkvalid++)
            {
                strmid(dpp_stkvalues[i][stkvalid],dpp_invalidstkval,0,dpp_stkaddrsize,dpp_stkaddrsize);
            }
            dpp_error("STK LOG :: Created a stack : '%s'<%i>",name,size);
            return 1;
        }
    }
    return 1;
}

stock dpp_getstkocc(stkid)
{
    new ret = 0;
    for(new i; i < dpp_stksize[stkid]; i++)
    {
        if(strcmp(dpp_stkvalues[stkid][i], dpp_invalidstkval))
        {
            ret++;
        }
    }
    return ret;
}

stock dpp_pushvalue(stkid, const value[])
{
    if(dpp_getstkocc(stkid) == dpp_stksize[stkid])
    {
        dpp_fatalerror(9);
        return 1;
    }
    new ptr_addr__[2][dpp_argcharsize];
    dpp_parseline(value,ptr_addr__,'@');
    if(!dpp_isnumeric(ptr_addr__[0]) || !dpp_isnumeric(ptr_addr__[1]))
    {
        dpp_error("Invalid address (namely '%s') passed.",value);
        return 1;
    }
    
    for(new i; i < dpp_stksize[stkid]; i++)
    {
        if(!strcmp(dpp_stkvalues[stkid][i], dpp_invalidstkval))
        {
            strmid(dpp_stkvalues[stkid][i], value, 0, dpp_stkaddrsize,dpp_stkaddrsize);
            dpp_error("STK LOG :: Pushed to stack : '%s'<%i> = %s",dpp_stkname[stkid],i,dpp_stkvalues[stkid][i]);
            break;   
        }
    }
    //dpp_error("Added a value '%i' to an iter '%s'",value,name);
    return 1;
}

stock dpp_popvalue(stkid, dest[])
{
    if(dpp_getstkocc(stkid) == 0)
    {
        dpp_fatalerror(10);
        return 1;
    }
    for(new i = dpp_stksize[stkid] - 1; i > -1; i--)
    {
        if(strcmp(dpp_stkvalues[stkid][i], dpp_invalidstkval))
        {
            strmid(dest,dpp_stkvalues[stkid][i],0,dpp_stkaddrsize,dpp_stkaddrsize);
            dpp_error("STK LOG :: Popped from stack :: 0 : '%s'<%i> = %s",dpp_stkname[stkid],i,dpp_stkvalues[stkid][i]);
            strmid(dpp_stkvalues[stkid][i],dpp_invalidstkval,0,dpp_stkaddrsize,dpp_stkaddrsize);
            dpp_error("STK LOG :: Popped from stack :: 1 : '%s'<%i> = %s",dpp_stkname[stkid],i,dpp_stkvalues[stkid][i]);
            break;   
        }
    }
    return 1;
}


stock dpp_findstk(name[])
{
    dpp_argclasscheck(name);
    new stkid = -1;
    for(new i; i < dpp_maxstk; i++)
    {
        if(dpp_strcmp(name, dpp_stkname[i]))
        {
            if(dpp_validstk[i] == 1)
            {
                stkid = i;
                break;   
            }
        }
    }
    return stkid;
}

stock dpp_deletestk(name[])
{
    dpp_argclasscheck(name);
    for(new i; i < dpp_maxstk; i++)
    {
        if(dpp_strcmp(name, dpp_stkname[i]))
        {
            if(dpp_validstk[i] == 1)
            {
                dpp_validstk[i] = 0;
                return 1;   
            }
        }
    }
    //dpp_error("Iterator '%s' could not be found.",name);
    return 0;
}