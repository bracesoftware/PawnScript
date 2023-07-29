/*
 *
 * D++ Scripting Language
 *     Made for a SA:MP server
 *
 * Functions/header
 *
 * 
 * - by: DEntisT, (c) 2022
 *
 */

#define dpp_header 1

#define dpp_info dpp_print
#define isnull(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#define dpp_execheader%0(%1) print("|====================| "%1" |====================|")
#define dpp_comment%0(%1) print("|==============================================|")
#define dpp_nullcomment%1(%1) print("                                               ")
#define dpp_print%0(%1) printf("[PawnScript] SERVER THREAD - Info: "%1)
#define dpp_compilerprint%0(%1) printf("[PawnScript] COMPILER: "%1)
#if DPP_DEBUG == 1
#define dpp_debug%0(%1) if(dpp_option_debug==1)printf("[PawnScript] | DEBUG: "%1)
#elseif DPP_DEBUG == 0
#define dpp_debug%0(%1)%2;
#endif

new
    dpp_error_str[1024];

#define __line,) __line)


#define dpp_error%0(%1,%2) format(dpp_error_str,sizeof dpp_error_str,"[PawnScript] ERROR (dpp.amx @ %s:%i): "%1,__file,__line,%2)&& \
    print(dpp_error_str)&&dpp_incerrcnt()

#define dpp_apierror%0(%3,%1,%2) format(dpp_error_str,sizeof dpp_error_str,"[PawnScript] API ("%3") ERROR (dpp.amx @ %s:%i): "%1,__file,__line,%2)&& \
    print(dpp_error_str)&&dpp_incerrcnt()
 //printf(">> D++ | ERROR (dpp.amx @ %s:%i): %s",__file,__line,%1)

#define dpp_warning%0(%1,%2) format(dpp_error_str,sizeof dpp_error_str,"[PawnScript] WARNING (dpp.amx @ %s:%i): "%1,__file,__line,%2)&& \
    print(dpp_error_str)&&dpp_incwarncnt()


stock dpp_incerrcnt()
{
    dpp_errorcount++;
    return 1;
}

stock dpp_incwarncnt()
{
    dpp_warningcount++;
    return 1;
}

stock dpp_parsecode(const code[], destln[][])
{
    new 
        i, 
        start,
        index,
        len;

    // Lets assume code = "decl::end;"

    while(i <= strlen(code)) // do this down there while 'i' is smaller than length of "decl::end;"
    {
        /*if(strcmp(code, "{")) // if at certain point i reaches the ';' char, or it reaches the end,then:
        {
            len = strmid(destln[index], "{", start, i, 128); // store "decl::end" without a ';' into destln 
            destln[index][len] = 0; // clear the last char
            start = i+1; // set start to be for 1 bigger
            index++; // set an index to be for  1 bigger
        }
        if(strcmp(code, "}")) // if at certain point i reaches the ';' char, or it reaches the end,then:
        {
            len = strmid(destln[index], "}", start, i, 128); // store "decl::end" without a ';' into destln 
            destln[index][len] = 0; // clear the last char
            start = i+1; // set start to be for 1 bigger
            index++; // set an index to be for  1 bigger
        }*/

        if(code[i] == ';' || i == strlen(code)) // if at certain point i reaches the ';' char, or it reaches the end,then:
        {
            len = strmid(destln[index], code, start, i, 128); // store "decl::end" without a ';' into destln 
            destln[index][len] = 0; // clear the last char
            start = i+1; // set start to be for 1 bigger
            index++; // set an index to be for  1 bigger
        }
        i++;
        
        if(strlen(code) != 0)
        {
            dpp_debug("Parsecode backtrace:\n\tcode: '%s'\n\ti: %i\n\tstart: %i\n\tindex: %i\n\tlen: %i\n\tdestln[%i]: '%s'\n\tlen (destln[%i]): %i",code,i,start,index,len,index,destln[index],index,strlen(destln[index]));
        }
    }
    return 1;
}

