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

#define dpp_graphics_major 0
#define dpp_graphics_minor 0
#define dpp_graphics_patch 1

#define GRAPHICS_ROWS 5
#define GRAPHICS_COLUMNS 5

new dpp_graphics_grid__[GRAPHICS_ROWS][GRAPHICS_COLUMNS];

// Setup

dpp_graphics__init(); // Initialize the screen.
dpp_graphics__show(); // Show the screen.
dpp_graphics__showpixel(row, column); // Show pixel.
dpp_graphics__cls(); // Clean the screen.

// Functions
public dpp_graphics__init() //Internal
{
	for(new i; i < GRAPHICS_ROWS; i++)
	{
		format(dpp_graphics_grid__[i], GRAPHICS_COLUMNS, "\n");
	}
	for(new i; i < GRAPHICS_ROWS; i++)
	{
		for(new j; j < GRAPHICS_COLUMNS; j++)
		{
			dpp_graphics_grid__[i][j] = '-';
		}
	}
	dpp_gprint("Graphics grid has been initialized.");
	return 1;
}

public dpp_graphics__show()
{
	printf("\tPawnScript: Graphics Mode\t\t\tVersion: [Gs%i]",
		DPP_VERSION_GS);
	printf("\t[Rows: %i\t\tColumns: %i]",GRAPHICS_ROWS,GRAPHICS_COLUMNS);

	for(new i; i < GRAPHICS_ROWS; i++)
	{
		print(dpp_graphics_grid__[i]);
	}

	printf("\tPowered by: Pawn\t\t\t\tRelease: %d.%02d.%02d", __Pawn >>> 8, __Pawn & 0xFF, __PawnBuild);
	return 1;
}

public dpp_graphics__showpixel(row, column)
{
	if(row == 0)
	{
		dpp_gerror("System encountered an error.");
		return 1;
	}
	if(column == 0)
	{
		dpp_gerror("System encountered an error.");
		return 1;
	}
	if(row > GRAPHICS_ROWS)
	{
		dpp_gerror("System encountered an error.");
		return 1;
	}
	if(column > GRAPHICS_COLUMNS)
	{
		dpp_gerror("System encountered an error.");
		return 1;
	}
	printf("__showpixel\t\targs[0] : '%i'\targs[1] : '%i'", row,column);
	dpp_graphics_grid__[row-1][column-1] = '+';
	return 1;
}

public dpp_graphics__cls()
{
	for(new i; i < GRAPHICS_ROWS; i++)
	{
		for(new j; j < GRAPHICS_COLUMNS; j++)
		{
			dpp_graphics_grid__[i][j] = '-';
		}
	}
	dpp_gprint("Graphics grid is clean.");
	return 1;
}