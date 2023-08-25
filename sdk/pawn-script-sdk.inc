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

#define PS_CallPublicFunction(%0) 	CallRemoteFunction("PS_CallRemoteFunction","ss",%0)

__ps_sdktest();
public __ps_sdktest()
{
	print("[PawnScript] SDK LOADED");
	PS_CallPublicFunction("TestFuncForAPI","1923,\"some text\"");
	return 1;
}