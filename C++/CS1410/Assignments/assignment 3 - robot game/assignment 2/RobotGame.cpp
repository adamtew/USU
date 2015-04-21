#include "RobotGame.hpp"
#include <iostream>
#include <string.h>


#include <fstream>
#include <string>

using namespace std;

					/***************************************************
										CONSTRUCTORS
					***************************************************/

RobotGame::RobotGame()
{

}

RobotGame::RobotGame(int rRows, int rCols)
{
	// Initialize rows and columns
	m_rows = rRows;
	m_cols = rCols;

		// Create strings to compare commands against
	m_rMove = "MOVE";
	m_rPickup = "PICKUP";
	m_rRotate = "ROTATE";
	m_quit = "QUIT";

		// Dynamically allocate memory for the game board
	m_pBoard = new char*[rRows];
	for (int i = 0; i < m_rows; i++)
		m_pBoard[i] = new char[m_cols];

		// Initialize the array to 'x'
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			m_pBoard[i][j] = 'x';

}

				/***************************************************
									DESTRUCTOR
				***************************************************/

RobotGame::~RobotGame()
{
		// Make sure the file is closed
	if (m_file.is_open())
	{
		m_file.close();
	}
		// de-allocate the memory (if it's not null already)
	for (int i = 0; i < m_rows; i++)
		if (m_pBoard[i] != nullptr)
			if (m_pBoard[i] != nullptr)
				m_pBoard[i] = nullptr;


	if (m_pBoard != nullptr)
		delete[] m_pBoard;
}

				/***************************************************
									FILE FUNCTIONS
				***************************************************/

void RobotGame::openFile(std::string rName)
{
	m_file.open(rName);
	if (m_file.is_open())
		cout << "\nFile: " << rName << " opened.\n";
	else
		cout << "\nFile: " << rName << " didn't open.\n";
}

void RobotGame::closeFile()
{
	m_file.close();
}

void RobotGame::loadRow(int row, char* pRowString)
{
	m_file.getline(pRowString, row);
}

void RobotGame::makeMap()
{
	getline(m_file, m_emptyString); // Empty line used to advance past the first row of the file
	for (int i = 0; i < m_rows; i++)
		loadRow(m_cols + 1, m_pBoard[i]);
}

					/***************************************************
									DISPLAY FUNCTIONS
					***************************************************/

void RobotGame::DisplayGameBoard()
{
	m_gCount = m_gSentinel; m_dCount = m_dSentinel;
	cout << "\n\tGame Board:\n\n\t  ";
	for (int i = 0; i < m_cols; i++) cout << i << " ";

	for (int i = 0; i < m_rows; i++)
	{
		cout << "\n\t" << i << " ";
		for (int j = 0; j < m_cols; j++)
		{
			cout << m_pBoard[i][j] << " ";
			if (m_pBoard[i][j] == 'G') m_gCount++;
			if (m_pBoard[i][j] == 'D') m_dCount++;
		}
	}

	cout << "\n\n\tGold Left: " << m_gCount << ", Gold Picked Up: " << m_gCollected << endl;
	cout << "\tDiamonds Left: " << m_dCount << ", Diamonds Picked Up: " << m_dCollected << endl;

	cout << "\n\tRobot is facing " << m_rDir << " at position " << m_rRow << ", " << m_rCol << endl;
}

void RobotGame::displayOptions()
{
	cout << "\n\n(M)ove, (P)ickup, (R)otate, (Q)uit";
	cout << "\nOption: ";
}

				/***************************************************
								PLAY FUNCTIONS
				***************************************************/

