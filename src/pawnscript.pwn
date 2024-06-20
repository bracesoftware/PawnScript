/*

The ORIGINAL CODE is the `PawnScript: the Language` Source Code.
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


#pragma dynamic 16108732
#pragma warning disable 204
#pragma warning disable 211
#pragma option -;+

//-----------------------------------------------------------

#include "ps_setup.pwn"

//-----------------------------------------------------------
// REQUIRED.
#include <open.mp>
#if !defined fcreatedir
native fcreatedir(const filename[]);
#endif

//-----------------------------------------------------------
#include "ps_stk.pwn"
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
#include "modules/template.inc"
#include "modules/vectors.inc"
#include "modules/logics.inc"

#include "modules/interpreter.inc"
//-----------------------------------------------------------
//compiler sys
#include "core/index.inc"
#include "core/sys_utils.inc"
#include "core/component_impl.inc"
#include "ps_asm.pwn"
#include "ps_sdk.pwn"
#include "ps_graphics.pwn"
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
#include "components/iter.inc"
#include "components/vector.inc"
#include "components/graphics.inc"
//-----------------------------------------------------------

dpp_resspeedhz(); public dpp_resspeedhz()
{
    dpp_speedhz = 0;
    return 1;
}

dpp_main(); public dpp_main()
{
    fcreatedir(PS_LOGDIR); // Log folder
    strmid(dpp_projname,"Unnamed project",0,128,128);
    dpp_nullcomment();
    dpp_nullcomment();
    dpp_compile("index"SCRIPT_EXT);
    SetTimer("main_again", 3000, false);
    SetTimer("dpp_resspeedhz",1000,true);

    fcreatedir(PSDATA_DIRNAME); // Data folder
    
    //print("-");
    return 1;
}

main_again();
public main_again()
{
    CallLocalFunction("dpp_initstack", "");
    CallLocalFunction("dpp_initstk", "");
    
    if(dpp_compiled == 1)
    {
        dpp_execute("index"SCRIPT_EXT);
    }

    CallLocalFunction("DPP_GAMEMODEINIT", "");
    CallRemoteFunction("dppcord_init", "");
    CallLocalFunction("dpp_taskinit", "");
    CallRemoteFunction("__ps_sdktest", "");
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

main()
{
    //CallLocalFunction("dpp_asmtest", "");
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
#pragma unused myprintf
myprintf(const formattedstr[], {Float,_}:...)
{
    if(numargs() == 1)
    {
        @emit__ tempaddr    ,.str=formattedstr
        #emit push.c        dpp_tempaddr__
        #emit push.c        4
        #emit sysreq.c      print
        #emit stack         8
        #emit const.pri     0
        #emit retn
        return 0;
    }

    #emit nop // Just no.

    #emit const.pri         0
    #emit retn
    return 0; // Make the compiler happy.
}

__asmtest2()
{
    // This function will actually return a value
    // stored inside a primary register.
    #emit const.pri         24
    #emit retn
    return 1; // Make compiler happy.
}

new stk, stp, tmp; // globals are not involved in the stack
f(arg)
{
    // compiler automatically adds a PROC instruction at the beginning of every function
    #pragma unused arg
    new x = 200;
  
    #emit LCTRL 3
    #emit STOR.pri stp
  
    #emit LCTRL 4
    #emit STOR.pri stk
  
    printf("STP: %d STK: %d\n", stp, stk);
  
    // prints the contents of the stack from top to bottom (lower address to higher address)
    while(stk != stp) {
        #emit LOAD.pri stk
        #emit LOAD.I
        #emit STOR.pri tmp
        printf("%d", tmp);
        stk += 4;
    }
    
    // compiler uses whatever information it has and adds instructions to correct the stack before returning
    // if items have been pushed or popped manually using #emit, the compiler will not be aware of it
    return 1234;
}

forward dpp_asmtest();
public dpp_asmtest()
{
    printf("%i", __asmtest2());
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
    arr[]="hi %s %s",
    arr2[]="hi again";
    strmid(dpp_tempaddr__, "Test", 0, sizeof dpp_tempaddr__, sizeof dpp_tempaddr__);
    print(dpp_tempaddr__);
    #emit push.c            dpp_tempaddr__
    #emit push.adr          arr2
    #emit push.adr          arr
    #emit push.c            12
    #emit sysreq.c          printf
    #emit stack             16

    #emit push.c dpp_tempaddr__
    #emit push.c 4
    #emit sysreq.c print
    #emit stack 8

    #emit load.pri          dpp_alt__
    #emit load.s.alt        __cellbytes
    #emit add
    #emit stor.pri          dpp_pri__
    #emit zero.pri
    #emit zero.alt
    #emit nop
    printf("%i", dpp_pri__);

    #emit nop
    new test=5;
    @emit__ tempfloat       ,.float=23.34
    #emit push.c            dpp_tempfloat__
    #emit push.adr          test
    @emit__ tempreg         ,.int=__cellbytes
    #emit push.c            dpp_tempreg__
    @emit__ tempaddr        ,.str="Testaddr2 %i %i %f"
    #emit push.c            dpp_tempaddr__
    #emit push.c            16
    #emit sysreq.c          printf
    #emit stack             20

    /*#emit proc
    @emit__ tempaddr        ,.str="ASM FUNC CALLED!"
    #emit push.c            dpp_tempaddr__
    #emit push.c            4
    #emit sysreq.c          print
    #emit stack             8
    #emit zero.pri
    #emit retn
    @emit__ tempaddr        ,.str="This is not a function!"
    #emit push.c            dpp_tempaddr__
    #emit push.c            4
    #emit sysreq.c          print
    #emit stack             8
    #emit call.pri
    */   
    a = 1;
    f(101);
    #emit stor.s.pri a // store the value stored in the primary register (return value) in 'a'
    printf("\nPRI: %d", a);


    static const str[] = "Random number: %d";

    //printf(str, random());
    
    #emit push.c            0 // zero arguments
    #emit sysreq.c          random
    #emit stack             4 // must manually clean the stack (only one item was pushed onto the stack; hence, we move STK up by 4)
    // random value was returned in the primary register

    // prepare to push the random value
    // note that 'printf' takes values as variable arguments: we need to push addresses
    #emit heap              4 // make space for the random value in the heap
    #emit stor.i // store the value of the primary register in the newly allocated space
    
    #emit push.alt // push the address of the random value
    #emit push.c            str // 'str' is static local string; hence, it is present in the data segment
    #emit push.c            8
    #emit sysreq.c          printf
    #emit stack             12 // total of three items were pushed; hence, pop 3 cells

    #emit heap              -4
    return 1; // Make compiler happy.
}
//-----------------------------------------------------------
stock dpp_genver__() 
{
    new buf[256];
    format(buf, sizeof buf, "%s-%s",__date,__time);
    new length=strlen(buf);
    new 
        s1 = 1,
        s2 = 0,
        n;
    for (n=0; n<length; n++)
    {
       s1 = (s1 + buf[n]) % 65521;
       s2 = (s2 + s1)     % 65521;
    }
    return floatround(((s2 << 16) + s1)/100000);
}