stock dpp_parseline(const code[], destln[][], delimiter)
{
    new 
        i, 
        start,
        index,
        len;

    while(i <= strlen(code))
    {
        if((code[i+1] != delimiter && code[i-1] != dpp_option_escapechar && code[i] == delimiter) || i == strlen(code))
        {
            len = strmid(destln[index], code, start, i, 128);
            destln[index][len] = 0;
            start = i+1;
            index++;
        }
        i++;
    }
    return 1;
}

stock dpp_parseline_2(const code[], destln[][], const delimiter[])
{
    if(strlen(delimiter) != 2)
    {
        dpp_error("Parse error; delimiter isn't 2 chars long.",);
        return 1;
    }
    new 
        i, 
        start,
        index,
        len;

    while(i <= strlen(code))
    {
        if((code[i] == delimiter[0] && code[i+1] == delimiter[1]) || i == strlen(code))
        {
            len = strmid(destln[index], code, start, i, 128);
            destln[index][len] = 0;
            destln[index][len+1] = 0;
            start = i+2;
            index++;
        }
        i++;
    }
    return 1;
}

stock dpp_removeslashes(arg[])
{
    for(new i; i < strlen(arg); i++)
    {
        if(arg[i] == dpp_option_escapechar) strdel(arg, i,i+1);
    }
    return 1;
}

stock dpp_checkforconditionals(const code[], dest1[], dest2[], const delimiter[])
{
    new
        delimiter_start,
        delimiter_end;
    
    for(new i; i < strlen(code); i++)
    {
        if(code[i] == delimiter[0] && code[i+1] == delimiter[1])
        {
            dpp_isconditional = 1;
            delimiter_start = i;
            delimiter_end = i+1;
            strmid(dest1, code, 0, delimiter_start, 3000);
            strmid(dest2, code, delimiter_end+1, strlen(code), 3000);

            // strmid(dest[], const source[], start, end, maxlength=sizeof dest)

            dpp_debug("Code : \"%s\" was split into destln1 : \"%s\" and destln2 : \"%s\"",code,dest1,dest2);
            return 1;
        }
    }
    return 1;
}

stock dpp_checkforobjinit(const code[], dest1[], dest2[], const delimiter[])
{
    new
        delimiter_start,
        delimiter_end;
    
    for(new i; i < strlen(code); i++)
    {
        if(code[i] == delimiter[0] && code[i+1] == delimiter[1])
        {
            dpp_isobjinit = 1;
            delimiter_start = i;
            delimiter_end = i+1;
            strmid(dest1, code, 0, delimiter_start, 3000);
            strmid(dest2, code, delimiter_end+1, strlen(code), 3000);

            // strmid(dest[], const source[], start, end, maxlength=sizeof dest)

            dpp_debug("Code : \"%s\" was split into destln1 : \"%s\" and destln2 : \"%s\"",code,dest1,dest2);
            return 1;
        }
    }
    return 1;
}

stock dpp_cwlu(const constargs[], modargs[])
{
    strmid(modargs, constargs, 0, dpp_argcharsize, dpp_argcharsize);

    dpp_removeslashes(modargs);
    dpp_argclasscheck(modargs);
    dpp_argarraycheck(modargs);
    dpp_argfunccheck(modargs);
    dpp_argvarcheck(modargs);
    dpp_argmathcheck(modargs);
    dpp_argformargcheck(modargs);

    dpp_formatarg(modargs);
    return 1;
}

stock dpp_extract(const src[], dest[], startchar, endchar)
{
    new
        start,
        end;

    for(new i; i < strlen(src); i++)
    {
        if(src[i] == startchar) start = i;
        if(src[i] == endchar) end = i;
    }

    strmid(dest, src, start, end, strlen(src));
    dpp_debug("Extracted : \"%s\"",dest);
    return 1;
}

stock dpp_deletespaces(line[])
{
    new firstcommapos;
    for(new i; i < strlen(line); i++)
    {
        if(line[i] == ',')
        {
            firstcommapos = i;
            break;
        }
    }
    for(new i; i < firstcommapos+1; i++)
    {
        if(line[i] == ' ')
        {
            strdel(line, i, i+1);
        }
    }
    for(new i; i < strlen(line); i++)
    {
        if(line[i-2] != dpp_option_escapechar && line[i-1] == ',' && line[i] == ' ')
        {
            strdel(line, i, i+1);
        } 
        if(line[i-2] != dpp_option_escapechar && line[i-1] == ',' && line[i] == '\t')
        {
            strdel(line, i, i+1);
        } 
    }
    return 1;
}

