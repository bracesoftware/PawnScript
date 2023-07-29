/*
*
* D++ Scripting Language
*     Made for a SA:MP server
*
* Support for matematical operations
*
* 
* - by: DEntisT, (c) 2022
*
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

    dpp_add(arg);
    dpp_sub(arg);
    dpp_div(arg);
    dpp_mul(arg);
    dpp_exp(arg);
    dpp_drm(arg);
    return 1;
}

stock dpp_add(arg[])
{
    // using::console.cout,add?1:1
    new newvalue[dpp_argcharsize];
    new operands[2][64];
    dpp_parseline(arg, operands, '+');

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            dpp_argclasscheck(operands[i]);
            dpp_argarraycheck(operands[i]);
            dpp_argfunccheck(operands[i]);
            dpp_argvarcheck(operands[i]);
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
    new operands[2][64];
    dpp_parseline(arg, operands, '-');

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            dpp_argclasscheck(operands[i]);
            dpp_argarraycheck(operands[i]);
            dpp_argfunccheck(operands[i]);
            dpp_argvarcheck(operands[i]);
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
    new operands[2][64];
    dpp_parseline(arg, operands, '*');

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            dpp_argclasscheck(operands[i]);
            dpp_argarraycheck(operands[i]);
            dpp_argfunccheck(operands[i]);
            dpp_argvarcheck(operands[i]);
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
    new operands[2][64];
    dpp_parseline(arg, operands, '/');

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            dpp_argclasscheck(operands[i]);
            dpp_argarraycheck(operands[i]);
            dpp_argfunccheck(operands[i]);
            dpp_argvarcheck(operands[i]);
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
    new operands[2][64];
    dpp_parseline(arg, operands, '^');

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            dpp_argclasscheck(operands[i]);
            dpp_argarraycheck(operands[i]);
            dpp_argfunccheck(operands[i]);
            dpp_argvarcheck(operands[i]);
            CallLocalFunction("dpp_argenumcheck", "s", operands[i]);
        }
    }

    format(newvalue, sizeof newvalue, "%i", 
        floatround(floatpower(Float:(strval(operands[0])),Float:(strval(operands[1])))));

    return format(arg, strlen(arg), newvalue);
}


stock dpp_drm(arg[])
{
    // using::console.cout,add?1:1
    new newvalue[dpp_argcharsize];
    new operands[2][64];
    dpp_parseline(arg, operands, '%');

    if(isnull(operands[0]) || isnull(operands[1]))
    {
        return 1;
    }

    if(!dpp_isnumeric(operands[0]) || !dpp_isnumeric(operands[1]))
    {
        for(new i; i < 2; i++)
        {
            dpp_argclasscheck(operands[i]);
            dpp_argarraycheck(operands[i]);
            dpp_argfunccheck(operands[i]);
            dpp_argvarcheck(operands[i]);
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