/*
*
*
*  PawnScript Plugin
*
*  (c) DEntisT
*
*
*/


cell AMX_NATIVE_CALL IsPawnScriptLoaded(AMX* amx, cell* params)
{
    logprintf("Loaded!");
    return 1;
}