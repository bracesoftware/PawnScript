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

#define dpp_pers__%0	%0;


/*
*
*
*
* INTEGERS
*
*
*
*/

//import*int,"dataname",dest;
stock dpp_importint(const name[], varid)
{
	new file_name[150];
	format(file_name, sizeof file_name,
		PSDATA_DIRNAME"/var_%s.pspdmf", name);

	new exporteddata[128];

	format(exporteddata, sizeof exporteddata, dpp_null);

	new File:file = fopen(file_name, io_read);
	if (file)
	{
		fread(file, exporteddata);

		fclose(file);

		dpp_vardata[varid][integervalue] = strval(exporteddata);
		//dpp_warning("Imported [varid: '%i'] '%s' [val: '%i']: '%s'",varid,name,strval(exporteddata),exporteddata);

		return 1;
	}
	dpp_vardata[varid][integervalue] = 0;
	return 1;
}

//export*int,"name",value;
stock dpp_exportint(const name[], value)
{
	new file_name[150], datatowrite[150];
	format(file_name, sizeof file_name,
		PSDATA_DIRNAME"/var_%s.pspdmf", name);

	new File:file = fopen(file_name, io_write);

	format(datatowrite, sizeof datatowrite, 
		"%i", value);

	fwrite(file, datatowrite);
	fclose(file);

	//dpp_warning("Exported '%s' [val: '%i']: '%s'",name,value,datatowrite);
	return 1;
}



/*
*
*
*
* BOOLEANS
*
*
*
*/

//import*int,"dataname",dest;
stock dpp_importbool(const name[], varid)
{
	new file_name[150];
	format(file_name, sizeof file_name,
		PSDATA_DIRNAME"/var_%s.pspdmf", name);

	new exporteddata[128];

	format(exporteddata, sizeof exporteddata, dpp_null);

	new File:file = fopen(file_name, io_read);
	if (file)
	{
		fread(file, exporteddata);

		fclose(file);

		dpp_vardata[varid][boolvalue] = strval(exporteddata);
		//dpp_warning("Imported [varid: '%i'] '%s' [val: '%i']: '%s'",varid,name,strval(exporteddata),exporteddata);

		return 1;
	}
	dpp_vardata[varid][boolvalue] = 0;
	return 1;
}

//export*int,"name",value;
stock dpp_exportbool(const name[], value)
{
	new file_name[150], datatowrite[150];
	format(file_name, sizeof file_name,
		PSDATA_DIRNAME"/var_%s.pspdmf", name);

	new File:file = fopen(file_name, io_write);

	format(datatowrite, sizeof datatowrite, 
		"%i", value);

	fwrite(file, datatowrite);
	fclose(file);

	//dpp_warning("Exported '%s' [val: '%i']: '%s'",name,value,datatowrite);
	return 1;
}




/*
*
*
*
* STRINGs
*
*
*
*/

//import*int,"dataname",dest;
stock dpp_importstr(const name[], varid)
{
	new file_name[150];
	format(file_name, sizeof file_name,
		PSDATA_DIRNAME"/var_%s.pspdmf", name);

	new exporteddata[128];

	format(exporteddata, sizeof exporteddata, dpp_null);

	new File:file = fopen(file_name, io_read);
	if (file)
	{
		fread(file, exporteddata);

		fclose(file);

		strmid(dpp_vardata[varid][stringvalue],exporteddata,0,dpp_maxstrsize,dpp_maxstrsize);
		//dpp_warning("Imported [varid: '%i'] '%s' [val: '%i']: '%s'",varid,name,strval(exporteddata),exporteddata);

		return 1;
	}
	strmid(dpp_vardata[varid][stringvalue], dpp_null, 0, dpp_maxstrsize,dpp_maxstrsize);
	return 1;
}

//export*int,"name",value;
stock dpp_exportstr(const name[], const value[])
{
	new file_name[150], datatowrite[150];
	format(file_name, sizeof file_name,
		PSDATA_DIRNAME"/var_%s.pspdmf", name);

	new File:file = fopen(file_name, io_write);

	format(datatowrite, sizeof datatowrite, 
		"%s", value);

	fwrite(file, datatowrite);
	fclose(file);

	//dpp_warning("Exported '%s' [val: '%i']: '%s'",name,value,datatowrite);
	return 1;
}




/*
*
*
*
* DOUBLES
*
*
*
*/

//import*int,"dataname",dest;
stock dpp_importdouble(const name[], varid)
{
	new file_name[150];
	format(file_name, sizeof file_name,
		PSDATA_DIRNAME"/var_%s.pspdmf", name);

	new exporteddata[128];

	format(exporteddata, sizeof exporteddata, dpp_null);

	new File:file = fopen(file_name, io_read);
	if (file)
	{
		fread(file, exporteddata);

		fclose(file);

		dpp_vardata[varid][floatvalue] = floatstr(exporteddata);
		//dpp_warning("Imported [varid: '%i'] '%s' [val: '%i']: '%s'",varid,name,strval(exporteddata),exporteddata);

		return 1;
	}
	dpp_vardata[varid][floatvalue] = 0.0;
	return 1;
}

//export*int,"name",value;
stock dpp_exportdouble(const name[], Float:value)
{
	new file_name[150], datatowrite[150];
	format(file_name, sizeof file_name,
		PSDATA_DIRNAME"/var_%s.pspdmf", name);

	new File:file = fopen(file_name, io_write);

	format(datatowrite, sizeof datatowrite, 
		"%f", value);

	fwrite(file, datatowrite);
	fclose(file);

	//dpp_warning("Exported '%s' [val: '%i']: '%s'",name,value,datatowrite);
	return 1;
}



/*
*
*
*
* CHARS
*
*
*
*/

//import*int,"dataname",dest;
stock dpp_importchar(const name[], varid)
{
	new file_name[150];
	format(file_name, sizeof file_name,
		PSDATA_DIRNAME"/var_%s.pspdmf", name);

	new exporteddata[128];

	format(exporteddata, sizeof exporteddata, dpp_null);

	new File:file = fopen(file_name, io_read);
	if (file)
	{
		fread(file, exporteddata);

		fclose(file);

		dpp_vardata[varid][charvalue] = exporteddata[0];
		//dpp_warning("Imported [varid: '%i'] '%s' [val: '%i']: '%s'",varid,name,strval(exporteddata),exporteddata);

		return 1;
	}
	dpp_vardata[varid][charvalue] = '0';
	return 1;
}

//export*int,"name",value;
stock dpp_exportchar(const name[], value)
{
	new file_name[150], datatowrite[150];
	format(file_name, sizeof file_name,
		PSDATA_DIRNAME"/var_%s.pspdmf", name);

	new File:file = fopen(file_name, io_write);

	format(datatowrite, sizeof datatowrite, 
		"%c", value);

	fwrite(file, datatowrite);
	fclose(file);

	//dpp_warning("Exported '%s' [val: '%i']: '%s'",name,value,datatowrite);
	return 1;
}

