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


new dpp_ignoreline=0,File:dpp_indexhandle;
//@_
#define PS_LOGDIR "$ps_log"
#define SCRIPT_EXT ".ps"
#define LOG_EXT ".pslog"
#define STACKOUTPUT_FILE PS_LOGDIR"/stackoutput"LOG_EXT
#define PROJECT_NAME "PawnScript"
#define PSDATA_DIRNAME "$ps_data"

//-----------------------------------------------------------
#define dpp_invalidclass 100
//-----------------------------------------------------------
#define DPP_CELLMAX 8

#define DPP_VERSION_BETA 1

#define DPP_LOG_FILE PS_LOGDIR"/pawnscript"LOG_EXT
//-----------------------------------------------------------
#define DPP_INVALID_INLINE_ID 0
#define DPP_INVALID_FORM_ID -1
#define DPP_INVALID_TASK_ID -1
#define DPP_INVALID_ENUM_ID -1
#define DPP_INVALID_OBJECT_ID -1
//-----------------------------------------------------------
#define DPP_DEBUG 1
#define DPP_BRACES 0
//-----------------------------------------------------------
#define dpp_maxcodelines 2048
#define dpp_maxformatlen 2048
#define dpp_maxpathsize 256
//-----------------------------------------------------------
#define dpp_maxformargs 15
//-----------------------------------------------------------
// Constant values (used for initial memory allocation)
#define dpp_entities__ 17
#define dpp_rescells__ 255

#define dpp_maxconst__ dpp_rescells__
#define dpp_maxfuncs__ dpp_rescells__
#define dpp_maxinline__ dpp_rescells__
#define dpp_maxvar__ dpp_rescells__
#define dpp_maxclass__ dpp_rescells__
#define dpp_maxtasks__ dpp_rescells__
#define dpp_maxiter__ dpp_rescells__
#define dpp_maxtag__ dpp_rescells__
#define dpp_maxtypedef__ dpp_rescells__
#define dpp_maxenum__ dpp_rescells__
#define dpp_maxobj__ dpp_rescells__
#define dpp_maxoclass__ dpp_rescells__
#define dpp_maxtemplate__ dpp_rescells__
#define dpp_maxvector__ dpp_rescells__
#define dpp_maxptr__ dpp_rescells__
#define dpp_maxstk__ dpp_rescells__
#define dpp_maxbitarr__ dpp_rescells__
// Variables with max values of constants above.
// Used in #pragma to select amount of memory used for each entity.
new dpp_maxconst        = dpp_maxconst__;
new dpp_maxfuncs        = dpp_maxfuncs__;
new dpp_maxinline       = dpp_maxinline__;
new dpp_maxvar          = dpp_maxvar__;
new dpp_maxclass        = dpp_maxclass__;
new dpp_maxtasks        = dpp_maxtasks__;
new dpp_maxiter         = dpp_maxiter__;
new dpp_maxtag          = dpp_maxtag__;
new dpp_maxtypedef      = dpp_maxtypedef__;
new dpp_maxenum         = dpp_maxenum__;
new dpp_maxobj          = dpp_maxobj__;
new dpp_maxoclass       = dpp_maxoclass__;
new dpp_maxtemplate     = dpp_maxtemplate__;
new dpp_maxvector       = dpp_maxvector__;
new dpp_maxptr          = dpp_maxptr__;
new dpp_maxstk          = dpp_maxstk__;
new dpp_maxbitarr       = dpp_maxbitarr__;
dpp_memory__dyn(dyn)
{
if(dyn>dpp_rescells__)
{
dyn=dpp_rescells__; // Avoid invalid memory addresses and instructions.
}
dpp_maxconst            = dyn;
dpp_maxfuncs            = dyn;
dpp_maxinline           = dyn;
dpp_maxvar              = dyn;
dpp_maxclass            = dyn;
dpp_maxtasks            = dyn;
dpp_maxiter             = dyn;
dpp_maxtag              = dyn;
dpp_maxtypedef          = dyn;
dpp_maxenum             = dyn;
dpp_maxobj              = dyn;
dpp_maxoclass           = dyn;
dpp_maxtemplate         = dyn;
dpp_maxvector           = dyn;
dpp_maxptr              = dyn;
dpp_maxstk              = dyn;
dpp_maxbitarr           = dyn;
#emit const.pri 1
#emit retn
}
//-----------------------------------------------------------
#define dpp_maxenumvals 100
//-----------------------------------------------------------
#define dpp_maxitersize 1000
#define dpp_maxvectorsize 5000
#define dpp_maxstksize 100
#define dpp_invaliditerval -1
#define dpp_invalidvectorval -1

