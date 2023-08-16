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


stock dpp_argmathcheck(arg[])
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

    dpp_sub(arg);
    dpp_add(arg);

    dpp_mul(arg);
    dpp_div(arg);

    dpp_drm(arg);
    dpp_exp(arg);

    dpp_bor(arg);
    dpp_ban(arg);
    return 1;
}


stock dpp_bor(arg[])
{
    // using::console.cout,add?1:1
    new newvalue[dpp_argcharsize];
    new operands[2][dpp_operandsize];
    dpp_2split(arg, operands[0], operands[1], '|'); //dpp_parseline(arg, operands, '|');

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            dpp_argclasscheck(operands[i]);
            dpp_argoclasscheck(operands[i]);
            dpp_argarraycheck(operands[i]);
            dpp_argfunccheck(operands[i]);
            dpp_argvarcheck(operands[i]);
            dpp_argmathcheck(operands[i]);
            CallLocalFunction("dpp_argenumcheck", "s", operands[i]);
        }
    }

    if( dpp_isnumeric(operands[0]) && dpp_isnumeric(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%i", 
            strval(operands[0])|strval(operands[1]));
    }
    else if( dpp_isfloat(operands[0]) && dpp_isfloat(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%f", 
            floatstr(operands[0])|floatstr(operands[1]));
    }

    return format(arg, strlen(arg), newvalue);
}


stock dpp_ban(arg[])
{
    // using::console.cout,add?1:1
    new newvalue[dpp_argcharsize];
    new operands[2][dpp_operandsize];
    dpp_2split(arg, operands[0], operands[1], '&'); //dpp_parseline(arg, operands, '&');

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            dpp_argclasscheck(operands[i]);
            dpp_argoclasscheck(operands[i]);
            dpp_argarraycheck(operands[i]);
            dpp_argfunccheck(operands[i]);
            dpp_argvarcheck(operands[i]);
            dpp_argmathcheck(operands[i]);
            CallLocalFunction("dpp_argenumcheck", "s", operands[i]);
        }
    }

    if( dpp_isnumeric(operands[0]) && dpp_isnumeric(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%i", 
            strval(operands[0])&strval(operands[1]));
    }
    else if( dpp_isfloat(operands[0]) && dpp_isfloat(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%f", 
            floatstr(operands[0])&floatstr(operands[1]));
    }

    return format(arg, strlen(arg), newvalue);
}


stock dpp_add(arg[])
{
    // using::console.cout,add?1:1
    new newvalue[dpp_argcharsize];
    new operands[2][dpp_operandsize];
    dpp_2split(arg, operands[0], operands[1], '+'); //dpp_parseline(arg, operands, '+');

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            dpp_argclasscheck(operands[i]);
            dpp_argoclasscheck(operands[i]);
            dpp_argarraycheck(operands[i]);
            dpp_argfunccheck(operands[i]);
            dpp_argvarcheck(operands[i]);
            dpp_argmathcheck(operands[i]);
            CallLocalFunction("dpp_argenumcheck", "s", operands[i]);
        }
    }

    if( dpp_isnumeric(operands[0]) && dpp_isnumeric(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%i", 
            strval(operands[0])+strval(operands[1]));
    }
    else if( dpp_isfloat(operands[0]) && dpp_isfloat(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%f", 
            floatstr(operands[0])+floatstr(operands[1]));
    }

    return format(arg, strlen(arg), newvalue);
}


stock dpp_sub(arg[])
{
    // using::console.cout,add?1:1
    new newvalue[dpp_argcharsize];
    new operands[2][dpp_operandsize];
    dpp_2split(arg, operands[0], operands[1], '-'); //dpp_parseline(arg, operands, '-');

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            dpp_argclasscheck(operands[i]);
            dpp_argoclasscheck(operands[i]);
            dpp_argarraycheck(operands[i]);
            dpp_argfunccheck(operands[i]);
            dpp_argvarcheck(operands[i]);
            dpp_argmathcheck(operands[i]);
            CallLocalFunction("dpp_argenumcheck", "s", operands[i]);
        }
    }

    if( dpp_isnumeric(operands[0]) && dpp_isnumeric(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%i", 
            strval(operands[0])-strval(operands[1]));
    }
    else if( dpp_isfloat(operands[0]) && dpp_isfloat(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%f", 
            floatstr(operands[0])-floatstr(operands[1]));
    }

    return format(arg, strlen(arg), newvalue);
}


