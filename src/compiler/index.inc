/*
*
* D++ Scripting Language
*     Made for a SA:MP server
*
* Compiling System Entry point
*
* 
* - by: DEntisT, (c) 2022
*
*/

stock void:dpp_writecompileddata(const file[],const data[]) 
{
    new 
        File:LogFile = fopen(file, io_append), 
        fixed_data[dpp_maxstrsize*DPP_CELLMAX];

    format(fixed_data, sizeof fixed_data, "%s", data);

    fwrite(LogFile, fixed_data);

    fclose(LogFile);
}
/*
stock dpp_compile(const script[])
{
    new content[dpp_maxstrsize*DPP_CELLMAX];
    print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("                   D++                  ");
    print("         Compiler is loading...         ");
    print("                                        ");
    printf("         Version: %i.%i.%i-R%i         ", DPP_VERSION_MAJOR,DPP_VERSION_MINOR,DPP_VERSION_PATCH,DPP_VERSION_RELEASE);
    print("                                        ");
    print("               By: DEntisT              ");
    print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("                                        ");

    if(fexist("index.dppc")) fremove("index.dppc");

    dpp_print("Compiling \"%s\"...",script);
    print("                                        ");
    print("                                        ");
    dpp_compilerprint("Going through the 1st compiler pass.");
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
    }

    else if(!file)
    {
        dpp_error("Invalid file.",);
        return 1;
    }
    


    dpp_compiled = 1;
    dpp_compiling_pass = 2;


    dpp_compilerprint("Going through the 2nd compiler pass.");
    file = fopen("index.dppc", io_read);
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
    }

    dpp_compiling_pass = 3;
    dpp_isobjinit = 0;
    dpp_isconditional = 0;

    dpp_nullcomment();
    print("                                        ");
    print("                                        ");
    dpp_print("File \"%s\" and imported modules compiled successfully.",script);
    print("                                        ");
    print("                                        ");
    return 1;
}
*/

stock dpp_compile(const script[])
{
    print("                                        ");
    new content[16000];
    printf("\tPawnScript   %i.%i.%i-R%i\t\tBraceTM Inc.", DPP_VERSION_MAJOR,DPP_VERSION_MINOR,DPP_VERSION_PATCH,DPP_VERSION_RELEASE);
    //dpp_print("Interpreter version %i.%i.%i-R%i - by: DEntisT",DPP_VERSION_MAJOR,DPP_VERSION_MINOR,DPP_VERSION_PATCH,DPP_VERSION_RELEASE);
    if(fexist("index.dppc")) fremove("index.dppc");
    //dpp_print("Compiling \"%s\"...",script);
    print("                                        ");
    print("                                        ");
    //dpp_compilerprint("Going through the 1st compiler pass.");
    new File:file = fopen(script, io_read), rlen;
    //new codelines[dpp_maxcodelines][1024];
    if(file)
    {
        while(rlen = fread(file, content))
        {
            for(new i; i < strlen(content); i++)
            {
                //if(content[i] == ';' && content[i+1] == ' ') strdel(content, i+1, i+2);
                if(content[i] == '\t') strdel(content, i, i+1);
                if(content[i] == '\n') strdel(content, i, i+1);
            }
            dpp_debug("content: '%s'", content);
            //dpp_parsecode(content, codelines);
            //dpp_debug("Executing:\n\n%s", content);
            //dpp_writecompileddata("index.dppc", content);
            //dpp_process(content);
        }
    }

    else if(!file)
    {
        dpp_error("Invalid file.",);
        return 1;
    }
    


    dpp_compiled = 1;
    dpp_compiling_pass = 2;


    //dpp_compilerprint("Going through the 2nd compiler pass.");
    file = fopen("index.dppc", io_read);
    new rlen2;
    new codelines[dpp_maxcodelines][1024];
    if(file)
    {
        while(rlen2 = fread(file, content))
        {
            /*for(new i; i < strlen(content); i++)
            {
                if(content[i] == ';' && content[i+1] == ' ') strdel(content, i+1, i+2);
                if(content[i] == '\t') strdel(content, i, i+1);
                if(content[i] == '\n') strdel(content, i, i+1);
            }*/
            dpp_debug("content: '%s'", content);
            dpp_parsecode(content, codelines);
            //dpp_debug("Executing:\n\n%s", content);
            for(new i; i < dpp_maxcodelines; i++)
            {
                if(!isnull(codelines[i])) dpp_debug("codelines[%i]: '%s'",i, codelines[i]);
                //dpp_process(codelines[i]);
            }
        }
    }

    dpp_compiling_pass = 3;
    dpp_isobjinit = 0;
    dpp_isconditional = 0;

    //dpp_print("File \"%s\" and imported modules compiled successfully.",script);
    return 1;
}

