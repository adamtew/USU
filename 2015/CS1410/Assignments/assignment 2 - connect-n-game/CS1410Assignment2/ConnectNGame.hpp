#ifndef CONNECTNGAME_HPP
#define CONNECTNGAME_HPP

#include <iostream>
using namespace std;
class ConnectNGame
{
public:
	ConnectNGame(int);
	~ConnectNGame();
	void play();

private:
	struct Position{
		int row;
		int col;
		char team;
	};

	void displayGameBoard();
	Position playerMove();
	Position computerMove();
	bool checkRowWin(Position);
	bool checkColumnWin(Position);
	void makeBoard();
	bool checkRightDiagonalWin(Position);
	bool checkLeftDiagonalWin(Position);
	bool checkTie(Position);
	bool checkWin(Position);
	void winner();
	void tie();
	int checkNext(int, int, int, int, char);
	bool playing();

	int m_rows;
	int m_cols;
	int m_spacesToWin;
	char **m_pBoard;
	Position m_playerPos;
	Position m_computerPos;
	bool m_playing;
	bool m_winner;
};

#endif