stock dpp_mul(arg[])
{
    // using::console.cout,add?1:1
    new newvalue[dpp_argcharsize];
    new operands[2][dpp_operandsize];
    dpp_2split(arg, operands[0], operands[1], '*'); //dpp_parseline(arg, operands, '*');

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            dpp_argclasscheck(operands[i]);
            dpp_argoclasscheck(operands[i]);
            dpp_argarraycheck(operands[i]);
            dpp_argfunccheck(operands[i]);
            dpp_argvarcheck(operands[i]);
            dpp_argmathcheck(operands[i]);
            CallLocalFunction("dpp_argenumcheck", "s", operands[i]);
        }
    }

    if( dpp_isnumeric(operands[0]) && dpp_isnumeric(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%i", 
            strval(operands[0])*strval(operands[1]));
    }
    else if( dpp_isfloat(operands[0]) && dpp_isfloat(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%f", 
            floatstr(operands[0])*floatstr(operands[1]));
    }

    return format(arg, strlen(arg), newvalue);
}



stock dpp_div(arg[])
{
    // using::console.cout,add?1:1
    new newvalue[dpp_argcharsize];
    new operands[2][dpp_operandsize];
    dpp_2split(arg, operands[0], operands[1], '/'); //dpp_parseline(arg, operands, '/');

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            dpp_argclasscheck(operands[i]);
            dpp_argoclasscheck(operands[i]);
            dpp_argarraycheck(operands[i]);
            dpp_argfunccheck(operands[i]);
            dpp_argvarcheck(operands[i]);
            dpp_argmathcheck(operands[i]);
            CallLocalFunction("dpp_argenumcheck", "s", operands[i]);
        }
    }
    
    if( dpp_isnumeric(operands[0]) && dpp_isnumeric(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%i", 
            strval(operands[0])/strval(operands[1]));
    }
    else if( dpp_isfloat(operands[0]) && dpp_isfloat(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%f", 
            floatstr(operands[0])/floatstr(operands[1]));
    }

    return format(arg, strlen(arg), newvalue);
}



stock dpp_exp(arg[])
{
    // using::console.cout,add?1:1
    new newvalue[dpp_argcharsize];
    new operands[2][dpp_operandsize];
    dpp_2split(arg, operands[0], operands[1], '^'); //dpp_parseline(arg, operands, '^');

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            dpp_argclasscheck(operands[i]);
            dpp_argoclasscheck(operands[i]);
            dpp_argarraycheck(operands[i]);
            dpp_argfunccheck(operands[i]);
            dpp_argvarcheck(operands[i]);
            dpp_argmathcheck(operands[i]);
            CallLocalFunction("dpp_argenumcheck", "s", operands[i]);
        }
    }

    format(newvalue, sizeof newvalue, "%f", 
        floatpower(Float:(strval(operands[0])),Float:(strval(operands[1]))));

    return format(arg, strlen(arg), newvalue);
}


stock dpp_drm(arg[])
{
    // using::console.cout,add?1:1
    new newvalue[dpp_argcharsize];
    new operands[2][dpp_operandsize];
    dpp_2split(arg, operands[0], operands[1], '%'); //dpp_parseline(arg, operands, '%');

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            dpp_argclasscheck(operands[i]);
            dpp_argoclasscheck(operands[i]);
            dpp_argarraycheck(operands[i]);
            dpp_argfunccheck(operands[i]);
            dpp_argvarcheck(operands[i]);
            dpp_argmathcheck(operands[i]);
            CallLocalFunction("dpp_argenumcheck", "s", operands[i]);
        }
    }

    if( dpp_isnumeric(operands[0]) && dpp_isnumeric(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%i", 
            strval(operands[0])%strval(operands[1]));
    }
    else if( dpp_isfloat(operands[0]) && dpp_isfloat(operands[1]) )
    {
        format(newvalue, sizeof newvalue, "%f", 
            strval(operands[0])%strval(operands[1]));
    }

    return format(arg, strlen(arg), newvalue);
}