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
    pawnscriptprint("System is ready to use.");
    return 1;
}