/*
stock dpp_compilemodule(const script[], const dest[])
{
    //dpp_print("Compiling module: \"%s\"",script);
    if(fexist(script)) fremove(script);
    new File:file = fopen(script, io_read), rlen;
    //new codelines[dpp_maxcodelines][1024];
    if(file)
    {
        while(rlen = fread(file, content))
        {
            for(new i; i < strlen(content); i++)
            {
                //if(content[i] == ';' && content[i+1] == ' ') strdel(content, i+1, i+2);
                if(content[i] == '\t') strdel(content, i, i+1);
                if(content[i] == '\n') content[i] = ';'; //strdel(content, i, i+1);
            }
            dpp_debug("content: '%s'", content);
            //dpp_parsecode(content, codelines);
            //dpp_debug("Executing:\n\n%s", content);
            //dpp_writecompileddata("index.dppc", content);
            dpp_writecompileddata(dest, content);
        }
    }

    else if(!file)
    {
        dpp_error("Invalid file.",);
        return 1;
    }
    return 1;
}
*/

stock dpp_formatarg(argument[]) // creds DEntisT
{
    if(!dpp_isargstr(argument))
    {
        return 1;
    }
    new 
        start=-1,
        end=-1,
        len = strlen(argument),
        symbolname[64],
        replacementname[64],
        varvalid = 0,
        constvalid = 0,
        argvalid = 0,
        replacement[dpp_maxformatlen],
        newvalue[dpp_maxformatlen];

    for(new i; i < len; i++)
    {
        if(argument[i] == '{') start = i;
        if(argument[i] == '}') end = i;
    }

    strmid(symbolname, argument, start+1, end);
    strmid(replacementname, argument, start, end+1);

    dpp_argclasscheck(symbolname);
    dpp_argoclasscheck(symbolname);

    for(new i; i < dpp_maxvar; i++)
    {
        if(!strcmp(dpp_vardata[i][var_name], symbolname))
        {
            if(dpp_vardata[i][var_valid] == 1)
            {
                if(dpp_vardata[i][var_type] == dpp_var_type_int)
                {
                    format(newvalue, dpp_argcharsize, "%i", 
                        dpp_vardata[i][integervalue]);
                }
                if(dpp_vardata[i][var_type] == dpp_var_type_bool)
                {
                    if(dpp_vardata[i][boolvalue] == 1)
                    {
                        strmid(replacement, "true", 0, dpp_argcharsize, dpp_argcharsize);
                    }
                    if(dpp_vardata[i][boolvalue] == 0)
                    {
                        strmid(replacement, "false", 0, dpp_argcharsize, dpp_argcharsize);
                    }
                }
                if(dpp_vardata[i][var_type] == dpp_var_type_str)
                {
                    format(newvalue, dpp_argcharsize, "\"%s\"", 
                        dpp_vardata[i][stringvalue]);
                }
                if(dpp_vardata[i][var_type] == dpp_var_type_double)
                {
                    format(newvalue, dpp_argcharsize, "%f", 
                        dpp_vardata[i][floatvalue]);
                }
                if(dpp_vardata[i][var_type] == dpp_var_type_char)
                {
                    format(newvalue, dpp_argcharsize, "'%c'", 
                        dpp_vardata[i][charvalue]);
                }

                if(dpp_vardata[i][var_type] != dpp_var_type_bool)
                {
                    strmid(replacement, newvalue, 0, dpp_argcharsize, dpp_argcharsize);
                }
                varvalid = 1;
                break;
            }
        }
    }

    for(new i; i < dpp_maxconst; i++)
    {
        if(!strcmp(dpp_constdata[i][const_name], symbolname))
        {
            if(dpp_constdata[i][const_valid] == 1)
            {
                if(dpp_constdata[i][const_type] == dpp_const_type_int)
                {
                    format(newvalue, dpp_argcharsize, "%i", 
                        dpp_constdata[i][integervalue]);
                }
                if(dpp_constdata[i][const_type] == dpp_const_type_bool)
                {
                    if(dpp_constdata[i][boolvalue] == 1)
                    {
                        strmid(replacement, "true", 0, dpp_argcharsize, dpp_argcharsize);
                    }
                    if(dpp_constdata[i][boolvalue] == 0)
                    {
                        strmid(replacement, "false", 0, dpp_argcharsize, dpp_argcharsize);
                    }
                }
                if(dpp_constdata[i][const_type] == dpp_const_type_str)
                {
                    format(newvalue, dpp_argcharsize, "\"%s\"", 
                        dpp_constdata[i][stringvalue]);
                }

                if(dpp_constdata[i][const_type] == dpp_const_type_double)
                {
                    format(newvalue, dpp_argcharsize, "%f", 
                        dpp_constdata[i][floatvalue]);
                }

                if(dpp_constdata[i][const_type] == dpp_const_type_char)
                {
                    format(newvalue, dpp_argcharsize, "'%c'", 
                        dpp_constdata[i][charvalue]);
                }

                if(dpp_constdata[i][const_type] != dpp_const_type_bool)
                {
                    strmid(replacement, newvalue, 0, dpp_argcharsize, dpp_argcharsize);
                }
                constvalid = 1;
                break;
            }
        }
    }

    argvalid = CallLocalFunction("dpp_formatcheck", "ss", symbolname, replacement);

    for(new i; i < strlen(replacement); i++)
    {
        if(replacement[i] == '\"') strdel(replacement, i,i+1);
    }

    if(constvalid == 1 || varvalid == 1 || argvalid == 1)
    {
        dpp_strreplace(argument,replacementname,replacement,.maxlength=dpp_maxformatlen);
    }
    else if( (constvalid == 0 || varvalid == 0 || argvalid == 0) && start != -1 || end != -1)
    {
        dpp_strreplace(argument,replacementname,"null",.maxlength=dpp_maxformatlen);
    }

    /*new 
        start,
        end,
        len = strlen(argument),
        symbolname[64],
        replacementname[64],
        varvalid = 0,
        constvalid = 0,
        replacement[dpp_maxformatlen],
        newvalue[dpp_maxformatlen];

    new stackoutput_temporary[2048];
    format(stackoutput_temporary,sizeof stackoutput_temporary,"D++ Format backtrace: \n\
        \tstart : '%i'\n\
        \tend : '%i'\n\
        \tlen : '%i'\n\
        \tsymbolname[] : '%s'\n\
        \treplacementname : '%s'\n\
        \tvarvalid : '%i'\n\
        \tconstvalid : '%i'\n\
        \treplacement : '%s'\n\
        \tnewvalue : '%s'\n\
        ",
        start,
        end,
        len,
        symbolname,
        replacementname,
        varvalid,
        constvalid,
        replacement,
        newvalue);
    print(stackoutput_temporary);*/

    len = strlen(argument);
    new doitagain;

    for(new i; i < len; i++)
    {
        if(argument[i] == '{') doitagain = 1;
        if(argument[i] == '}') doitagain = 1;
    }

    if(doitagain == 1)
    {
        dpp_formatarg(argument);
    }
    return 1;
}