void RobotGame::play()
{
	loadRobot();
	char q;
	string c;
	int actionNumber;
	float degrees;
	DisplayGameBoard();

	while ((!m_file.eof()) || q != 'q')
	{
		m_file >> m_emptyString;
		c = m_emptyString.c_str();
		
		while (_strcmpi(c.c_str(), m_rMove.c_str()) != 0 && _strcmpi(c.c_str(), m_rRotate.c_str()) != 0 &&
			_strcmpi(c.c_str(), m_rPickup.c_str()) != 0 && _strcmpi(c.c_str(), m_quit.c_str()) != 0)
		{
			cout << "\n" << c.c_str() << " does not meet the criteria. \nTry 'MOVE, PICKUP, ROTATE, or QUIT\n";
			m_file >> m_emptyString;
			c = m_emptyString.c_str();
		}
		cout << "\n!!! " << m_emptyString;
		switch (m_emptyString[0])
		{
			case 'm':
			case 'M': 
				m_file >> actionNumber; 
				cout << " " << actionNumber << " !!!\n";
				moveRobot(actionNumber); break;

			case 'p': 
			case 'P': cout << " !!!\n"; pickup();  break;
			case 'r': 
			case 'R': m_file >> degrees; cout << " " << degrees << " !!!\n"; rotate(degrees); break;
			case 'q': 
			case 'Q': q = 'q'; cout << " !!!\n"; break;
			default: cout << "\n\n\tSorry, that was an invalid command. Try again\n";
				break;
		}
		DisplayGameBoard();
	}
}

void RobotGame::interactivePlay()
{
	cout << "\n\n\tEntered Interactive Mode";

	loadRobot();
	char q = 's';
	string command;
	int actionNumber;
	float degrees;
	DisplayGameBoard();

	while (q != 'q')
	{
		displayOptions();
		cin >> command;
		while (_strcmpi(command.c_str(), m_rMove.c_str()) != 0 && _strcmpi(command.c_str(), m_rRotate.c_str()) != 0 &&
			_strcmpi(command.c_str(), m_rPickup.c_str()) != 0 && _strcmpi(command.c_str(), m_quit.c_str()) != 0)
		{
			cout << "\nThat command did not meet the criteria. \nTry 'MOVE, PICKUP, ROTATE, or QUIT\n";
			cout << "Option: ";
			getline(cin, command);
		}
		switch (command[0])
		{
		case 'm':
		case 'M':
			cout << "Spaces: ";
			cin >> actionNumber;  
			moveRobot(actionNumber); 
			break;
		case 'p':
		case 'P': pickup(); break;
		case 'r':
		case 'R': 
			cout << "Degrees: ";
			cin >> degrees;  
			if (static_cast<int>(degrees) % 45 == 0)
				rotate(degrees);
			else
				cout << "\n" << degrees << " Not divisible by 45\n";
			break;
		case 'q':
		case 'Q': q = 'q'; cout << "\nThanks for playing!\n"; continue;
		default: cout << "\n\n\tSorry, that was an invalid command. Try again\n";
			break;
		}
		DisplayGameBoard();
	}
}

				/***************************************************
									ROBOT FUNCTIONS
				***************************************************/

	// This is called at the beginning of the play functions.
	// It initializes the robots location
void RobotGame::loadRobot()
{
	m_file >> m_emptyString;
	m_file >> m_rRow;
	m_file >> m_rCol;
	m_file >> m_rDir;
	m_dir = robotDir(m_rDir);
	m_ph = '_';
	moveRobot(0);

}

void RobotGame::placeRobot()
{
	switch (m_ph)
	{
		case 'G':
			m_gSentinel = 1;
			break;
		case 'D':
			m_dSentinel = 1;
			break;
		default:
			m_dSentinel = 0;
			m_gSentinel = 0;
			break;
	}

	m_pBoard[m_rRow][m_rCol] = 'R';
	
	
}
int RobotGame::robotDir(string rDir)
{
	char e[] = "EAST";			// 0
	char se[] = "SOUT-HEAST";	// 1
	char s[] = "SOUTH";			// 2
	char sw[] = "SOUTH-WEST";	// 3
	char w[] = "WEST";			// 4
	char nw[] = "NORTH-WEST";	// 5
	char n[] = "NORTH";			// 6
	char ne[] = "NORTH-EAST";	// 7
	if (_strcmpi(rDir.c_str(), e) == 0)
	{
		return 0;
	}
	if (_strcmpi(rDir.c_str(), se) == 0)
	{
		m_rDir = se;
		return 1;
	}
	if (_strcmpi(rDir.c_str(), s) == 0)
	{
		m_rDir = s;
		return 2;
	}
	if (_strcmpi(rDir.c_str(), sw) == 0)
	{
		m_rDir = sw;
		return 3;
	}
	if (_strcmpi(rDir.c_str(), w) == 0)
	{
		m_rDir = w;
		return 4;
	}
	if (_strcmpi(rDir.c_str(), nw) == 0)
	{
		m_rDir = nw;
		return 5;
	}
	if (_strcmpi(rDir.c_str(), n) == 0)
	{
		m_rDir = n;
		return 6;
	}
	if (_strcmpi(rDir.c_str(), ne) == 0)
	{
		m_rDir = ne;
		return 7;
	}
		
	cout << "\n\tRobot direction invalid. Setting it to " << e;
	m_rDir = e;
	return 0;
	
}
	// Move the robot
