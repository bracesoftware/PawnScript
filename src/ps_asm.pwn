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

#define tempaddr 0

#define @emit__%0\32;%1\10;%3 dpp_asm__(%1);

stock dpp_asm__(operand, int = 0, bool:bool = false, const str[] = "null")
{
    #pragma unused int
    #pragma unused bool
    if(operand == tempaddr)
    {
        strmid(dpp_tempaddr__, str, 0, sizeof dpp_tempaddr__);
        return 1;
    }
    return 1;
}

new dpp_currentid;
new dpp_currentsector;


stock dpp_parseaddr(addr[])
{
    dpp_removeslashes(addr);
    dpp_argclasscheck(addr);
    dpp_argoclasscheck(addr);
    dpp_argarraycheck(addr);
    dpp_argfunccheck(addr);
    dpp_argvarcheck(addr);
    dpp_argmathcheck(addr);
    dpp_argformargcheck(addr);
    dpp_argsystemval(addr);
    CallLocalFunction("dpp_arginstruct", "s", addr);
    CallLocalFunction("dpp_argenumcheck", "s", addr);
    CallLocalFunction("dpp_argtagcheck", "s", addr);

    dpp_formatarg(addr);
    return 1;
}

dpp_processasm(dirgroup[][],dirargs[][]);
public dpp_processasm(dirgroup[][],dirargs[][])
{
    dpp_parseaddr(dirargs[1]);
    //#emit:operation,operand;
    if(!strcmp(dirgroup[0], "#emit"))
    {
        /*
        * addrset
        *
        * - Set an address to operate on.
        */
        if(!strcmp(dirargs[0], "addrset"))
        {
            new address[2][10];
            dpp_parseline(dirargs[1], address, '@');
            dpp_currentid = strval(address[0]);
            dpp_currentsector = strval(address[1]);

            //dpp_print("dpp_currentid : '%i' | dpp_currentsector : '%i'",dpp_currentid,dpp_currentsector);
            return 1;
        }
        if(!strcmp(dirargs[0], "csnm"))
        {
            if(dpp_currentsector == dpp_memsec_var)
            {
                strmid(dpp_vardata[dpp_currentid][var_name], dirargs[1], 0, 64, 64);
                return 1;
            }
        }
        if(!strcmp(dirargs[0], "dtyp"))
        {
            if(dpp_currentsector == dpp_memsec_var)
            {
                if(dpp_var_type_int <= strval(dirargs[1]) <= dpp_var_type_char)
                {
                    dpp_vardata[dpp_currentid][var_type] = strval(dirargs[1]);
                }
                else
                {
                    dpp_error("Wrong data type ID specified.",);
                }
                return 1;
            }
        }
        if(!strcmp(dirargs[0], "vlset"))
        {
            if(dpp_currentsector == dpp_memsec_var)
            {
                // INTEGERS
                if(dpp_vardata[dpp_currentid][var_type] == dpp_var_type_int)
                {
                    if(!dpp_isnumeric(dirargs[1]))
                    {
                        dpp_error("Data type mismatch; value must be an integer.",);
                        return 0;
                    }
                    dpp_vardata[dpp_currentid][integervalue] = strval(dirargs[1]);
                    return 1;
                }
                //BOOLEANS
                if(dpp_vardata[dpp_currentid][var_type] == dpp_var_type_bool)
                {
                    if(strcmp(dirargs[1],"true") && strcmp(dirargs[1],"false"))
                    {
                        dpp_error("Data type mismatch; value must be either 'true' or 'false'.",);
                        return 0;
                    }

                    new dpp_boolval;


                    if(!strcmp(dirargs[1], "false"))
                    {
                        dpp_boolval = 0;
                    }
                    if(!strcmp(dirargs[1], "true"))
                    {
                        dpp_boolval = 1;
                    }

                    dpp_vardata[dpp_currentid][boolvalue] = dpp_boolval;
                    return 1;
                }
                // STRINGS
                if(dpp_vardata[dpp_currentid][var_type] == dpp_var_type_str)
                {
                    new mul2;
                    for(new i; i < strlen(dirargs[1]); i++)
                    {
                        if(dirargs[1][i] == '\"') mul2++, strdel(dirargs[1], i, i+1);
                    }
                    if(mul2 == 0)
                    {
                        dpp_error("You need to use '\"' to start a string.",);
                        return 0;
                    }
                    if(mul2 != 2)
                    {
                        dpp_error("Argument error; [%i] \"%s\"", mul2, dirargs[1]);
                        return 0;
                    }

                    strmid(dpp_vardata[dpp_currentid][stringvalue], dirargs[1], 0, dpp_maxstrsize, dpp_maxstrsize);
                    return 1;
                }
                // DOUBLES
                if(dpp_vardata[dpp_currentid][var_type] == dpp_var_type_double)
                {
                    if(!dpp_isfloat(dirargs[1]))
                    {
                        dpp_error("Data type mismatch; argument must be a double.",);
                        return 1;
                    }

                    dpp_vardata[dpp_currentid][floatvalue] = floatstr(dirargs[1]);
                    return 1;
                }
                // CHARACTERS
                if(dpp_vardata[dpp_currentid][var_type] == dpp_var_type_char)
                {
                    new mul2;
                    for(new i; i < strlen(dirargs[1]); i++)
                    {
                        if(dirargs[1][i] == '\'') mul2++, strdel(dirargs[1], i, i+1);
                    }
                    if(mul2 == 0)
                    {
                        dpp_error("You need to use \"'\" to start a char.",);
                        return 0;
                    }
                    if(mul2 != 2)
                    {
                        dpp_error("Data type mismatch; [%i] \"%s\"", mul2, dirargs[1]);
                        return 0;
                    }

                    dpp_vardata[dpp_currentid][charvalue] = dirargs[1][0];
                    return 1;
                }
            }
            return 1;
        }
        // oops! Wrong operation.
        else
        {
            dpp_error("Unknown operation \"%s\".", dirargs[0]);
            return 0;
        }
    }
    return 1;
}