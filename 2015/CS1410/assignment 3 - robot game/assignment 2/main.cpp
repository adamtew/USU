#include "RobotGame.hpp"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void firstLine(string rFileName, string& rName, int& rRow, int& rCol);
int convert(string rVal);

int main(int argc, char** pArgv)
{
	int row, col;
	string line;
	
	if (argc > 1)
	{
		firstLine(pArgv[1], line, row, col);
		RobotGame robot(row, col);
		robot.openFile(pArgv[1]);
		robot.makeMap();

		char interactive[] = "INTERACTIVE_MAP";
		if (!strcmp(line.c_str(), interactive))
		{
			robot.interactivePlay();
		}
		else
		{
			robot.play();
		}
	}
	else
	{
		cout << "\nSorry, there were no arguments.";
		cout << "\nTo use this program enter a map file as an argument";
		cout << "\n\n" << pArgv[0] << " [filename]";
		cout << "\n\nExample: " << pArgv[0] << " map.txt";
	}

	return 0;
}

void firstLine(string rFileName, string& rName, int& rRow, int& rCol)
{
	ifstream file(rFileName);
	if (file.is_open())
	{
		file >> rName;
		file >> rRow;
		file >> rCol;
		
		file.close();
	}
	else
	{
		printf("Please enter the correct file name: ");
	}
}