#define dpp_stkaddrsize 10
#define dpp_invalidstkval "PSSTK"
//-----------------------------------------------------------
#define dpp_argcharsize 100
//-----------------------------------------------------------
#define dpp_const_type_int 1
#define dpp_const_type_bool 2
#define dpp_const_type_str 3
#define dpp_const_type_double 4
#define dpp_const_type_char 5
//-----------------------------------------------------------
#define dpp_var_type_int 1
#define dpp_var_type_bool 2
#define dpp_var_type_str 3
#define dpp_var_type_double 4
#define dpp_var_type_char 5
//-----------------------------------------------------------
#define dpp_rtn_type_void 0
#define dpp_rtn_type_int 1
#define dpp_rtn_type_bool 2
#define dpp_rtn_type_str 3
#define dpp_rtn_type_double 4
#define dpp_rtn_type_char 5
//-----------------------------------------------------------
#define DPP_LOGPROCESSES 0
//-----------------------------------------------------------
#define dpp_maxsymbolchar 64
#define dpp_maxstrsize 256
#define dpp_maxargsc 20

#define dpp_buffersize 1024
//-----------------------------------------------------------
new dpp_skipelse = 0;
//-----------------------------------------------------------
//new dpp_skipcase = 0;
new dpp_switchedvar;
//-----------------------------------------------------------
#define dpp_deco_invalid 0
#define dpp_deco_hook 1
#define dpp_deco_method 2
#define dpp_deco_task 3
#define dpp_deco_yield 4
#define dpp_deco_extern 5
#define dpp_deco_export 6
#define dpp_deco_import 7
#define dpp_deco_quiet 8
new dpp_lastdeco = dpp_deco_invalid;
//-----------------------------------------------------------
// PREDEFINES
//-----------------------------------------------------------
#define dpp_null "null"
#define dpp_null__ " "

#define dpp_event_form 0
#define dpp_event_task 1
#define dpp_event_class 2
#define dpp_event_inline 3
#define dpp_event_enum 4
#define dpp_event_namespace 5
#define dpp_event_case 6

#define dpp_event_do 10
#define dpp_event_if 11
#define dpp_event_try 12

#define dpp_event_using 15
#define dpp_event_REQUIRES@samp 16
//-----------------------------------------------------------
#define DPP_INPUT_TYPE_NONE 0
#define DPP_INPUT_TYPE_LINE 1
#define DPP_INPUT_TYPE_CHAR 2
//-----------------------------------------------------------
//PawnScriptASM
#define dpp_memsec_var 1
//-----------------------------------------------------------
#define dpp_operandsize 64
#define dpp_shortlim 65535
#define DPP_INVALID_STACK_VALUE 65535
#define DPP_BRACE_STACK_SIZE 10
new dpp_bracestack[DPP_BRACE_STACK_SIZE];
new dpp_bracestack__2[DPP_BRACE_STACK_SIZE];
//-----------------------------------------------------------
#define dpp_defaultretvar (dpp_rescells__-1)
new dpp_retvar__ = dpp_defaultretvar;
//-----------------------------------------------------------
//new content[16000];
//new subcontent[16000];
//-----------------------------------------------------------
new dpp_tryinterpreter = 1;
new dpp_trycodeblock[dpp_buffersize];
//-----------------------------------------------------------
new dpp_lastvalueprcfunc;
//-----------------------------------------------------------
new dpp_enuminterpreter = 1;
new dpp_currentenumid = -1;
new dpp_nextenumval = 0;