stock dpp_delexcspaces(arg[])
{
    for(new i; i < strlen(arg)+1; i++)
    {
        if(arg[strlen(arg)] == ' ')
        {
            strdel(arg, i, i+1);
        }
    }
    return 1;
}

stock dpp_deletefunc(const name[])
{
    for(new i; i < dpp_maxfuncs; i++)
    {
        if(!strcmp(dpp_funcname[i], name))
        {
            if(dpp_hookform[i] != 1 && dpp_validfunc[i] == 1)
            {
                dpp_validfunc[i] = 0;
            }
        }
    }
    return 1;
}

stock dpp_createfunc(funcname[], const args[], autoform = 0, hookform = 0, struct = dpp_formstruct_local, method = 0, ret = dpp_rtn_type_void)
{
    if(dpp_workingclassid != dpp_invalidclass)
    {
        new newvalue[dpp_argcharsize];
        format(newvalue,sizeof(newvalue),"DPPCf@%s_%s",dpp_classname[dpp_workingclassid],funcname);
        strmid(funcname, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
    }
    new dpp_formcount;
    for(new i; i < dpp_maxfuncs; i++)
    {
        if(dpp_validfunc[i] == 0)
        {
            if(hookform == 1)
            {
                dpp_hookform[i] = 1;
            }
            if(autoform == 1)
            {
                dpp_autoform[i] = 1;
            }

            dpp_currentfuncid = i;
            dpp_validfunc[i] = 1;
            dpp_structtype[i] = struct;
            dpp_methodform[i] = method;

            dpp_returntype[i] = ret;

            for(new y; y < dpp_maxfuncs; y++)
            {
                if(!strcmp(dpp_funcname[y], funcname))
                {
                    if(dpp_validfunc[y] == 1 && dpp_hookform[y] == 0)
                    {
                        dpp_formcount++;
                    }
                }
            }

            if(dpp_formcount > 1)
            {
                dpp_warning("There are multiple forms with name \"%s\" created.",funcname);
            }

            new formargs[dpp_maxformargs][100];
            dpp_parseline(args,formargs,'&');

            for(new argid; argid < dpp_maxformargs; argid++)
            {
                strmid(dpp_args[i][argid][dpp_argname],formargs[argid],0,100,100);
            }

            strmid(dpp_funcname[i], funcname, 0, 64);
            dpp_debug("funcgroup[1]:%s",funcname);
            dpp_debug("dpp_funcname[i]:%s",dpp_funcname[i]);
            dpp_debug("dpp_currentfuncid:%i",dpp_currentfuncid);
            return 1;
        }
    }
    return 1;
}
/*
stock dpp_execute(const script[])
{
    new content[dpp_maxstrsize*DPP_CELLMAX];
    print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("         Interpreter is loading...      ");
    print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("                                        ");
    //dpp_print("Interpreter version %i.%i.%i-R%i - by: DEntisT",DPP_VERSION_MAJOR,DPP_VERSION_MINOR,DPP_VERSION_PATCH,DPP_VERSION_RELEASE);
    #if DPP_DEBUG == 1
    dpp_print("Debug component loaded...");
    #endif
    dpp_nullcomment();
    dpp_prepareproject("config.dppproj");
    dpp_print("Project file for '%s' project loaded.",dpp_projname);
    dpp_print("Executing the entry script...");
    dpp_nullcomment();
    dpp_execheader("index.dppc");
    dpp_nullcomment();

    new File:file = fopen(script, io_read);
    if(file)
    {
        while(fread(file, content))
        {
            dpp_codetrim(content, .edge = edge_right);
            new split_buffer[dpp_buffersize][dpp_buffersize];
            dpp_parseline(content, split_buffer, ';');
            for(new i; i < dpp_buffersize; i++)
            {
                dpp_process(split_buffer[i]);
            }
        }
        CallLocalFunction("DPP_ENTRYPOINT", "");
    }

    else if(!file)
    {
        dpp_error("Invalid file.",);
    }
    return 1;
}
*/


stock dpp_processbraces(line[])
{
    dpp_codetrim(line);

    if(line[0] == '<')
    {
        dpp_workingclassid = dpp_lastclass;
        return 1;
    }

    if(line[0] == '>')
    {
        dpp_workingclassid = dpp_invalidclass;
        return 1;
    }

    if(line[0] == '}')
    {
        if(dpp_event == dpp_event_form)
        {
            dpp_sysreturned = 0;
            dpp_currentfuncid = DPP_INVALID_FORM_ID;
            //dpp_processfunc = DPP_INVALID_FORM_ID;
            dpp_interpreter = 1;
        }
        if(dpp_event == dpp_event_task)
        {
            dpp_currenttaskid = DPP_INVALID_TASK_ID;
            dpp_taskinterpreter = 1;
        }
        if(dpp_event == dpp_event_enum)
        {
            dpp_currentenumid = DPP_INVALID_ENUM_ID;
            dpp_enuminterpreter = 1;
        }
        return 1;
    }

    if(line[0] == '{')
    {
        if(dpp_event == dpp_event_form)
        {
            dpp_interpreter = 0;
            //dpp_processfunc = dpp_currentfuncid;
        }
        if(dpp_event == dpp_event_task)
        {
            dpp_taskinterpreter = 0;
        }
        if(dpp_event == dpp_event_enum)
        {
            dpp_enuminterpreter = 0;
        }
        return 1;
    }
    return 0;
}


stock dpp_execute(const script[])
{
    dpp_prepareproject("config.psproj");
    dpp_print("Executing project: '%s'",dpp_projname);
    new content[16000];
    format(content,sizeof content, "\t");
    /*print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("         Interpreter is loading...      ");
    print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("                                        ");
    //dpp_print("Interpreter version %i.%i.%i-R%i - by: DEntisT",DPP_VERSION_MAJOR,DPP_VERSION_MINOR,DPP_VERSION_PATCH,DPP_VERSION_RELEASE);
    #if DPP_DEBUG == 1
    dpp_print("Debug component loaded...");
    #endif
    dpp_nullcomment();
    dpp_print("Project file for '%s' project loaded.",dpp_projname);
    dpp_print("Executing the entry script...");
    dpp_nullcomment();
    dpp_execheader("index.dppc");
    dpp_nullcomment();*/

    new File:file = fopen(script, io_read), rlen;
    new codelines[dpp_maxcodelines][1024];
    if(file)
    {
        while(rlen = fread(file, content))
        {
            dpp_codetrim(content);
            for(new i; i < strlen(content); i++)
            {
                if(content[i] == ';' && content[i+1] == ' ') strdel(content, i+1, i+2);
                //if(content[i] == '\t') strdel(content, i, i+1);
                //if(content[i] == '\n') strdel(content, i, i+1);
            }
            dpp_debug("content: '%s'", content);
            dpp_parsecode(content, codelines);
            //dpp_debug("Executing:\n\n%s", content);
            for(new i; i < dpp_maxcodelines; i++)
            {
                if(!isnull(codelines[i])) dpp_debug("codelines[%i]: '%s'",i, codelines[i]);
                if(dpp_terminated == 1)
                {
                    break;
                }
                dpp_processbraces(content);
                dpp_process(codelines[i]);
            }
        }
        CallLocalFunction("DPP_ENTRYPOINT", "");
    }

    else if(!file)
    {
        dpp_error("Invalid file.",);
    }
    return 1;
}


stock dpp_executefile(const script[])
{
    new File:file = fopen(script, io_read), rlen;
    new codelines[dpp_maxcodelines][1024];
    if(file)
    {
        while(rlen = fread(file, content))
        {
            dpp_codetrim(content);
            for(new i; i < strlen(content); i++)
            {
                if(content[i] == ';' && content[i+1] == ' ') strdel(content, i+1, i+2);
                //if(content[i] == '\t') strdel(content, i, i+1);
                //if(content[i] == '\n') strdel(content, i, i+1);
            }
            dpp_debug("content: '%s'", content);
            dpp_parsecode(content, codelines);
            //dpp_debug("Executing:\n\n%s", content);
            for(new i; i < dpp_maxcodelines; i++)
            {
                if(!isnull(codelines[i])) dpp_debug("codelines[%i]: '%s'",i, codelines[i]);
                if(dpp_terminated == 1)
                {
                    break;
                }
                dpp_process(codelines[i]);
            }
        }
        CallLocalFunction("DPP_ENTRYPOINT", "");
    }

    else if(!file)
    {
        dpp_error("Invalid file.",);
    }
    return 1;
}

stock dpp_subexecute(const code[], funcid = -1)
{
    #pragma unused funcid
    new __codelines[1024][1024];

    dpp_parsecode(code, __codelines);
    //dpp_debug("Executing:\n\n%s", code);
    for(new i; i < 1024; i++)
    {
        if(funcid != -1)
        {
            if(dpp_returned[funcid] == 1) return 1;
        }
        dpp_codetrim(__codelines[i]);
        dpp_subprocess(__codelines[i]);
    }
    return 1;
}

stock dpp_subexecute2(const code[])
{
    new __codelines[1024][1024];

    dpp_parsecode(code, __codelines);
    //dpp_debug("Executing:\n\n%s", code);
    for(new i; i < 1024; i++)
    {
        dpp_subprocess(__codelines[i]);
    }
    return 1;
}
////////////////////////////////////////////////


stock dpp_createtask(const name[], interval)
{
    for(new i; i < dpp_maxtasks; i++)
    {
        if(dpp_validtask[i] != 1)
        {
            dpp_currenttaskid = i;
            dpp_validtask[i] = 1;
            strmid(dpp_taskname[i], name, 0, 64, 64);
            dpp_interval[i] = interval;
            return 1;
        }
    }
    return 0;
}

////////////////////////////////////////////////
stock dpp_argsystemval(arg[])
{
    new newvalue[dpp_argcharsize];
    if(!strcmp(arg, "__proccessed_form_id"))
    {
        format(newvalue, sizeof newvalue, "%i", dpp_processfunc);
        strmid(arg, newvalue, 0, dpp_argcharsize, dpp_argcharsize);
    }
    if(!strcmp(arg, "__majorver"))
    {
        format(newvalue, sizeof newvalue, "%i", DPP_VERSION_MAJOR);
        strmid(arg, newvalue, 0, dpp_argcharsize, dpp_argcharsize);
    }
    if(!strcmp(arg, "__minorver"))
    {
        format(newvalue, sizeof newvalue, "%i", DPP_VERSION_MINOR);
        strmid(arg, newvalue, 0, dpp_argcharsize, dpp_argcharsize);
    }
    if(!strcmp(arg, "__patch"))
    {
        format(newvalue, sizeof newvalue, "%i", DPP_VERSION_PATCH);
        strmid(arg, newvalue, 0, dpp_argcharsize, dpp_argcharsize);
    }
    if(!strcmp(arg, "__release"))
    {
        format(newvalue, sizeof newvalue, "%i", DPP_VERSION_RELEASE);
        strmid(arg, newvalue, 0, dpp_argcharsize, dpp_argcharsize);
    }
    if(!strcmp(arg, "__beta"))
    {
        format(newvalue, sizeof newvalue, "%i", DPP_VERSION_BETA);
        strmid(arg, newvalue, 0, dpp_argcharsize, dpp_argcharsize);
    }    
    return 1;
}
///////////////////
dpp_arginstruct(arg[]); public dpp_arginstruct(arg[])
{
    new 
        symbolid = -1,
        newvalue[dpp_argcharsize],
        operands[2][dpp_maxsymbolchar];

    dpp_parseline(arg,operands,'?');
    if(!strcmp(operands[0], "sizeof"))
    {
        for(new i; i < dpp_maxiter; i++)
        {
            if(!strcmp(operands[1], dpp_itername[i]))
            {
                if(dpp_validiter[i] == 1)
                {
                    symbolid = i;
                    break;
                }
            }
        }
        if(symbolid == -1) return 1;
        format(newvalue, sizeof newvalue, "%i", dpp_itersize[symbolid]);
        strmid(arg, newvalue, 0, dpp_argcharsize, dpp_argcharsize);
    }

    if(!strcmp(operands[0], "defined"))
    {
        dpp_argclasscheck(operands[1]);
        
        for(new i; i < dpp_maxiter; i++)
        {
            if(!strcmp(operands[1], dpp_itername[i]))
            {
                if(dpp_validiter[i] == 1)
                {
                    symbolid = i;
                    break;
                }
            }
        }

        for(new i; i < dpp_maxfuncs; i++)
        {
            if(!strcmp(operands[1], dpp_funcname[i]))
            {
                if(dpp_validfunc[i] == 1)
                {
                    symbolid = i;
                    break;
                }
            }
        }

        for(new i; i < dpp_maxvar; i++)
        {
            if(!strcmp(operands[1], dpp_vardata[i][var_name]))
            {
                if(dpp_vardata[i][var_valid] == 1)
                {
                    symbolid = i;
                    break;
                }
            }
        }

        for(new i; i < dpp_maxconst; i++)
        {
            if(!strcmp(operands[1], dpp_constdata[i][const_name]))
            {
                if(dpp_constdata[i][const_valid] == 1)
                {
                    symbolid = i;
                    break;
                }
            }
        }

        if(symbolid == -1)
        {
            format(newvalue, sizeof newvalue, "0");
        }
        else
        {
            format(newvalue, sizeof newvalue, "1");
        }
        strmid(arg, newvalue, 0, dpp_argcharsize, dpp_argcharsize);
    }
    return 1;
}
///////////////FUNC CALLING/////////////////////
stock dpp_argfunccheck(arg[])
{
    new newvalue[dpp_argcharsize];
    for(new i; i < dpp_maxfuncs; i++)
    {
        if(!strcmp(dpp_funcname[i], arg))
        {
            if(dpp_validfunc[i] == 1)
            {
                if(dpp_hookform[i] == 0)
                {
                    /*for(new argid; argid < dpp_maxformargs; argid++)
                    {
                        strmid(dpp_args[i][argid][dpp_argvalue],
                            args[argid+1],
                            0,
                            dpp_argcharsize,
                            dpp_argcharsize);
                    }*/
                    dpp_returned[i] = 0;
                    dpp_processfunc = i;
                    dpp_subexecute(dpp_funccodeblock[i], i);
                    dpp_debug("dpp_funccodeblock[i]:%s",dpp_funccodeblock[i]);

                    if(dpp_option_hooking == 1)
                    {
                        for(new hookfuncid; hookfuncid < dpp_maxfuncs; hookfuncid++)
                        {
                            if(!strcmp(dpp_funcname[hookfuncid], arg))
                            {
                                if(dpp_hookform[hookfuncid] == 1)
                                {
                                    /*for(new argid; argid < dpp_maxformargs; argid++)
                                    {
                                        strmid(dpp_args[hookfuncid][argid][dpp_argname],
                                            dpp_args[i][argid][dpp_argname],
                                            0,
                                            dpp_argcharsize,
                                            dpp_argcharsize);
                                        strmid(dpp_args[hookfuncid][argid][dpp_argvalue],
                                            args[argid+1],
                                            0,
                                            dpp_argcharsize,
                                            dpp_argcharsize);
                                    }*/
                                    dpp_returned[hookfuncid] = 0;
                                    dpp_processfunc = hookfuncid;
                                    dpp_subexecute(dpp_funccodeblock[hookfuncid], hookfuncid);
                                    dpp_debug("dpp_funccodeblock[hookfuncid]:%s",dpp_funccodeblock[hookfuncid]);
                                }
                            }
                        }
                    }
                }

                dpp_processfunc = DPP_INVALID_FORM_ID;
                dpp_clearformstack(dpp_processfunc); dpp_processfunc = DPP_INVALID_FORM_ID;
                /////////////////////////////////////

                if(dpp_returntype[i] == dpp_rtn_type_int)
                {
                    format(newvalue, dpp_argcharsize, "%i", 
                        dpp_funcreturn_int[i]);
                }
                if(dpp_returntype[i] == dpp_rtn_type_bool)
                {
                    if(dpp_funcreturn_bool[i] == 1)
                    {
                        strmid(arg, "true", 0, dpp_argcharsize, dpp_argcharsize);
                    }
                    if(dpp_funcreturn_bool[i] == 0)
                    {
                        strmid(arg, "false", 0, dpp_argcharsize, dpp_argcharsize);
                    }
                }
                if(dpp_returntype[i] == dpp_rtn_type_str)
                {
                    format(newvalue, dpp_argcharsize, "\"%s\"", 
                        dpp_funcreturn_str[i]);
                }
                if(dpp_returntype[i] == dpp_rtn_type_double)
                {
                    format(newvalue, dpp_argcharsize, "%f", 
                        dpp_funcreturn_double[i]);
                }
                if(dpp_returntype[i] == dpp_rtn_type_char)
                {
                    format(newvalue, dpp_argcharsize, "'%c'", 
                        dpp_funcreturn_char[i]);
                }
                
                if(dpp_returntype[i] != dpp_rtn_type_bool)
                {
                    strmid(arg, newvalue, 0, dpp_argcharsize, dpp_argcharsize);
                }
                return 1;
            }
        }
    }
    return 1;
}

// system autoforms

DPP_ENTRYPOINT();
public DPP_ENTRYPOINT()
{
    if(dpp_config[system_comp] == 0)
    {
        return 1;
    }
    
    for(new i; i < dpp_maxfuncs; i++)
    {
        if(!strcmp(dpp_funcname[i], "main"))
        {
            if(dpp_autoform[i] == 0) return 1;
            if(dpp_hookform[i] == 0)
            {
                dpp_processfunc = i;
                dpp_subexecute(dpp_funccodeblock[i],i);
                dpp_debug("dpp_funccodeblock[i]:%s",dpp_funccodeblock[i]);
                dpp_debug("\"main\" called.");

                if(dpp_option_hooking == 1)
                {
                    for(new hookfuncid; hookfuncid < dpp_maxfuncs; hookfuncid++)
                    {
                        if(!strcmp(dpp_funcname[hookfuncid], "main"))
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

// stack output

stock void:dpp_savelog(const file[],const message[]) 
{
    new formatted_message[ 256 ], 
        second, 
        minutes, 
        day2, 
        day, 
        year, 
        month;

    getdate(year, month, day);

    gettime(second, minutes, day2);
    
    format(formatted_message, 
        sizeof formatted_message, 
        "%d:%d:%d | %d:%d:%d @ >> [PawnScript] | LOG: %s\r\n ", 
        day, month, year, 
        second, minutes, day2, message);

    new File:LogFile = fopen(file, io_append);

    fwrite(LogFile, formatted_message);

    fclose(LogFile);
}

//////////

stock dpp_argformargcheck(arg[])
{
    //i.e., playerid@OnPlayerConnect
    new newvalue[dpp_argcharsize];
    new 
        systemarg[2][128],
        formvalid = 0,
        formid = 0,
        argvalid = 0,
        argid = 0;

    dpp_parseline(arg,systemarg,'@');

    dpp_argclasscheck(systemarg[1]);

    for(new i; i < dpp_maxfuncs; i++)
    {
        if(!strcmp(dpp_funcname[i],systemarg[1]))
        {
            if(dpp_validfunc[i] == 1 && dpp_hookform[i] == 0)
            {
                formvalid = 1;
                formid = i;
                break;
            }
        }
    }

    if(formvalid == 1)
    {
        for(new i; i < dpp_maxformargs; i++)
        {
            if(!strcmp(dpp_args[formid][i][dpp_argname],systemarg[0]))
            {
                argid = i;
                argvalid = 1;
                break;
            }
        }
    }

    if(formvalid == 1 && argvalid == 1)
    {
        format(newvalue,sizeof newvalue,"%s",dpp_args[formid][argid][dpp_argvalue]);

        strmid(arg, newvalue, 0, dpp_argcharsize,dpp_argcharsize);
    }
    return 1;
}

///////////////////////////////////////

dpp_formatcheck(arg[],replacement[]); public dpp_formatcheck(arg[],replacement[])
{
    //i.e., playerid@OnPlayerConnect
    new 
        systemarg[2][128],
        formvalid = 0,
        formid = 0,
        argvalid = 0,
        argid = 0;

    dpp_parseline(arg,systemarg,'@');
    
    dpp_argclasscheck(systemarg[1]);

    for(new i; i < dpp_maxfuncs; i++)
    {
        if(!strcmp(dpp_funcname[i],systemarg[1]))
        {
            if(dpp_validfunc[i] == 1 && dpp_hookform[i] == 0)
            {
                formvalid = 1;
                formid = i;
                break;
            }
        }
    }

    if(formvalid == 1)
    {
        for(new i; i < dpp_maxformargs; i++)
        {
            if(!strcmp(dpp_args[formid][i][dpp_argname],systemarg[0]))
            {
                argid = i;
                argvalid = 1;
                break;
            }
        }
    }

    if(formvalid == 1 && argvalid == 1)
    {
        format(replacement,dpp_argcharsize,"%s",dpp_args[formid][argid][dpp_argvalue]);

        strmid(arg, replacement, 0, dpp_argcharsize,dpp_argcharsize);

        return 1;
    }
    return 0;
}

//methods

dpp_callmethod(funcgroup[][],args[][],args_const[][]); 
public dpp_callmethod(funcgroup[][],args[][],args_const[][])
{
    if(isnull(funcgroup[2]))
    {
        return 1;
    }
    dpp_argclasscheck(funcgroup[2]);
    for(new i; i < dpp_maxfuncs; i++)
    {
        if(!strcmp(dpp_funcname[i], funcgroup[2]))
        {
            if(dpp_methodform[i] == 0)
            {
                dpp_error("Unknown form method.",);
                return 1;
            } 
            if(dpp_hookform[i] == 0)
            {
                for(new argid; argid < dpp_maxformargs; argid++)
                {
                    strmid(dpp_args[i][argid][dpp_argvalue],
                        args[argid],
                        0,
                        dpp_argcharsize,
                        dpp_argcharsize);
                }
                dpp_returned[i] = 0;
                dpp_processfunc = i;
                dpp_subexecute(dpp_funccodeblock[i], i);
                dpp_debug("dpp_funccodeblock[i]:%s",dpp_funccodeblock[i]);

                if(dpp_option_hooking == 1)
                {
                    for(new hookfuncid; hookfuncid < dpp_maxfuncs; hookfuncid++)
                    {
                        if(!strcmp(dpp_funcname[hookfuncid], funcgroup[2]))
                        {
                            if(dpp_hookform[hookfuncid] == 1)
                            {
                                for(new argid; argid < dpp_maxformargs; argid++)
                                {
                                    /*strmid(dpp_args[hookfuncid][argid][dpp_argname],
                                        dpp_args[i][argid][dpp_argname],
                                        0,
                                        dpp_argcharsize,
                                        dpp_argcharsize);*/
                                    strmid(dpp_args[hookfuncid][argid][dpp_argvalue],
                                        args[argid],
                                        0,
                                        dpp_argcharsize,
                                        dpp_argcharsize);
                                }
                                dpp_processfunc = hookfuncid;
                                dpp_subexecute(dpp_funccodeblock[hookfuncid], hookfuncid);
                                dpp_debug("dpp_funccodeblock[hookfuncid]:%s",dpp_funccodeblock[hookfuncid]);
                            }
                        }
                    }
                }
                dpp_clearformstack(dpp_processfunc); dpp_processfunc = DPP_INVALID_FORM_ID;
                return 1;
            }
        }
    }
    return 1;
}

// for apis

forward dpp_callform(external_form[]);
public dpp_callform(external_form[])
{
    for(new i; i < dpp_maxfuncs; i++)
    {
        if(!strcmp(dpp_funcname[i], external_form))
        {
            if(dpp_autoform[i] == 0) return 1;
            dpp_processfunc = i;
            dpp_subexecute(dpp_funccodeblock[i],i);
     
            if(dpp_hookform[i] == 0)
            {
                if(dpp_option_hooking == 1)
                {
                    for(new hookfuncid; hookfuncid < dpp_maxfuncs; hookfuncid++)
                    {
                        if(!strcmp(dpp_funcname[hookfuncid], external_form))
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
