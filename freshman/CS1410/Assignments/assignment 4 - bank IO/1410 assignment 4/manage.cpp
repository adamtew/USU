#include "Bank.hpp"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** pArgv)
{
	if (argc > 1)
	{
		Bank bank(pArgv[1]);
	}
	else
	{
		cout << "\nThere were no arguments.";
		cout << "\nTo use this program enter an input file and output file as arguments";
		cout << "\n\n" << pArgv[0] << " [input.csv]" << " [output.bnk]";
		cout << "\n\nExample: " << pArgv[0] << " input.csv output.bnk\n\n";

		cout << "\nOr, you can just enter an input (.bnk) file to be searched";
		cout << "\nExample: " << pArgv[0] << " output.bnk";

	}

	return 0;
}