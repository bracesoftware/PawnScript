/*
*
* D++ Scripting Language
*     Made for a SA:MP server
*
* Component impl: samp
*
* 
* - by: DEntisT, (c) 2022
*
*/


DPP_GAMEMODEINIT();
public DPP_GAMEMODEINIT()
{
    if(dpp_config[samp_comp] == 0)
    {
        return 1;
    }

    for(new i; i < dpp_maxfuncs; i++)
    {
        if(!strcmp(dpp_funcname[i], "OnGameModeInit"))
        {
            if(dpp_autoform[i] == 0) return 1;
            if(dpp_hookform[i] == 0)
            {
                dpp_processfunc = i;
                dpp_subexecute(dpp_funccodeblock[i],i);
                dpp_debug("dpp_funccodeblock[i]:%s",dpp_funccodeblock[i]);
                dpp_debug("\"OnGameModeInit\" called.");

                if(dpp_option_hooking == 1)
                {
                    for(new hookfuncid; hookfuncid < dpp_maxfuncs; hookfuncid++)
                    {
                        if(!strcmp(dpp_funcname[hookfuncid], "OnGameModeInit"))
                        {
                            if(dpp_hookform[hookfuncid] == 1)
                            {
                                dpp_returned[hookfuncid] = 0;
                                dpp_processfunc = hookfuncid;
                                dpp_subexecute(dpp_funccodeblock[hookfuncid],hookfuncid);
                                dpp_debug("dpp_funccodeblock[hookfuncid]:%s",dpp_funccodeblock[hookfuncid]);
                            }
                        }
                    }
                }
            }
            return 1;
        }
    }

    return 1;
}

dpp_sampexitcall(); public dpp_sampexitcall()
{
    if(dpp_config[samp_comp] == 0)
    {
        return 1;
    }

    for(new i; i < dpp_maxfuncs; i++)
    {
        if(!strcmp(dpp_funcname[i], "OnGameModeExit"))
        {
            if(dpp_autoform[i] == 0) return 1;
            dpp_processfunc = i;
            dpp_subexecute(dpp_funccodeblock[i],i);
            dpp_debug("dpp_funccodeblock[i]:%s",dpp_funccodeblock[i]);
            dpp_debug("\"OnGameModeInit\" called.");
            if(dpp_hookform[i] == 0)
            {
                if(dpp_option_hooking == 1)
                {
                    for(new hookfuncid; hookfuncid < dpp_maxfuncs; hookfuncid++)
                    {
                        if(!strcmp(dpp_funcname[hookfuncid], "OnGameModeExit"))
                        {
                            if(dpp_hookform[hookfuncid] == 1)
                            {
                                dpp_returned[hookfuncid] = 0;
                                dpp_processfunc = hookfuncid;
                                dpp_subexecute(dpp_funccodeblock[hookfuncid],hookfuncid);
                                dpp_debug("dpp_funccodeblock[hookfuncid]:%s",dpp_funccodeblock[hookfuncid]);
                            }
                        }
                    }
                }
            }
            return 1;
        }
    }

    return 1;
}

public OnPlayerConnect(playerid)
{
    if(dpp_config[samp_comp] == 0)
    {
        return 1;
    }
    new dpp_argval[dpp_argcharsize];
    for(new i; i < dpp_maxfuncs; i++)
    {
        if(!strcmp(dpp_funcname[i], "OnPlayerConnect"))
        {
            if(dpp_autoform[i] == 0) return 1;
            //Argument setup
            // playerid
            format(dpp_argval, sizeof dpp_argval, "%i", playerid);
            strmid(dpp_args[i][0][dpp_argvalue],
                    dpp_argval,
                    0,
                    dpp_argcharsize,
                    dpp_argcharsize);

            // Form call
            dpp_processfunc = i;
            dpp_subexecute(dpp_funccodeblock[i],i);
            dpp_debug("dpp_funccodeblock[i]:%s",dpp_funccodeblock[i]);
            dpp_debug("\"OnPlayerConnect\" called.");
            if(dpp_hookform[i] == 0)
            {
                if(dpp_option_hooking == 1)
                {
                    for(new hookfuncid; hookfuncid < dpp_maxfuncs; hookfuncid++)
                    {
                        if(!strcmp(dpp_funcname[hookfuncid], "OnPlayerConnect"))
                        {
                            if(dpp_hookform[hookfuncid] == 1)
                            {
                                // Argument setup
                                //playerid
                                format(dpp_argval, sizeof dpp_argval, "%i", playerid);
                                strmid(dpp_args[hookfuncid][0][dpp_argvalue],
                                        dpp_argval,
                                        0,
                                        dpp_argcharsize,
                                        dpp_argcharsize);

                                // Func call:
                                dpp_returned[hookfuncid] = 0;
                                dpp_processfunc = hookfuncid;
                                dpp_subexecute(dpp_funccodeblock[hookfuncid],hookfuncid);
                                dpp_debug("dpp_funccodeblock[hookfuncid]:%s",dpp_funccodeblock[hookfuncid]);
                            }
                        }
                    }
                }
            }
            return 1;
        }
    }

    return 1;
}


