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


stock dpp_prepareproject(const script[])
{
    new dpp_proj_file_content[8000];
    dpp_print("Reading the project file.");

    new File:file = fopen(script, io_read), rlen;
    if(file)
    {
        while(rlen = fread(file, dpp_proj_file_content))
        {
            /*for(new i; i < strlen(dpp_proj_file_content); i++)
            {
                if(dpp_proj_file_content[i] == ';' && dpp_proj_file_content[i+1] == ' ') strdel(dpp_proj_file_content, i+1, i+2);
                if(dpp_proj_file_content[i] == '\t') strdel(dpp_proj_file_content, i, i+1);
                if(dpp_proj_file_content[i] == '\n') strdel(dpp_proj_file_content, i, i+1);
            }*/
            dpp_debug("dpp_proj_file_content: '%s'", dpp_proj_file_content);
            //dpp_debug("Executing:\n\n%s", dpp_proj_file_content);
            for(new i; i < 1024; i++)
            {
                if(!isnull(dpp_proj_file_content)) dpp_debug("codelines[%i]: '%s'",i, dpp_proj_file_content);
                dpp_projfileprocess(dpp_proj_file_content);
            }
        }
    }

    else if(!file)
    {
        dpp_warning("Project file not found.",);
    }
    return 1;
}

stock dpp_projfileprocess(line[])
{
    dpp_codetrim(line);
    //PROJECT_NAME=D++ testing
    new address[2][512];
    dpp_parseline(line,address,'=');

    //project_name
    if(!strcmp(address[0], "project_name"))
    {
        strmid(dpp_projname,address[1],0,128,128);
        return 1;
    }
    //stack_output
    if(!strcmp(address[0], "stack_output"))
    {
        if(!strcmp(address[1], "true"))
        {
            dpp_stackoutput = 1;
            return 1;
        }
        if(!strcmp(address[1], "false"))
        {
            dpp_stackoutput = 0;
            return 1;
        }
        return 1;
    }
    return 1;
}