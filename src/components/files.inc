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


forward dpp_processfiles(funcgroup[][],args[][],args_const[][]);
public dpp_processfiles(funcgroup[][],args[][],args_const[][])
{
    if(!strcmp(funcgroup[0], "files"))
    {
        if(dpp_config[files_comp] == 0)
        {
            dpp_error("Component \"files\" is not imported.",);
            dpp_internal<return>(0);
        }
        if(!strcmp(funcgroup[1], "createdir"))
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
                dpp_internal<return>(0);
            }
            if(mul != 2)
            {
                dpp_error("Argument error; [%i] \"%s\"", mul, args[0]);
                dpp_internal<return>(0);
            }

            format(args[0],dpp_maxpathsize,"%s%s",dpp_curpath,args[0]);
            //fcreatedir(args[0]);
            @emit__ tempaddr        ,.str=args[0]
            #emit push.c            dpp_tempaddr__
            #emit push.c            4
            #emit sysreq.c          fcreatedir
            #emit stack             8
            //#emit retn
            dpp_internal<return>(1);
        }
        if(!strcmp(funcgroup[1], "delete"))
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
                dpp_internal<return>(0);
            }
            if(mul != 2)
            {
                dpp_error("Argument error; [%i] \"%s\"", mul, args[0]);
                dpp_internal<return>(0);
            }

            //fremove(args[0]);
            format(args[0],dpp_maxpathsize,"%s%s",dpp_curpath,args[0]);
            @emit__ tempaddr        ,.str=args[0]
            #emit push.c            dpp_tempaddr__
            #emit push.c            4
            #emit sysreq.c          fremove
            #emit stack             8
            //#emit retn
            dpp_internal<return>(1);
        }
        if(!strcmp(funcgroup[1], "open_for_append"))
        {
            if(dpp_fhandleused == 1)
            {
                dpp_error("Another file handle is opened already.",);
                dpp_internal<return>(0);
            }
            new mul, str[dpp_argcharsize];
            strmid(str, args[0], 0, dpp_argcharsize);
            for(new i; i < strlen(args[0]); i++)
            {
                if(args[0][i] == '\"') mul++, strdel(args[0], i, i+1);
            }
            if(mul == 0)
            {
                dpp_error("You need to use '\"' to start a string.",);
                dpp_internal<return>(0);
            }
            if(mul != 2)
            {
                dpp_error("Argument error; [%i] \"%s\"", mul, args[0]);
                dpp_internal<return>(0);
            }
            format(args[0],dpp_maxpathsize,"%s%s",dpp_curpath,args[0]);

            dpp_filehandle = fopen(args[0], io_append);
            dpp_fhandleused = 1;
            dpp_internal<return>(1);
        }
        if(!strcmp(funcgroup[1], "open_for_read"))
        {
            if(dpp_fhandleused == 1)
            {
                dpp_error("Another file handle is opened already.",);
                dpp_internal<return>(0);
            }
            new mul, str[dpp_argcharsize];
            strmid(str, args[0], 0, dpp_argcharsize);
            for(new i; i < strlen(args[0]); i++)
            {
                if(args[0][i] == '\"') mul++, strdel(args[0], i, i+1);
            }
            if(mul == 0)
            {
                dpp_error("You need to use '\"' to start a string.",);
                dpp_internal<return>(0);
            }
            if(mul != 2)
            {
                dpp_error("Argument error; [%i] \"%s\"", mul, args[0]);
                dpp_internal<return>(0);
            }
            format(args[0],dpp_maxpathsize,"%s%s",dpp_curpath,args[0]);

            dpp_filehandle = fopen(args[0], io_read);
            dpp_fhandleused = 1;
            dpp_internal<return>(1);
        }
        if(!strcmp(funcgroup[1], "open_for_write"))
        {
            if(dpp_fhandleused == 1)
            {
                dpp_error("Another file handle is opened already.",);
                dpp_internal<return>(0);
            }
            new mul, str[dpp_argcharsize];
            strmid(str, args[0], 0, dpp_argcharsize);
            for(new i; i < strlen(args[0]); i++)
            {
                if(args[0][i] == '\"') mul++, strdel(args[0], i, i+1);
            }
            if(mul == 0)
            {
                dpp_error("You need to use '\"' to start a string.",);
                dpp_internal<return>(0);
            }
            if(mul != 2)
            {
                dpp_error("Argument error; [%i] \"%s\"", mul, args[0]);
                dpp_internal<return>(0);
            }
            format(args[0],dpp_maxpathsize,"%s%s",dpp_curpath,args[0]);

            dpp_filehandle = fopen(args[0], io_write);
            dpp_fhandleused = 1;
            dpp_internal<return>(1);
        }
        if(!strcmp(funcgroup[1], "close"))
        {
            if(dpp_fhandleused == 0)
            {
                dpp_error("No file handle is opened.",);
                dpp_internal<return>(0);
            }
            fclose(dpp_filehandle);
            dpp_fhandleused = 0;
            dpp_internal<return>(1);
        }
        if(!strcmp(funcgroup[1], "write"))
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
                dpp_internal<return>(0);
            }
            if(mul != 2)
            {
                dpp_error("Argument error; [%i] \"%s\"", mul, args[0]);
                dpp_internal<return>(0);
            }
            format(args[0],dpp_maxpathsize,"%s%s",dpp_curpath,args[0]);

            fwrite(dpp_filehandle, args[0]);
            dpp_internal<return>(1);
        }
        if(!strcmp(funcgroup[1], "read"))
        {
            new foundvar = -1;

            for(new i; i < dpp_maxvar; i++)
            {
                if(!strcmp(dpp_vardata[i][var_name], args_const[0]))
                {
                    if(dpp_vardata[i][var_type] == dpp_var_type_str)
                    {
                        if(dpp_vardata[i][var_valid] == 1)
                        {
                            foundvar = i;
                            break;
                        }
                    }
                }
            }
            if(foundvar == -1)
            {
                dpp_error("Cannot find a destination string variable : \"%s\"",args_const[0]);
                dpp_internal<return>(0);
            }

            fread(dpp_filehandle, dpp_vardata[foundvar][stringvalue]);
            dpp_internal<return>(1);
        }

        else
        {
            dpp_error("Unknown form in the component \"files\".",);
            dpp_internal<return>(0);
        }
    }
    return 0;
}