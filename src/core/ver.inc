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

#if defined RELEASE_FILTERSCRIPT
#define DPP_VERSION_TYPE		"FS"
#else
#define DPP_VERSION_TYPE		"MS"
#endif
#define DPP_VERSION_MAJOR 		1
#define DPP_VERSION_MINOR 		2
#define DPP_VERSION_PATCH 		0
//dpp_genver__()
#define DPP_VERSION_RELEASE 	"u"
//dpp_genver__()*2
#define DPP_VERSION_GS			1

new dpp_vers_string__[100];

dpp_genvers__()
{
	//DPP_VERSION_TYPE,DPP_VERSION_MAJOR,DPP_VERSION_MINOR,DPP_VERSION_PATCH,DPP_VERSION_RELEASE,DPP_VERSION_GS

	format(dpp_vers_string__, sizeof dpp_vers_string__, "%s %i%i%i%s-Gs%i",
		DPP_VERSION_TYPE,
		DPP_VERSION_MAJOR,
		DPP_VERSION_MINOR,
		DPP_VERSION_PATCH,
		DPP_VERSION_RELEASE,
		DPP_VERSION_GS);

	return 1;
}

void:dpp_verinfo__()
{
	printf("\tPawnScript   %s\tBrace Inc.", dpp_vers_string__);
    printf("\tPawn         %d.%02d.%02d\t\tITB CompuPhase", __Pawn >>> 8, __Pawn & 0xFF, __PawnBuild/*__pawn_build*/); // from YSI
}

/*
DEntisT versioning system
=========================

Firstly, we must know if the code is a filterscript or mainscript, 
that's what the FS or MS prefixes do.

Now, we need a product version which consists of 3 digits, and that's
x 	-	Major vers number
y 	-	Minor vers number
z 	-	Patch number

Afterwards, we get a suffix:
t 	-	testing phase
s 	-	stable
u 	-	unstable

And lastly, we have a release of the graphics system.
-GsX
where X is a number starting from 1.

Example:

PawnScript MS 245u-Gs3

PawnScript interpreter made for gamemode, major release 2 , minor release 4,
patch number 5. This is an unstable version. Graphics system is at release 3.

*/