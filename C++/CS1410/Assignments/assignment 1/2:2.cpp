#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** pArgv)
{
	// Parse comman-line for file name

	printf("This programs name is %s\n", pArgv[0]);

	if(argc > 1)
	{

	}
	else
	{
		printf("Usaage\n %s [filename]\n", pArgv[0]);
	}

}