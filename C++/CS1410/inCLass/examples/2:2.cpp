// sscanf <--- this is good for comparisons

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main(int argc, char** pArgv)
{
	// Parse comman-line for file name

	printf("This programs name is %s\n", pArgv[0]);

	if(argc > 1)
	{
		std::ofstream is;
		string myString(pArgv[1]);



		is.open(pArgv[1], std::ifstream::out);

		if(is.is_open())
		{
			printf("The file is now opened: %s\n", pArgv[1]);
			is << "Something more";
			is.close();
		}
	}
	else
	{
		printf("Usage\n %s [filename]\n", pArgv[0]);
	}

}