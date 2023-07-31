/*
*
*
*  PawnScript Plugin
*
*  (c) DEntisT
*
*
*/


PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)
{
    pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
    logprintf = (logprintf_t) ppData[PLUGIN_DATA_LOGPRINTF];

    pawnscriptprint("System loaded.");
    return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
    pawnscriptprint("System unloaded.");
}
