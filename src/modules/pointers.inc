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


stock dpp_createptr(const name[], const addr[])
{
	for(new i; i < dpp_maxptr; i++)
	{
		if(dpp_ptrdata[i][ptr_valid] == 0)
		{
			new ptr_addr[2][dpp_maxsymbolchar];

			dpp_parseline(addr,ptr_addr,'@');
			if(!dpp_isnumeric(ptr_addr[0]) || !dpp_isnumeric(ptr_addr[1]))
			{
				dpp_error("Invalid memory address passed to pointer '%s'.",name);
				return 1;
			}

			dpp_ptrdata[i][ptr_valid] = 1;
			strmid(dpp_ptrdata[i][ptr_name],name,0,dpp_maxsymbolchar,dpp_maxsymbolchar);
			dpp_ptrdata[i][ptr_cell] = strval(ptr_addr[0]);
			dpp_ptrdata[i][ptr_memsec] = strval(ptr_addr[1]);
			return 1;
		}
	}
	return 1;
}

stock dpp_updatepointer(const name[], const addr[])
{
	for(new i; i < dpp_maxptr; i++)
	{
		if(!strcmp(dpp_ptrdata[i][ptr_name],name) && dpp_ptrdata[i][ptr_valid] == 1)
        {
        	new ptr_addr[2][dpp_maxsymbolchar];

			dpp_parseline(addr,ptr_addr,'@');
			if(!dpp_isnumeric(ptr_addr[0]) || !dpp_isnumeric(ptr_addr[1]))
			{
				dpp_error("Invalid memory address passed to pointer '%s'.",name);
				return 1;
			}

			dpp_ptrdata[i][ptr_cell] = strval(ptr_addr[0]);
			dpp_ptrdata[i][ptr_memsec] = strval(ptr_addr[1]);
            return 1;
        }
	}
	return 1;
}

forward dpp_argptrtosym(arg[]);
public dpp_argptrtosym(arg[])
{
    new newvalue[dpp_argcharsize];/*
        enumdata[2][dpp_maxsymbolchar];

    dpp_parseline(arg,enumdata,'.');

    dpp_argclasscheck(enumdata[0]);*/

    new ptrid = -1;
    for(new i; i < dpp_maxptr; i++)
    {
        if(!strcmp(dpp_ptrdata[i][ptr_name],arg) && dpp_ptrdata[i][ptr_valid] == 1)
        {
            ptrid = i;
            break;
        }
    }

    if(ptrid == -1)
    {
        return 1;
    }

    if(dpp_ptrdata[ptrid][ptr_memsec] == dpp_memsec_var)
    {
    	strmid(arg,dpp_vardata[
    			dpp_ptrdata[ptrid][ptr_cell]
    		][var_name],0,dpp_maxsymbolchar,dpp_maxsymbolchar);
    }
    return 1;
}

forward dpp_argptrcheck(arg[]);
public dpp_argptrcheck(arg[])
{
    new newvalue[dpp_argcharsize];/*
        enumdata[2][dpp_maxsymbolchar];

    dpp_parseline(arg,enumdata,'.');

    dpp_argclasscheck(enumdata[0]);*/

    new ptrid = -1;
    for(new i; i < dpp_maxptr; i++)
    {
        if(!strcmp(dpp_ptrdata[i][ptr_name],arg) && dpp_ptrdata[i][ptr_valid] == 1)
        {
            ptrid = i;
            break;
        }
    }

    if(ptrid == -1)
    {
        return 1;
    }

    format(newvalue, sizeof newvalue, "%i@%i", dpp_ptrdata[ptrid][ptr_cell],dpp_ptrdata[ptrid][ptr_memsec]);
    strmid(arg, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
    return 1;
}