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



dpp_taskinit();
public dpp_taskinit()
{
    for(new i; i < dpp_maxtasks; i++)
    {
    	if(dpp_validtask[i] == 1)
    	{
    		dpp_internaltasks[i] = SetTimerEx("dpp_runtask", dpp_interval[i], true, "i", i);
    	}
    }
    return 1;
}

dpp_runtask(taskid);
public dpp_runtask(taskid)
{
	if(dpp_terminated == 1)
	{
		return 1;
	}
	dpp_subexecute(dpp_taskcodeblock[taskid]);
    return 1;
}