new dpp_validenum[dpp_maxenum__];
new dpp_enumname[dpp_maxenum__][dpp_maxsymbolchar];
enum __dpp_valcache
{
    e_valid,
    e_valname[dpp_maxsymbolchar],
    e_value
}
new dpp_enumvalues[dpp_maxenum__][dpp_maxenumvals][__dpp_valcache];
new dpp_enumconstexpr[dpp_maxenum__];
//-----------------------------------------------------------
new dpp_validtypedef[dpp_maxtypedef__];
new dpp_typedefname[dpp_maxtypedef__][dpp_maxstrsize];
new dpp_typedefrepl[dpp_maxtypedef__][dpp_maxstrsize];
//-----------------------------------------------------------
new dpp_validtemplate[dpp_maxtemplate__];
new dpp_templatename[dpp_maxtemplate__][dpp_maxstrsize];
new dpp_templaterepl[dpp_maxtemplate__][dpp_maxstrsize];
//-----------------------------------------------------------
enum dpp_enumset
{
    console_comp,
    system_comp,
    samp_comp,
    math_comp,
    files_comp,
    misc_comp,
    data_comp,
    pawn_comp,
    iter_comp,
    vector_comp,
    graphics_comp,
    stk_comp,
    bitarr_comp,
    //samp,
    @global_comp
}

new dpp_config[dpp_enumset];
enum dpp_enumset2
{
    samp@api_module
}
new dpp_config__[dpp_enumset2];
//-----------------------------------------------------------
//const
enum __dpp_const_val
{
    const_valid,
    const_name[dpp_maxsymbolchar],
    const_type,
    integervalue,
    /*bool:*/boolvalue,
    Float:floatvalue,
    stringvalue[dpp_maxstrsize],
    charvalue
}
new dpp_constdata[dpp_maxconst__][__dpp_const_val];
//-----------------------------------------------------------
//vars
new dpp_setregister__ = 0;
enum __dpp_var_val
{
    var_valid,
    var_name[dpp_maxsymbolchar],
    var_type,
    var_object,
    var_unsigned,
    var_short,
    var_byte,
    var_register,
    integervalue,
    /*bool:*/boolvalue,
    Float:floatvalue,
    stringvalue[dpp_maxstrsize],
    charvalue,
    //func
    var_static,
    var_baseformid
}

new dpp_vardata[dpp_maxvar__][__dpp_var_val];
//pointers >:)
enum __dpp_ptr_E
{
    ptr_valid,
    ptr_name[dpp_maxsymbolchar],
    ptr_cell,
    ptr_memsec
}

new dpp_ptrdata[dpp_maxptr__][__dpp_ptr_E];
//-----------------------------------------------------------
//inline
new dpp_inlineinterpreter = 1;
new dpp_currentinlineid = DPP_INVALID_INLINE_ID;
new dpp_validinline[dpp_maxinline__];
new dpp_inlinebaseform[dpp_maxinline__];
new dpp_inlinename[dpp_maxinline__][dpp_maxsymbolchar];
new dpp_inlinecodeblock[dpp_maxinline__][dpp_buffersize];
//-----------------------------------------------------------
//tasks
new dpp_internaltasks[dpp_maxtasks__];

new dpp_taskinterpreter = 1;
new dpp_currenttaskid = DPP_INVALID_TASK_ID;
new dpp_validtask[dpp_maxtasks__];
new dpp_taskname[dpp_maxtasks__][dpp_maxsymbolchar];
new dpp_taskcodeblock[dpp_maxtasks__][dpp_buffersize];
new dpp_interval[dpp_maxtasks__];
new dpp_repeat[dpp_maxtasks__];
//-----------------------------------------------------------
//iterators
new dpp_validiter[dpp_maxiter__];
new dpp_itername[dpp_maxiter__][dpp_maxsymbolchar];
new dpp_itersize[dpp_maxiter__];
new dpp_itervalues[dpp_maxiter__][dpp_maxitersize];
//vectors
new dpp_validvector[dpp_maxvector__];
new dpp_vectorname[dpp_maxvector__][dpp_maxsymbolchar];
new dpp_vectorsize[dpp_maxvector__]; // Completely irrelevant.
new dpp_vectorvalues[dpp_maxvector__][dpp_maxvectorsize];
//stack
new dpp_validstk[dpp_maxstk__];
new dpp_stkname[dpp_maxstk__][dpp_maxsymbolchar];
new dpp_stksize[dpp_maxstk__];
new dpp_stkvalues[dpp_maxstk__][dpp_maxstksize][dpp_stkaddrsize];
//-----------------------------------------------------------
//classes and objects
new dpp_currentobject = DPP_INVALID_OBJECT_ID;
new dpp_usedclassid;
new dpp_oclassinterpreter = 1;

