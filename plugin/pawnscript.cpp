/*
*
*
*  PawnScript Plugin
*
*  (c) DEntisT, Brace Inc.
*
*
*/


#include <iostream>
#include <string>

#include "sdk\amx\amx.h"
#include "sdk\plugincommon.h"

#include "util.cpp"

typedef void (*logprintf_t)(const char* format, ...);
logprintf_t logprintf;
extern void *pAMXFunctions;


#include "init.cpp"

#include "natives.cpp"

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

AMX_NATIVE_INFO PluginNatives[] =
{
    {"IsPawnScriptLoaded", IsPawnScriptLoaded},
    {0, 0}
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad( AMX *amx )
{
    return amx_Register(amx, PluginNatives, -1);
}


PLUGIN_EXPORT int PLUGIN_CALL AmxUnload( AMX *amx )
{
    return AMX_ERR_NONE;
}