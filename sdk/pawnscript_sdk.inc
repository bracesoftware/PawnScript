/*

The ORIGINAL CODE is the `PawnScript SDK` Source Code.
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

#pragma semicolon 1
#include <open.mp>

//Decorator for internal stuff
#define @PAWNSCRIPT_N_DECO@%0\32; @PAWNSCRIPT_N_DECO@
#define @pawnscript_sdk%0(%1) @PAWNSCRIPT_N_DECO@
#define @PAWNSCRIPT_N_DECO@print%0(%1) printf("[PawnScript] SERVER THREAD :: SDK - Info: "%1)
#define @PAWNSCRIPT_N_DECO@err%0(%1) printf("[PawnScript] SERVER THREAD :: SDK - Info: "%1)
//Natives
/*
native CallPawnScriptFunction(name[], args[]);
*/
#define CallPawnScriptFunction%1(%0) 	CallRemoteFunction("PS_CallRemoteFunction","ss",%0)
/*
native CallPawnScriptCallback(name[], args[]);
*/
#define CallPawnScriptCallback%1(%0) 	CallRemoteFunction("PS_Callback","ss",%0)
/*
native IsValidPawnScriptFunction(name[]);
*/
#define IsValidPawnScriptFunction%1(%0) 	CallRemoteFunction("_PS_N@IsFuncValid","s",%0)

// This is internal function! DONT CHANGE THE NAME
__pawnscript_sdk(); public __pawnscript_sdk()
{
	if(IsValidPawnScriptFunction("randshit::lol"))
	{
		@pawnscript_sdk() err("randshit::lol is valid!!!111");
	}
	if(IsValidPawnScriptFunction("test::__eat"))
	{
		@pawnscript_sdk() print("test::__eat is valid!!!111");
	}
	if(IsValidPawnScriptFunction("MeAgain.eat"))
	{
		@pawnscript_sdk() print("MeAgain.eat is valid!!!111");
	}
	return 0b01010010101001;
}