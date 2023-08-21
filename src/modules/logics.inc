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

dpp_islogicop(c)
{
    if(c=='=')return 1;
    if(c=='!')return 1;
    if(c=='<')return 1;
    if(c=='>')return 1;
    return 0;
}

forward dpp_parsearg(arg[],ignorelogics);
public dpp_parsearg(arg[],ignorelogics)
{
    dpp_codetrim(arg);

    dpp_removeslashes(arg);
    dpp_argclasscheck(arg);
    dpp_argoclasscheck(arg);
    dpp_argarraycheck(arg);
    dpp_argfunccheck(arg);
    dpp_argvarcheck(arg);
    dpp_argmathcheck(arg);
    dpp_argformargcheck(arg);
    dpp_argsystemval(arg);
    CallLocalFunction("dpp_arginstruct", "s", arg);
    CallLocalFunction("dpp_argenumcheck", "s", arg);
    CallLocalFunction("dpp_argtagcheck", "s", arg);
    if(ignorelogics==0)CallLocalFunction("dpp_logics", "s", arg);

    dpp_formatarg(arg);
    return 1;
}


forward dpp_logics(arg[]);
public dpp_logics(arg[])
{
    new mul;
    for(new i; i < strlen(arg); i++)
    {
        if(arg[i] == '\"') mul++;
    }
    if(mul != 0)
    {
        return 1;
    }

    dpp_equ(arg);
    dpp_neq(arg);

    dpp_gt(arg);
    dpp_lt(arg);

    dpp_ge(arg);
    dpp_le(arg);
    return 1;
}


stock dpp_equ(arg[])
{
    // using::console.cout,add?1:1
    new newvalue[dpp_argcharsize];
    new operands[2][dpp_operandsize];
    dpp_parseline_2(arg, operands, "==");
    //printf("EQU : op1 : '%s', op2 : '%s'", operands[0],operands[1]);

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            CallLocalFunction("dpp_parsearg", "si", operands[i],1);
        }
    }

    if( dpp_isnumeric(operands[0]) && dpp_isnumeric(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%i", 
            strval(operands[0])==strval(operands[1]));
    }
    else if( dpp_isfloat(operands[0]) && dpp_isfloat(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%i", 
            floatstr(operands[0])==floatstr(operands[1]));
    }

    return format(arg, strlen(arg), newvalue);
}


stock dpp_neq(arg[])
{
    // using::console.cout,add?1:1
    new newvalue[dpp_argcharsize];
    new operands[2][dpp_operandsize];
    dpp_parseline_2(arg, operands, "!=");
    //printf("NEQ : op1 : '%s', op2 : '%s'", operands[0],operands[1]);

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            CallLocalFunction("dpp_parsearg", "si", operands[i],1);
        }
    }

    if( dpp_isnumeric(operands[0]) && dpp_isnumeric(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%i", 
            strval(operands[0])!=strval(operands[1]));
    }
    else if( dpp_isfloat(operands[0]) && dpp_isfloat(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%i", 
            floatstr(operands[0])!=floatstr(operands[1]));
    }

    return format(arg, strlen(arg), newvalue);
}


stock dpp_gt(arg[])
{
    // using::console.cout,add?1:1
    new newvalue[dpp_argcharsize];
    new operands[2][dpp_operandsize];
    dpp_parseline(arg, operands, '>');
    //printf("GT : op1 : '%s', op2 : '%s'", operands[0],operands[1]);

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            CallLocalFunction("dpp_parsearg", "si", operands[i],1);
        }
    }

    if( dpp_isnumeric(operands[0]) && dpp_isnumeric(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%i", 
            strval(operands[0])>strval(operands[1]));
    }
    else if( dpp_isfloat(operands[0]) && dpp_isfloat(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%i", 
            floatstr(operands[0])>floatstr(operands[1]));
    }

    return format(arg, strlen(arg), newvalue);
}


stock dpp_lt(arg[])
{
    // using::console.cout,add?1:1
    new newvalue[dpp_argcharsize];
    new operands[2][dpp_operandsize];
    dpp_parseline(arg, operands, '<');
    //printf("LT : op1 : '%s', op2 : '%s'", operands[0],operands[1]);

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            CallLocalFunction("dpp_parsearg", "si", operands[i],1);
        }
    }

    if( dpp_isnumeric(operands[0]) && dpp_isnumeric(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%i", 
            strval(operands[0])<strval(operands[1]));
    }
    else if( dpp_isfloat(operands[0]) && dpp_isfloat(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%i", 
            floatstr(operands[0])<floatstr(operands[1]));
    }

    return format(arg, strlen(arg), newvalue);
}

stock dpp_ge(arg[])
{
    // using::console.cout,add?1:1
    new newvalue[dpp_argcharsize];
    new operands[2][dpp_operandsize];
    dpp_parseline_2(arg, operands, ">=");
    //printf("GE : op1 : '%s', op2 : '%s'", operands[0],operands[1]);

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            CallLocalFunction("dpp_parsearg", "si", operands[i],1);
        }
    }

    if( dpp_isnumeric(operands[0]) && dpp_isnumeric(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%i", 
            strval(operands[0])>=strval(operands[1]));
    }
    else if( dpp_isfloat(operands[0]) && dpp_isfloat(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%i", 
            floatstr(operands[0])>=floatstr(operands[1]));
    }

    return format(arg, strlen(arg), newvalue);
}

stock dpp_le(arg[])
{
    // using::console.cout,add?1:1
    new newvalue[dpp_argcharsize];
    new operands[2][dpp_operandsize];
    dpp_parseline_2(arg, operands, "<=");
    //printf("LE : op1 : '%s', op2 : '%s'", operands[0],operands[1]);

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            CallLocalFunction("dpp_parsearg", "si", operands[i],1);
        }
    }

    if( dpp_isnumeric(operands[0]) && dpp_isnumeric(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%i", 
            strval(operands[0])<=strval(operands[1]));
    }
    else if( dpp_isfloat(operands[0]) && dpp_isfloat(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%i", 
            floatstr(operands[0])<=floatstr(operands[1]));
    }

    return format(arg, strlen(arg), newvalue);
}