/*

The ORIGINAL CODE is the `PawnScript the Language` Source Code.
The INITIAL DEVELOPER is Brace Inc., DEntisT.

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


//-----------------------------------------------------------

#include "ps_mem.pwn"

//-----------------------------------------------------------
// REQUIRED.
#include <open.mp>
#if !defined fcreatedir
    native fcreatedir(const filename[]);
#endif

//-----------------------------------------------------------
//includes
#include "modules/utils.inc"
#include "modules/header.inc"
#include "modules/proj.inc"
#include "modules/const.inc"
#include "modules/vars.inc"
#include "modules/operators.inc"
#include "modules/namespace.inc"
#include "modules/inline.inc"
#include "modules/tasks.inc"
#include "modules/iter.inc"
#include "modules/tags.inc"
#include "modules/typedef.inc"
#include "modules/enum.inc"
#include "modules/persistent.inc"
#include "modules/class.inc"

#include "modules/interpreter.inc"
//-----------------------------------------------------------
//compiler sys
#include "core/index.inc"
#include "core/sys_utils.inc"
#include "core/component_impl.inc"
#include "ps_asm.pwn"
//-----------------------------------------------------------
// component impl
#include "components/system.inc"
#include "components/console.inc"
#include "components/samp.inc"
#include "components/math.inc"
#include "components/files.inc"
#include "components/misc.inc"
#include "components/data.inc"
#include "components/pawn.inc"
//-----------------------------------------------------------

dpp_main(); public dpp_main()
{
    strmid(dpp_projname,"Unnamed project",0,128,128);
    dpp_nullcomment();
    dpp_nullcomment();
    dpp_compile("index"SCRIPT_EXT);
    SetTimer("main_again", 3000, false);
    return 1;   
}

main_again();
public main_again()
{
    CallLocalFunction("dpp_initstack", "");
    
    if(dpp_compiled == 1)
    {
        dpp_execute("index"SCRIPT_EXT);
    }

    CallLocalFunction("DPP_GAMEMODEINIT", "");
    CallRemoteFunction("dppcord_init", "");
    CallLocalFunction("dpp_taskinit", "");
    return 1;
}

dpp_dostackoutput();
public dpp_dostackoutput()
{
    new stackfile[512],argfile[256];
    if(fexist(STACKOUTPUT_FILE)) fremove(STACKOUTPUT_FILE);
    dpp_nullcomment();
    dpp_comment();
    dpp_print("Loading the stack...");
    dpp_print("Loading the forms stack...");
    dpp_comment();
    dpp_savelog(STACKOUTPUT_FILE,"===============================================================");
    dpp_savelog(STACKOUTPUT_FILE,"FORMS");
    dpp_savelog(STACKOUTPUT_FILE,"===============================================================");
    for(new i; i < dpp_maxfuncs; i++)
    {
        format(stackfile,sizeof stackfile,"ID : %i | VALID : %i | NAME: \"%s\"\n\n",
            i,
            dpp_validfunc[i],
            dpp_funcname[i]);
        for(new argid; argid < dpp_maxformargs; argid++)
        {
            format(argfile, sizeof argfile, "\n\nARG[%i] NAME : \"%s\" | ARG[%i] VALUE : \"%s\"",
                argid,dpp_args[i][argid][dpp_argname],
                argid,dpp_args[i][argid][dpp_argvalue]);
            strcat(stackfile, argfile);
        }
        dpp_savelog(STACKOUTPUT_FILE,stackfile);
    }
    dpp_comment();
    dpp_print("Loading the const stack...");
    dpp_comment();
    dpp_savelog(STACKOUTPUT_FILE,"===============================================================");
    dpp_savelog(STACKOUTPUT_FILE,"CONSTANTS");
    dpp_savelog(STACKOUTPUT_FILE,"===============================================================");
    for(new i; i < dpp_maxconst; i++)
    {
        format(stackfile,sizeof stackfile,"ID : %i | VALID : %i | NAME: \"%s\"",
            i,
            dpp_constdata[i][const_valid],
            dpp_constdata[i][const_name]);
        dpp_savelog(STACKOUTPUT_FILE,stackfile);
    }
    dpp_comment();
    dpp_print("Loading the vars stack...");
    dpp_comment();
    dpp_savelog(STACKOUTPUT_FILE,"===============================================================");
    dpp_savelog(STACKOUTPUT_FILE,"VARS");
    dpp_savelog(STACKOUTPUT_FILE,"===============================================================");
    for(new i; i < dpp_maxvar; i++)
    {
        format(stackfile,sizeof stackfile,"ID : %i | VALID : %i | NAME: \"%s\"",
            i,
            dpp_vardata[i][var_valid],
            dpp_vardata[i][var_name]);
        dpp_savelog(STACKOUTPUT_FILE,stackfile);
    }
    dpp_comment();
    dpp_print("Loading the class stack...");
    dpp_comment();
    dpp_savelog(STACKOUTPUT_FILE,"===============================================================");
    dpp_savelog(STACKOUTPUT_FILE,"CLASSES");
    dpp_savelog(STACKOUTPUT_FILE,"===============================================================");
    for(new i; i < dpp_maxclass; i++)
    {
        format(stackfile,sizeof stackfile,"ID : %i | VALID : %i | NAME: \"%s\"",
            i,
            dpp_validclass[i],
            dpp_classname[i]);
        dpp_savelog(STACKOUTPUT_FILE,stackfile);
    }

    dpp_comment();
    dpp_print("Loading the iterator stack...");
    dpp_comment();
    dpp_savelog(STACKOUTPUT_FILE,"===============================================================");
    dpp_savelog(STACKOUTPUT_FILE,"ITERATORS");
    dpp_savelog(STACKOUTPUT_FILE,"===============================================================");
    for(new i; i < dpp_maxiter; i++)
    {
        format(stackfile,sizeof stackfile,"ID : %i | VALID : %i | NAME: \"%s\" | SIZE: %i",
            i,
            dpp_validiter[i],
            dpp_itername[i],
            dpp_itersize[i]);
        dpp_savelog(STACKOUTPUT_FILE,stackfile);
    }

    return 1;
}

pawnscriptcall(line[]); public pawnscriptcall(line[])
{
    dpp_process(line);
    return 1;
}

public OnGameModeExit()
{
    CallLocalFunction("dpp_sampexitcall", "");
    dpp_nullcomment();
    //dpp_print("The interpreter reached the EOS point.");
    dpp_print("Process finished with %i errors and %i warnings.", dpp_errorcount,dpp_warningcount);
    //dpp_print("The SA:MP/open.mp script will continue running in the background.");
    if(dpp_stackoutput == 1)
    {
        CallLocalFunction("dpp_dostackoutput", "");
    }
    else
    {
        dpp_print("System stack output is disabled.");
    }
    dpp_nullcomment();
    dpp_nullcomment();
    return 1;
}

//-----------------------------------------------------------



stock levenstein(const a[], const b[]) {
    new
        aLength = strlen(a),
        bLength = strlen(b),
        cache[256],
        index = 0,
        bIndex = 0,
        distance,
        bDistance,
        result,
        code;

    if (!strcmp(a, b)) {
        return 0;
    }

    if (aLength == 0) {
        return bLength;
    }

    if (bLength == 0) {
        return aLength;
    }

    while (index < aLength) {
        cache[index] = index + 1;
        index++;
    }

    while (bIndex < bLength) {
        code = b[bIndex];
        result = distance = bIndex++;
        index = -1;

        while (++index < aLength) {
            bDistance = code == a[index] ? distance : distance + 1;
            distance = cache[index];

            cache[index] = result = distance > result
            ? bDistance > result
                ? result + 1
                : bDistance
            : bDistance > distance
                ? distance + 1
                : bDistance;
        }
    }

    return result;
}

main()
{
    SetTimer("dpp_main", 1000, false);
}

//-----------------------------------------------------------

forward pawnscript_testpawnfunc();
public pawnscript_testpawnfunc()
{
    dpp_print("pawnscript_testpawnfunc was sucessfully called");
    return 1;
}

//-----------------------------------------------------------
forward dpp_asmtest();
public dpp_asmtest()
{
    /*new File:file = fopen("test.txt");
    new buffer[256], funcgroup[3][64];
    while(fread(file, buffer))
    {
        printf("Buffer: '%s'", buffer);
        dpp_codetrim(buffer);
        dpp_parseline(buffer, funcgroup, '\32');
        dpp_codetrim(funcgroup[0]);
        dpp_codetrim(funcgroup[1]);
        dpp_codetrim(funcgroup[2]);
        printf("Keyword 1: '%s'",funcgroup[0]);
        printf("Keyword 2: '%s'",funcgroup[1]);
        printf("Keyword 3: '%s'",funcgroup[2]);
    }*/

    // "kdhjsafgkj" vs "d"
    // dpp_data__strdist = 10
    // levenstein = 9

    /*new index;
    printf("Distance: %i",     dpp_data__strdist("kitten", "tt"));
    printf("Levenstein distance: %i", levenstein("kitten", "tt"));
    printf("++index : %i", index--);
    printf("index : %i", index);*/

    new a, __charbytes=1;
    #emit load.s.pri        a
    #emit load.s.alt        __charbytes
    #emit inc.pri
    #emit add
    #emit stor.s.pri        a
    #emit zero.pri
    #emit zero.alt
    printf("%i", a);

    new b=2;
    #emit push.s            a
    #emit push.s            b
    #emit pop.pri
    #emit pop.alt
    #emit add
    #emit stor.s.pri        b
    #emit zero.pri
    #emit zero.alt
    printf("%i", b);


    // For some reason,
    // instruction sets below result in an error.
    new __cellbytes=4,
    arr[]="hi %s",
    arr2[]="hi again";
    #emit push.adr          arr2
    #emit push.adr          arr
    #emit push.c            8
    #emit sysreq.c          printf

    #emit load.pri          dpp_alt__
    #emit load.s.alt        __cellbytes
    #emit add
    #emit stor.pri          dpp_pri__
    #emit zero.pri
    #emit zero.alt
    #emit nop
    printf("%i", dpp_pri__);
    return 1;
}
//-----------------------------------------------------------