new dpp_validobject[dpp_maxobj__];
new dpp_objectname[dpp_maxobj__][dpp_maxsymbolchar];

new dpp_validoclass[dpp_maxoclass__];
new dpp_oclassname[dpp_maxoclass__][dpp_maxsymbolchar];
new dpp_oclassblock[dpp_maxoclass__][dpp_buffersize];
//-----------------------------------------------------------
//bunch of crap
new dpp_currentfuncid = DPP_INVALID_FORM_ID;
new dpp_validfunc[dpp_maxfuncs__];
new dpp_funcname[dpp_maxfuncs__][dpp_maxsymbolchar];
new dpp_funccodeblock[dpp_maxfuncs__][dpp_buffersize];
new dpp_autoform[dpp_maxfuncs__];
new dpp_hookform[dpp_maxfuncs__];
new dpp_structtype[dpp_maxfuncs__];
new dpp_methodform[dpp_maxfuncs__];
new dpp_privatefunc[dpp_maxfuncs__];
new dpp_virtualfunc[dpp_maxfuncs__];
new dpp_setprivate__ = 0;
new dpp_setvirtual__ = 0;
enum __dpp_argcache
{
    dpp_argname[dpp_maxsymbolchar/2],
    dpp_argvalue[dpp_buffersize/2]
}
new dpp_args[dpp_maxfuncs__][dpp_maxformargs][__dpp_argcache];
//-----------------------------------------------------------
new dpp_validclass[dpp_maxclass__];
new dpp_classconstexpr[dpp_maxclass__];
new dpp_classname[dpp_maxclass__][dpp_maxsymbolchar];
new dpp_workingclassid = dpp_invalidclass;
//-----------------------------------------------------------
new dpp_funcreturn_int[dpp_maxfuncs__];
new dpp_funcreturn_bool[dpp_maxfuncs__];
new dpp_funcreturn_str[dpp_maxfuncs__][dpp_buffersize/2];
new Float:dpp_funcreturn_double[dpp_maxfuncs__];
new dpp_funcreturn_char[dpp_maxfuncs__];
//-----------------------------------------------------------
//tags
new dpp_objectid = -1;
new dpp_isobjinit = 0;
new dpp_validobj[dpp_maxtag__];
new dpp_objname[dpp_maxtag__][dpp_maxsymbolchar];
//-----------------------------------------------------------
new dpp_returned[dpp_maxfuncs__];
new dpp_returntype[dpp_maxfuncs__];
//-----------------------------------------------------------
new dpp_processfunc = DPP_INVALID_FORM_ID;
new dpp_isconditional = 0;
//-----------------------------------------------------------
new dpp_interpreter = 1;
//-----------------------------------------------------------
new File:dpp_filehandle;
new dpp_fhandleused = 0;
//-----------------------------------------------------------
// project config

new dpp_projname[128];
new dpp_stackoutput = 0;
new dpp_projvers[128];
//-----------------------------------------------------------
// process cache

new dpp_terminated = 0;
new dpp_sysreturned = 0;

new dpp_warningcount = 0;
new dpp_errorcount = 0;
//-----------------------------------------------------------
//OPTIONS

new dpp_option_debug = 0;
new dpp_option_warnings = 1;
new dpp_option_hooking = 1;
new dpp_option_escapechar = '\\';
new dpp_option_allspc = 0;
new dpp_option_reqref = 0; 
//-----------------------------------------------------------
// data
new dpp_compiling_pass = 1;
new dpp_compiled = 0;
new dpp_lastclass;
// do and end
new dpp_event = 0;

new dpp_failedif = 0;
new dpp_failedcase = 0;
//-----------------------------------------------------------
new 
    dpp_break=0, 
    dpp_continue=0;
//-----------------------------------------------------------
new dpp_inputtype=DPP_INPUT_TYPE_NONE;
new dpp_inputdest;
//-----------------------------------------------------------
// Fake registers:
new dpp_pri__, dpp_alt__, dpp_tmp;
new dpp_bytes__;
#pragma unused dpp_bytes__
new dpp_tempaddr__[dpp_maxstrsize];
new dpp_tempreg__;
new Float:dpp_tempfloat__;
//-----------------------------------------------------------
#define dpp_numinvchar__ 38

