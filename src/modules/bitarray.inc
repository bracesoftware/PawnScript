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

stock dpp_createbitarr(const name[], size)
{
    for(new i; i < dpp_maxbitarr; i++)
    {
        if(dpp_bitarrdata[i][bitarr_valid] == 0)
        {
            dpp_bitarrdata[i][bitarr_valid] = 1;
            strmid(dpp_bitarrdata[i][bitarr_name], name, 0, dpp_maxsymbolchar, dpp_maxsymbolchar);
            if(dpp_workingclassid != dpp_invalidclass)
            {
                new newvalue[dpp_argcharsize];
                format(newvalue,sizeof(newvalue),"DPPCba@%s_%s",dpp_classname[dpp_workingclassid],name);
                strmid(dpp_bitarrdata[i][bitarr_name], newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            }
            dpp_symbolcheck__(name);
            if(!(0 < size <= 32))
            {
            	dpp_error("Invalid bit array size.",);
            	dpp_bitarrdata[i][bitarr_valid] = 0;
            	return 0;
            }
            dpp_bitarrdata[i][bitarr_size] = size;
            dpp_bitarrdata[i][bitarr_value] = 0;
            return 1;
        }
    }
    return 1;
}

stock dpp_findbitarr(name[])
{
	dpp_argclasscheck(name);
	new bitarrid = -1;
    for(new i; i < dpp_maxbitarr; i++)
    {
        if(dpp_strcmp(name, dpp_bitarrdata[i][bitarr_name]))
        {
            if(dpp_bitarrdata[i][bitarr_valid] == 1)
            {
                bitarrid = i;
                break;   
            }
        }
    }
    return bitarrid;
}

stock dpp_getbitvalue(bitarrid, index)
{
	if(index >= dpp_bitarrdata[bitarrid][bitarr_size])
	{
		return 0;
	}
	return dpp_bitarrdata[bitarrid][bitarr_value] & (1 << index) ? 1 : 0;
}

stock dpp_setbitvalue(bitarrid, index, value)
{
	if(value != 0 && value != 1)
	{
		return 1;
	}
	if(!(0 <= index < 32))
	{
		return 1;
	}
	if(index >= dpp_bitarrdata[bitarrid][bitarr_size])
	{
		return 0;
	}

	dpp_bitarrdata[bitarrid][bitarr_value] = value ? (dpp_bitarrdata[bitarrid][bitarr_value] | (1 << index)) : (dpp_bitarrdata[bitarrid][bitarr_value] & ~(1 << index));
	return 1;
}