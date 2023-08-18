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

stock dpp_createvector(const name[], size)
{
    for(new i; i < dpp_maxvector; i++)
    {
        if(dpp_validvector[i] == 0)
        {
            dpp_validvector[i] = 1;
            strmid(dpp_vectorname[i], name, 0, dpp_maxsymbolchar, dpp_maxsymbolchar);
            if(dpp_workingclassid != dpp_invalidclass)
            {
                new newvalue[dpp_argcharsize];
                format(newvalue,sizeof(newvalue),"DPPCy@%s_%s",dpp_classname[dpp_workingclassid],name);
                strmid(dpp_vectorname[i], newvalue, 0, dpp_argcharsize,dpp_argcharsize);
            }
            dpp_vectorsize[i] = size; // Completely irrelevant initial size.
            for(new vecvalid; vecvalid < dpp_maxvectorsize; vecvalid++) // Initialize ALL of the reserved memory.
            {
                dpp_vectorvalues[i][vecvalid] = dpp_invalidvectorval;
            }
            //dpp_error("Created an iter '%s'",name);
            return 1;
        }
    }
    return 1;
}

stock dpp_updatevectorsize(const name[])
{
    new vectorid = -1;
    for(new i; i < dpp_maxvector; i++)
    {
        if(dpp_strcmp(name, dpp_vectorname[i]))
        {
            if(dpp_validvector[i] == 1)
            {
                vectorid = i;
                break;   
            }
        }
    }
    if(vectorid == -1)
    {
        dpp_error("Vector '%s' could not be found.",name);
        return 1;
    }

    dpp_vectorsize[vectorid] = 0; // Reset the data.

    for(new i; i < dpp_maxvectorsize; i++)
    {
        if(dpp_vectorvalues[vectorid][i] != dpp_invalidvectorval) // Now count for assigned values.
        {
            dpp_vectorsize[vectorid]++;
        }
    }
    return 1;
}

stock dpp_addvalue__v(const name[], value)
{
    new vectorid = -1;
    for(new i; i < dpp_maxvector; i++)
    {
        if(dpp_strcmp(name, dpp_vectorname[i]))
        {
            if(dpp_validvector[i] == 1)
            {
                vectorid = i;
                break;   
            }
        }
    }
    if(vectorid == -1)
    {
        dpp_error("Vector '%s' could not be found.",name);
        return 1;
    }
    for(new i; i < dpp_maxvectorsize; i++)
    {
        if(dpp_vectorvalues[vectorid][i] == dpp_invalidvectorval)
        {
            dpp_vectorvalues[vectorid][i] = value;
            break;   
        }
    }
    dpp_updatevectorsize(name);
    //dpp_error("Added a value '%i' to an iter '%s'",value,name);
    return 1;
}

stock dpp_removevalue__v(const name[], value)
{
    new vectorid = -1;
    for(new i; i < dpp_maxvector; i++)
    {
        if(dpp_strcmp(name, dpp_vectorname[i]))
        {
            if(dpp_validvector[i] == 1)
            {
                vectorid = i;
                break;   
            }
        }
    }
    if(vectorid == -1)
    {
        dpp_error("Vector '%s' could not be found.",name);
        return 1;
    }
    for(new i; i < dpp_maxvectorsize; i++)
    {
        if(dpp_vectorvalues[vectorid][i] == value)
        {
            dpp_vectorvalues[vectorid][i] = dpp_invalidvectorval;
            break;   
        }
    }
    dpp_updatevectorsize(name);
    //dpp_error("Removed a value '%i' from an iter '%s'",value,name);
    return 1;
}


stock dpp_deletevector(const name[])
{
    for(new i; i < dpp_maxvector; i++)
    {
        if(dpp_strcmp(name, dpp_vectorname[i]))
        {
            if(dpp_validvector[i] == 1)
            {
                dpp_validvector[i] = 0;
                return 1;   
            }
        }
    }
    //dpp_error("Iterator '%s' could not be found.",name);
    return 0;
}