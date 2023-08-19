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


stock dpp_asm__(operand, int = 0, bool:bool = false, Float:float = 0.0, const str[] = "null")
{
    #pragma unused bool
    if(operand == tempaddr)
    {
        strmid(dpp_tempaddr__, str, 0, sizeof dpp_tempaddr__);
        return 1;
    }
    if(operand == tempreg)
    {
        #emit zero.pri
        #emit load.s.pri        int
        #emit stor.pri          dpp_tempreg__
        return 1;
    }

    if(operand == tempfloat)
    {
        #emit zero.pri
        #emit load.s.pri        float
        #emit stor.pri          dpp_tempfloat__
        return 1;
    }
    if(operand == stk@push)
    {
        dpp__emitpush___(str);
        return 1;
    }
    if(operand == stk@pop)
    {
        dpp__emitpop___(str);
        return 1;
    }
    if(operand == stk@allcol)
    {
        dpp_allowcollision = 1;
        return 1;
    }
    #emit retn
    return 1;
}

new dpp_currentid; // cur reg
new dpp_currentsector; // sec reg
new dpp_nextid;


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
        // Some standard assembly first
        // There we will use variables as a replacement for registers.
        if(!strcmp(dirargs[0], "const.pri"))
        {
            dpp_pri__ = strval(dirargs[1]);
            return 1;
        }
        if(!strcmp(dirargs[0], "const.alt"))
        {
            dpp_alt__ = strval(dirargs[1]);
            return 1;
        }
        if(!strcmp(dirargs[0], "load.pri"))
        {
            if(dpp_currentsector == dpp_memsec_var)
            {
                // These instructions support only integers...
                if(dpp_vardata[dpp_currentid][var_type] == dpp_var_type_int)
                {
                    dpp_pri__= dpp_vardata[dpp_currentid][integervalue];
                    return 1;
                }
                dpp_pri__ = 0;
            }
            return 1;
        }
        if(!strcmp(dirargs[0], "load.alt"))
        {
            if(dpp_currentsector == dpp_memsec_var)
            {
                // These instructions support only integers...
                if(dpp_vardata[dpp_currentid][var_type] == dpp_var_type_int)
                {
                    dpp_alt__= dpp_vardata[dpp_currentid][integervalue];
                    return 1;
                }
                dpp_alt__ = 0;
            }
            return 1;

        }
        if(!strcmp(dirargs[0], "add"))
        {
            dpp_pri__ = dpp_pri__+dpp_alt__;
            return 1;
        }
        if(!strcmp(dirargs[0], "sub"))
        {
            dpp_pri__ = dpp_pri__-dpp_alt__ < 0 ? dpp_pri__-dpp_alt__*(-1) : dpp_pri__-dpp_alt__;
            return 1;
        }
        if(!strcmp(dirargs[0], "mul"))
        {
            dpp_pri__ = dpp_pri__*dpp_alt__;
            return 1;
        }
        if(!strcmp(dirargs[0], "div"))
        {
            dpp_pri__ = dpp_alt__ == 0 ? 0 : dpp_pri__/dpp_alt__;
            return 1;
        }
        if(!strcmp(dirargs[0], "xchg"))
        {
            dpp_tmp = dpp_pri__;
            dpp_pri__ = dpp_alt__;
            dpp_alt__ = dpp_tmp;
            return 1;
        }
        if(!strcmp(dirargs[0], "stor.pri"))
        {
            if(dpp_currentsector == dpp_memsec_var)
            {
                // INTEGERS
                if(dpp_vardata[dpp_currentid][var_type] == dpp_var_type_int)
                {
                    dpp_vardata[dpp_currentid][integervalue] = dpp_pri__;
                    return 1;
                }
            }
            return 1;
        }
        if(!strcmp(dirargs[0], "stor.alt"))
        {
            if(dpp_currentsector == dpp_memsec_var)
            {
                // INTEGERS
                if(dpp_vardata[dpp_currentid][var_type] == dpp_var_type_int)
                {
                    dpp_vardata[dpp_currentid][integervalue] = dpp_alt__;
                    return 1;
                }
            }
            return 1;

        }
        if(!strcmp(dirargs[0], "zero.pri"))
        {
            dpp_pri__=0;
            return 1;
        }
        if(!strcmp(dirargs[0], "zero.alt"))
        {
            dpp_alt__=0;
            return 1;
        }
        if(!strcmp(dirargs[0], "lctrl"))
        {
            if(strval(dirargs[1]) == 1)
            {
                dpp_pri__=dpp_currentid;
                return 1;
            }
            if(strval(dirargs[1]) == 2)
            {
                dpp_pri__=dpp_currentsector;
                return 1;
            }
            if(strval(dirargs[1]) == 3)
            {
                dpp_pri__=dpp_tmp;
                return 1;
            }
            if(strval(dirargs[1]) == 4)
            {
                dpp_pri__=dpp_nextid;
                return 1;
            }
            return 1;
        }
        if(!strcmp(dirargs[0], "sctrl"))
        {
            if(strval(dirargs[1]) == 1)
            {
                dpp_currentid=dpp_pri__;
                return 1;
            }
            if(strval(dirargs[1]) == 2)
            {
                dpp_currentsector=dpp_pri__;
                if(dpp_currentsector == dpp_memsec_var)
                {
                    for(new i; i < dpp_maxvar; i++)
                    {
                        if(dpp_vardata[i][var_valid] == 0)
                        {
                            dpp_nextid = i;
                            break;
                        }
                    }                    
                    return 1;
                }
                return 1;
            }
            if(strval(dirargs[1]) == 3)
            {
                dpp_tmp=dpp_pri__;
                return 1;
            }
            if(strval(dirargs[1]) == 4)
            {
                dpp_nextid=dpp_pri__;
                return 1;
            }
            return 1;
        }
        if(!strcmp(dirargs[0], "push"))
        {
            if(dpp_currentsector == dpp_memsec_var)
            {
                dpp_vardata[dpp_currentid][var_valid] = 1;
            }
            return 1;
        }
        if(!strcmp(dirargs[0], "pop"))
        {
            if(dpp_currentsector == dpp_memsec_var)
            {
                dpp_vardata[dpp_currentid][var_valid] = 0;
            }
            return 1;
        }
        if(!strcmp(dirargs[0], "inc.alt"))
        {
            dpp_alt__++;
            return 1;
        }

        if(!strcmp(dirargs[0], "inc.pri"))
        {
            dpp_pri__++;
            return 1;
        }
        if(!strcmp(dirargs[0], "dec.alt"))
        {
            dpp_alt__--;
            return 1;
        }

        if(!strcmp(dirargs[0], "dec.pri"))
        {
            dpp_pri__--;
            return 1;
        }

        /*
        * addrset
        *
        * - Set an address to operate on.
        */
        if(!strcmp(dirargs[0], "addrset"))
        {
            new address[2][10];
            dpp_parseline(dirargs[1], address, '@');
            if(isnull(address[0]) || isnull(address[1]))
            {
                dpp_fatalerror(4);
                return 1;
            }
            if(!dpp_isnumeric(address[0]) || !dpp_isnumeric(address[1]))
            {
                dpp_fatalerror(4);
                return 1;
            }
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
        dpp_fatalerror(3);
        return 1;
    }
    return 1;
}