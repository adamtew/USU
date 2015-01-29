// Command line arguments
// int main(int argc, char** pArgv)
// pArgv is an array of strigns
// first arguments is the program name
// 
// Remember that you need to use position 0 for the program name
// 
// 
// String function names:
// strlen <-- get length of a c string, include <string.h
// strcpy <-- copy a string from one var to another
// strncpy <-- it's like string copy but it can't be buffer overflow attacked as easily

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(int argc, char** pArgv)
{

	if(argc > 1)
	{
		// std::string filename = pArgv[1];		
		int stringLength = strlen(pArgv[1]);
		char* pFilename = new char[stringLength + 1];

		strcpy(pFilename, pArgv[1]);
		

		// pArgv[1];

		// printf("The filename is %s\n", filename.c_str());
	}
	else
	{
		printf("You have failed\n");
		printf("You need to use %s:\n %s [filename]\n", pArgv[0], pArgv[0]);
	}
	return 0;
}