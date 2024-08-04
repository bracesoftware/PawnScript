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

#define @PAWNSCRIPT_N_DECO@%0\32; @PAWNSCRIPT_N_DECO@
#define @pawnscript_sdk%0(%1) @PAWNSCRIPT_N_DECO@

#define _PS_N@%0\32; _PS_N@
#define @PAWNSCRIPT_N_DECO@native%0(%1) _PS_N@%0(%1);public _PS_N@%0(%1)

//////////////////////// == API == ////////////////////////

@pawnscript_sdk() native IsFuncValid(const name[])
{
    new localname[dpp_maxsymbolchar],_query__ = -1;
    strmid(localname,name,0,sizeof localname,sizeof localname);
    dpp_argclasscheck(localname);
    dpp_argoclasscheck(localname);
    dpp_sdkprint("Searching for a function : '%s'",localname);
    for(new i; i < dpp_maxfuncs; i++)
    {
        if(!strcmp(dpp_funcname[i], localname))
        {
            if(dpp_validfunc[i] == 1 && dpp_hookform[i] == 0)
            {
                if(dpp_privatefunc[i] == 0)
                {
                    _query__ = i;
                }
            }
        }
    }
    if(_query__ == -1)
    {
        dpp_sdkprint("Function not found.");
        return 0;
    }
    dpp_sdkprint("Function found.");
    return 1;
}
//SOME MORE INTERNAL SHEET
PS_CallRemoteFunction(funcname[],args__[]);
public PS_CallRemoteFunction(funcname[],args__[])
{
    return CallLocalFunction("__PS_CallRemoteFunction__","ssi",funcname,args__,0);
}

PS_Callback(funcname[],args__[]);
public PS_Callback(funcname[],args__[])
{
    return CallLocalFunction("__PS_CallRemoteFunction__","ssi",funcname,args__,1);
}

forward __PS_CallRemoteFunction__(funcname[],args__[],callback);
public __PS_CallRemoteFunction__(funcname[],args__[],callback)
{
    dpp_print("PS_CallRemoteFunction called: funcname - '%s', args__ - '%s'",funcname,args__);
    new args[dpp_maxformargs][dpp_maxsymbolchar/2];
    dpp_parseline(args__,args,',');
    for(new i; i < dpp_maxformargs; i++)
    {
        dpp_codetrim(args[i]);
    }
    dpp_argclasscheck(funcname);
    dpp_argoclasscheck(funcname);
    for(new i; i < dpp_maxfuncs; i++)
    {
        if(!strcmp(dpp_funcname[i], funcname))
        {
            if(dpp_privatefunc[i] == 1)
            {
                return 1;
            }
            if(callback == 1) if(dpp_structtype[i] != dpp_callbackstruct)
            {
                return 1;
            }
            if(dpp_hookform[i] == 0)
            {
                for(new argid; argid < dpp_maxformargs; argid++)
                {
                    strmid(dpp_args[i][argid][dpp_argvalue],
                        args[argid],
                        0,
                        dpp_argcharsize/2,
                        dpp_argcharsize/2);
                }
                dpp_returned[i] = 0;
                dpp_processfunc = i;
                dpp_subexecute(dpp_funccodeblock[i], i);
                //dpp_debug("dpp_funccodeblock[i]:%s",dpp_funccodeblock[i]);

                if(dpp_option_hooking == 1)
                {
                    for(new hookfuncid; hookfuncid < dpp_maxfuncs; hookfuncid++)
                    {
                        if(!strcmp(dpp_funcname[hookfuncid], funcname))
                        {
                            if(dpp_hookform[hookfuncid] == 1)
                            {
                                for(new argid; argid < dpp_maxformargs; argid++)
                                {
                                    strmid(dpp_args[hookfuncid][argid][dpp_argvalue],
                                        args[argid],
                                        0,
                                        dpp_argcharsize/2,
                                        dpp_argcharsize/2);
                                }
                                dpp_processfunc = hookfuncid;
                                //dpp_warning("#1 Hookfunc: '%s' | Code: '%s'",dpp_funcname[hookfuncid],dpp_funccodeblock[hookfuncid]);
                                dpp_subexecute(dpp_funccodeblock[hookfuncid], hookfuncid);
                                //dpp_warning("#2 Hookfunc: '%s' | Code: '%s'",dpp_funcname[hookfuncid],dpp_funccodeblock[hookfuncid]);
                                //dpp_debug("dpp_funccodeblock[hookfuncid]:%s",dpp_funccodeblock[hookfuncid]);
                            }
                        }
                    }
                }
                dpp_clearformstack(dpp_processfunc); 
                dpp_deletestaticvars();
                dpp_processfunc = DPP_INVALID_FORM_ID;
                return 1;
            }
        }
    }
    return 0;
}