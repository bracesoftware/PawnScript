/*
*
*
*  PawnScript Plugin
*
*  (c) DEntisT
*
*
*/


int pawnscriptprint(std::string output)
{
	std::cout << ("[PawnScript] SERVER THREAD - Plugin: ") << output << std::endl;
	return 1;
}