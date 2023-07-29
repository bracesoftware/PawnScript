/*
*
* D++ Scripting Language
*     Made for a SA:MP server
*
*  Task System
*
* 
* - by: DEntisT, (c) 2022
*
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