new dpp_invchar__[dpp_numinvchar__] = {
    '?', 
    '+', 
    '-', 
    '*', 
    '/', 
    '\\', 
    ':', 
    '(', 
    ')', 
    '{', 
    '}', 
    '[', 
    ']',
    '&',
    '%',
    '=',
    '$',
    '#',
    '^',
    'ˇ',
    '!',
    '~',
    '`',
    '\'',
    '\"',
    '˝',
    '˛',
    '°',
    '˘',
    '¸',
    '.',
    ',',
    '\32',
    '\t',
    '¤',
    '˙',
    '´'
};
//-----------------------------------------------------------
#define DPP_STKSIZE dpp_entities__*dpp_rescells__
#define DPP_STKNULL "PS__null__"
new dpp_stkreg[DPP_STKSIZE][dpp_maxsymbolchar];
#define tempaddr 0
#define tempreg 1
#define tempfloat 2
#define stk@push 3
#define stk@pop 4
#define stk@allcol 5
new dpp_allowcollision;
#define @emit__%0\32;%1\10;%3 dpp_asm__(%1);
//-----------------------------------------------------------
#define dpp_maxkwords 63
new dpp_kwords[dpp_maxkwords][256] = {
    "public",
    "default",
    "enum",
    "class",
    "inline",
    "namespace",
    "switch",
    "case",
    "final",
    "const",
    "static",
    "new",
    "int",
    "bool",
    "quiet",
    "str",
    "double",
    "byte",
    "char",
    "void",
    "using",
    "return",
    "@method",
    "@hook",
    "extern",
    "struct",
    "@task",
    "for",
    "foreach",
    "while",
    "do",
    "try",
    "explicit",
    "union",
    "tag",
    "break",
    "continue",
    "template",
    "typedef",
    "exit",
    "user",
    "if",
    "else",
    "tagof",
    "sizeof",
    "addressof",
    "short",
    "unsigned",
    "include",
    "undef",
    "pragma",
    "emit",
    "defined",
    "iterator",
    "vector",
    "@export",
    "@import",
    "stack",
    "true",
    "false",
    "this",
    "interval",
    "repeat"
};
//-----------------------------------------------------------
new dpp_interval__;
new dpp_repeat__=1;
//-----------------------------------------------------------
#define dpp_persdatasize 32
new dpp_typename__[dpp_persdatasize];
new dpp_from__[dpp_persdatasize];
new dpp_to__[dpp_persdatasize];
//-----------------------------------------------------------
new dpp_usingfor__ = 0;
#define dpp_comp_console 1
#define dpp_comp_system 2
#define dpp_comp_math 3
#define dpp_comp_files 4
#define dpp_comp_misc 5
#define dpp_comp_data 6
#define dpp_comp_pawn 7
#define dpp_comp_iter 8
#define dpp_comp_vec 9
#define dpp_comp_graphics 10
#define dpp_comp_stk 11
#define dpp_comp_bitarr 12
//samp
#define dpp_comp_@global 100
new dpp_compusedfor__ = 0;
//-----------------------------------------------------------
new dpp_deprecated__=1;
//-----------------------------------------------------------
new dpp_speedhz=0;
//-----------------------------------------------------------
new dpp_curpath[dpp_maxpathsize];
new dpp_moduledir[dpp_maxpathsize];
//-----------------------------------------------------------
#define dpp_formstruct_local 0
#define dpp_defaultstruct 1
#define dpp_callbackstruct 2
new dpp_structtype__;
//-----------------------------------------------------------
#define dpp_maxbitarrsize__ 100
enum __e_dpp_bitarr
{
    bitarr_valid,
    bitarr_name[dpp_maxsymbolchar],
    bitarr_size,
    bitarr_value[dpp_maxbitarrsize__]
}
new dpp_bitarrdata[dpp_maxbitarr__][__e_dpp_bitarr];
//-----------------------------------------------------------
#define dpp_unmsize 32
new dpp_currentunion[dpp_unmsize];
new dpp_currentunionreq[dpp_unmsize];
new dpp_explicit__ = 0;