#ifndef RobotGame_HPP
#define RobotGame_HPP

#include <iostream>
#include <fstream>
#include <stdio.h>

class RobotGame
{
public:
	RobotGame();
	RobotGame(int, int);
	~RobotGame();
	
	void play();
	void move();
	
	
	void quit();
	void openFile(std::string rName);
	void closeFile();
	void loadRow(int row, char* pRowString);
	void makeMap();
	void DisplayGameBoard();
	void interactivePlay();
	void displayOptions();

		/* Robot Functions*/
	void loadRobot();
	int moveRobot(int rSpaces);
	void placeRobot();
	void rotate(float rDegrees);
	void pickup();
	int robotDir(std::string rDir);

private:

	std::string m_emptyString;
	std::ifstream m_file;

		/* Board Variables*/
	int m_rows;
	int m_cols;
	char** m_pBoard;
	int m_dCount;
	int m_gCount;
	int m_dSentinel; // Used if robot is on gold or diamond
	int m_gSentinel;
	int m_dCollected; // The amount of diamonds collected
	int m_gCollected; // The amount of gold collected

		/* Robot variables */
	char m_ph;
	char m_oldPH;
	char m_newPH;
	int m_oldPRow; // Placeholder row
	int m_oldPCol; // Placeholder col
	int m_newPRow; // Placeholder row
	int m_newPCol; // Placeholder col
	int m_rRow;
	int m_rCol;
	int m_dir; // direction of the robot
	std::string m_rDir;
	std::string m_rMove;
	std::string m_rPickup;
	std::string m_rRotate;
	std::string m_quit;
	
	

};

#endif