public OnPlayerDisconnect(playerid, reason)
{
    if(dpp_config[samp_comp] == 0)
    {
        return 1;
    }
    new dpp_argval[dpp_argcharsize];
    for(new i; i < dpp_maxfuncs; i++)
    {
        if(!strcmp(dpp_funcname[i], "OnPlayerDisconnect"))
        {
            if(dpp_autoform[i] == 0) return 1;
            //Argument setup
            // playerid
            format(dpp_argval, sizeof dpp_argval, "%i", playerid);
            strmid(dpp_args[i][0][dpp_argvalue],
                    dpp_argval,
                    0,
                    dpp_argcharsize,
                    dpp_argcharsize);

            // reason
            format(dpp_argval, sizeof dpp_argval, "%i", reason);
            strmid(dpp_args[i][1][dpp_argvalue],
                    dpp_argval,
                    0,
                    dpp_argcharsize,
                    dpp_argcharsize);


            // Form call
            dpp_processfunc = i;
            dpp_subexecute(dpp_funccodeblock[i],i);
            dpp_debug("dpp_funccodeblock[i]:%s",dpp_funccodeblock[i]);
            dpp_debug("\"OnPlayerDisconnect\" called.");
            if(dpp_hookform[i] == 0)
            {
                if(dpp_option_hooking == 1)
                {
                    for(new hookfuncid; hookfuncid < dpp_maxfuncs; hookfuncid++)
                    {
                        if(!strcmp(dpp_funcname[hookfuncid], "OnPlayerDisconnect"))
                        {
                            if(dpp_hookform[hookfuncid] == 1)
                            {
                                // Argument setup
                                //playerid
                                format(dpp_argval, sizeof dpp_argval, "%i", playerid);
                                strmid(dpp_args[hookfuncid][0][dpp_argvalue],
                                        dpp_argval,
                                        0,
                                        dpp_argcharsize,
                                        dpp_argcharsize);
                                //reason
                                format(dpp_argval, sizeof dpp_argval, "%i", reason);
                                strmid(dpp_args[hookfuncid][1][dpp_argvalue],
                                        dpp_argval,
                                        0,
                                        dpp_argcharsize,
                                        dpp_argcharsize);


                                // Func call:
                                dpp_returned[hookfuncid] = 0;
                                dpp_processfunc = hookfuncid;
                                dpp_subexecute(dpp_funccodeblock[hookfuncid],hookfuncid);
                                dpp_debug("dpp_funccodeblock[hookfuncid]:%s",dpp_funccodeblock[hookfuncid]);
                            }
                        }
                    }
                }
            }
            return 1;
        }
    }

    return 1;
}

///////////// FUNCS

stock SetMaxPlayers(maxplayers)
{
    new rconcmd[50];
    format(rconcmd, 50, "maxplayers %i", maxplayers);
    return SendRconCommand(rconcmd);
}

