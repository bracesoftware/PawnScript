/*
*
* D++ Scripting Language
*     Made for a SA:MP server
*
* Support for enumerators
*
* 
* - by: DEntisT, (c) 2022
*
*/


stock dpp_createenum(const name[])
{
    for(new i; i < dpp_maxenum; i++)
    {
        if(dpp_validenum[i] == 0)
        {
            dpp_validenum[i] = 1;
            dpp_currentenumid = i;
            strmid(dpp_enumname[i], name, 0, dpp_maxsymbolchar, dpp_maxsymbolchar);
            return 1;
        }
    }
    return 1;
}

stock dpp_addenumval(enumid, const valname[], value)
{
    for(new i; i < dpp_maxenumvals; i++)
    {
        if(dpp_enumvalues[enumid][i][e_valid] == 0)
        {
            dpp_enumvalues[enumid][i][e_valid] = 1;
            dpp_enumvalues[enumid][i][e_value] = value;
            strmid(dpp_enumvalues[enumid][i][e_valname], valname, 0, dpp_maxsymbolchar, dpp_maxsymbolchar);
            return 1;   
        }
    }
    return 0;
}

forward dpp_argenumcheck(arg[]);
public dpp_argenumcheck(arg[])
{
    new newvalue[dpp_argcharsize],
        enumdata[2][dpp_maxsymbolchar];

    dpp_parseline(arg,enumdata,'.');

    new enumid = -1;
    for(new i; i < dpp_maxenum; i++)
    {
        if(!strcmp(dpp_enumname[i],enumdata[0]) && dpp_validenum[i] == 1)
        {
            enumid = i;
            break;
        }
    }

    if(enumid == -1)
    {
        return 1;
    }

    for(new i; i < dpp_maxenumvals; i++)
    {
        if(!strcmp(dpp_enumvalues[enumid][i][e_valname], enumdata[1]))
        {
            if(dpp_enumvalues[enumid][i][e_valid] == 1)
            {
                format(newvalue, sizeof newvalue, "%i", dpp_enumvalues[enumid][i][e_value]);
                break;
            }
        }
    }
    strmid(arg, newvalue, 0, dpp_argcharsize, dpp_argcharsize);
    return 1;
}