int RobotGame::moveRobot(int rSpaces)
{
	//bool bounds = ((m_rCol < m_cols && m_rCol > 0) && (m_rRow > 0 && m_rRow < m_rows - 1));
	bool ebounds = (m_rCol < m_cols - 1);
	bool wbounds = (m_rCol > 0);
	bool nbounds = (m_rRow > 0);
	bool sbounds = (m_rRow < m_rows - 1);
	bool bounds = true;
	m_pBoard[m_rRow][m_rCol] = m_ph;
	for (int i = 0; i < abs(rSpaces); i++)
	{
		if (rSpaces > 0)
			switch (m_dir)
		{
				case 0:if (ebounds)m_rCol++; break;
				case 1:if (sbounds && ebounds){ m_rRow++; m_rCol++; } break;
				case 2:if (sbounds)m_rRow++; break;
				case 3:if (sbounds && wbounds){ m_rRow++; m_rCol--; } break;
				case 4:if (wbounds)m_rCol--; break;
				case 5:if (wbounds && nbounds){ m_rCol--; m_rRow--; } break;
				case 6:if (nbounds)m_rRow--; break;
				case 7:if (nbounds && ebounds){ m_rRow--; m_rCol++; } break;
				default:
					cout << "\n\n\tThe robot is not facing in a valid direction";
					break;
		}
		else
		{
			switch (m_dir)
			{
				case 0:if (wbounds)m_rCol--; break;
				case 1:if (wbounds && nbounds){ m_rCol--; m_rRow--; } break;
				case 2:if (nbounds)m_rRow--; break;
				case 3:if (nbounds && ebounds){ m_rRow--; m_rCol++; } break;
				case 4:if (ebounds)m_rCol++; break;
				case 5:if (sbounds && ebounds){ m_rRow++; m_rCol++; } break;
				case 6:if (sbounds)m_rRow++; break;
				case 7:if (sbounds && wbounds){ m_rRow++; m_rCol--; } break;
			}

		}		
	}
	m_ph = m_pBoard[m_rRow][m_rCol];

	placeRobot();
	
	return 0;
}

	// Rotate the robot
void RobotGame::rotate(float rDegrees)
{
	for (int i = 0; i < (abs(rDegrees)) / 45; i++)
	{
		
		if (rDegrees > 0)
		{
			if (m_dir == 7)m_dir = -1;
			m_dir++;
		}
			
		else
		{
			if (m_dir == 0)m_dir = 8;
			m_dir--;
		}
	}

	switch (m_dir)
	{
		case 0: m_rDir = "EAST"; break;
		case 1: m_rDir = "SOUTH-EAST"; break;
		case 2: m_rDir = "SOUTH"; break;
		case 3: m_rDir = "SOUTH-WEST"; break;
		case 4: m_rDir = "WEST"; break;
		case 5: m_rDir = "NORTH-WEST"; break;
		case 6: m_rDir = "NORTH"; break;
		case 7: m_rDir = "NORTH-EAST"; break;
		default:
			cout << "\n\n\tThe degrees received were not valid";
			break;
	}
	
		
	
	
}

	// Pickup an item
void RobotGame::pickup()
{
	switch (m_ph)
	{
		case 'g':
		case 'G': 
			m_gSentinel = 0;
			m_gCollected++; 
			m_ph = '_'; 
			break;
		case 'd':
		case 'D':
			m_dSentinel = 0; 
			m_dCollected++; 
			m_ph = '_'; 
			break;
		default: cout << "\n\n\tSorry, nothing there to be picked up\n";
			break;
	}
}