forward dpp_processsamp(funcgroup[][],args[][]);
public dpp_processsamp(funcgroup[][],args[][])
{
    if(!strcmp(funcgroup[0], "samp"))
    {
        if(dpp_config[samp_comp] == 0)
        {
            dpp_error("Component \"samp\" is not imported.",);
            return 1;
        }
        //SetGameModeText
        if(!strcmp(funcgroup[1], "SetGameModeText"))
        {
            new mul, str[dpp_argcharsize];
            strmid(str, args[0], 0, dpp_argcharsize);
            for(new i; i < strlen(args[0]); i++)
            {
                if(args[0][i] == '\"') mul++, strdel(args[0], i, i+1);
            }
            if(mul == 0)
            {
                dpp_error("You need to use '\"' to start a string.",);
                return 1;
            }
            if(mul != 2)
            {
                dpp_error("Argument error; [%i] \"%s\"", mul, args[0]);
                return 1;
            }

            SetGameModeText(args[0]);
            return 1;
        }
        // Does not exist SetMaxPlayers
        if(!strcmp(funcgroup[1], "SetMaxPlayers"))
        {
            if(!dpp_isnumeric(args[0]))
            {
                dpp_error("Argument error; value must be an integer.",);
                return 1;
            }

            SetMaxPlayers(strval(args[0]));
            return 1;
        }

        //SendClientMessage
        if(!strcmp(funcgroup[1], "SendClientMessage"))
        {
            if(!dpp_isnumeric(args[0]))
            {
                dpp_error("Argument error; value must be an integer.",);
                return 1;
            }

            if(!dpp_isnumeric(args[1]))
            {
                dpp_error("Argument error; value must be an integer.",);
                return 1;
            }

            new mul, str[dpp_argcharsize];
            strmid(str, args[2], 0, dpp_argcharsize);
            for(new i; i < strlen(args[2]); i++)
            {
                if(args[2][i] == '\"') mul++, strdel(args[2], i, i+1);
            }
            if(mul == 0)
            {
                dpp_error("You need to use '\"' to start a string.",);
                return 1;
            }
            if(mul != 2)
            {
                dpp_error("Argument error; [%i] \"%s\"", mul, args[2]);
                return 1;
            }

            SendClientMessage(strval(args[0]),strval(args[1]),args[2]);
            return 1;
        }


        else
        {
            dpp_error("Unknown form in the component \"samp\".",);
            return 1;
        }
    }
    return 0;
}

//////////////////////////////////
// samp_commands external forms //
//////////////////////////////////

public OnPlayerCommandText(playerid, cmdtext[])
{
    if(dpp_config[samp_comp] == 0)
    {
        return 1;
    }


    dpp_error("cmdtext : '%s'",cmdtext);

    new dpp_cmdargs[2][1024];
    dpp_parseline(cmdtext, dpp_cmdargs, ' ');

    for(new i; i < strlen(dpp_cmdargs[0]); i++)
    {
        if(dpp_cmdargs[0][i] == '/') strdel(dpp_cmdargs[0], i, i+1);
    }

    dpp_error("Attempting to call '%s' with params : '%s'",dpp_cmdargs[0],dpp_cmdargs[1]);

    new dpp_argval[dpp_argcharsize];
    for(new i; i < dpp_maxfuncs; i++)
    {
        if(!strcmp(dpp_funcname[i], dpp_cmdargs[0]))
        {
            if(dpp_structtype[i] == dpp_formstruct_local) return 1;
            //Argument setup
            // playerid
            format(dpp_argval, sizeof dpp_argval, "%i", playerid);
            strmid(dpp_args[i][0][dpp_argvalue],
                    dpp_argval,
                    0,
                    dpp_argcharsize,
                    dpp_argcharsize);

            // params
            strmid(dpp_args[i][1][dpp_argvalue],
                    dpp_cmdargs[1],
                    0,
                    dpp_argcharsize,
                    dpp_argcharsize);


            // Form call
            dpp_processfunc = i;
            dpp_subexecute(dpp_funccodeblock[i],i);
            dpp_debug("dpp_funccodeblock[i]:%s",dpp_funccodeblock[i]);
            if(dpp_hookform[i] == 0)
            {
                if(dpp_option_hooking == 1)
                {
                    for(new hookfuncid; hookfuncid < dpp_maxfuncs; hookfuncid++)
                    {
                        if(!strcmp(dpp_funcname[hookfuncid], dpp_cmdargs[0]))
                        {
                            if(dpp_hookform[hookfuncid] == 1)
                            {
                                // Argument setup
                                //playerid
                                format(dpp_argval, sizeof dpp_argval, "%i", playerid);
                                strmid(dpp_args[hookfuncid][0][dpp_argvalue],
                                        dpp_argval,
                                        0,
                                        dpp_argcharsize,
                                        dpp_argcharsize);
                                //params
                                strmid(dpp_args[hookfuncid][1][dpp_argvalue],
                                        dpp_cmdargs[1],
                                        0,
                                        dpp_argcharsize,
                                        dpp_argcharsize);


                                // Func call:
                                dpp_returned[hookfuncid] = 0;
                                dpp_processfunc = hookfuncid;
                                dpp_subexecute(dpp_funccodeblock[hookfuncid],hookfuncid);
                                dpp_debug("dpp_funccodeblock[hookfuncid]:%s",dpp_funccodeblock[hookfuncid]);
                            }
                        }
                    }
                }
            }
            return 1;
        }
    }

    return 1;
}
