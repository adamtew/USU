#include "ConnectNGame.hpp"
#include <iostream>
#include <ctime>

/*****************************************************************
							CONSTRUCTOR
*****************************************************************/

ConnectNGame::ConnectNGame(int rSpaces)
{
	m_rows = 0;
	m_cols = 0;
	m_spacesToWin = rSpaces;
	m_playerPos.team = 'p';
	m_computerPos.team = 'c';
}

/*****************************************************************
							DESTRUCTOR
*****************************************************************/

ConnectNGame::~ConnectNGame()
{
	for (int i = 0; i < m_rows; i++)
		if (m_pBoard[i] != NULL)
		{
			if (m_pBoard[i] != NULL){
				delete[] m_pBoard[i];
				m_pBoard[i] = NULL;
			}	
		}

	if (m_pBoard != NULL)
	{
		delete[] m_pBoard;
		m_pBoard = NULL;
	}

}

/*****************************************************************
							INITIALIZERS
*****************************************************************/

void ConnectNGame::makeBoard()
{
	switch (m_spacesToWin)
	{
	case 3: m_rows = 5; m_cols = 6; break;
	case 4: m_rows = 6; m_cols = 7; break;
	case 5: m_rows = 7; m_cols = 8; break;
	default: break;
	}

	m_pBoard = new char*[m_rows];

	for (int i = 0; i < m_rows; i++)
	{
		*(m_pBoard + i) = new char[m_cols];
	}

	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			//m_pBoard[i][j] = '*';
			*(*(m_pBoard + i) + j) = '*';
		}
	}
}

bool ConnectNGame::playing()
{
	while (true)
	{
		displayGameBoard();

		if (checkWin(playerMove()))
		{
			m_winner = true;
			break;
		}

		if (checkTie(m_playerPos))return false;

		if (checkWin(computerMove()))
		{
			m_winner = false;
			break;
		}

		if (checkTie(m_computerPos))return false;
	}
	return true;
}

void ConnectNGame::play()
{
	makeBoard();
	if (playing())
		winner();
	else
		tie();
}

void ConnectNGame::displayGameBoard()
{
	cout << "\n\n\t----------------------";
	cout << "\n\n\t\t";
	for (int i = 0; i < m_cols; i++)cout << i + 1 << " ";
	cout << endl;
	for (int i = 0; i < m_rows; i++)
	{
		cout << "\n\t\t";
		for (int j = 0; j < m_cols; j++)
		{
			cout << m_pBoard[i][j] << " ";
		}
	}
	cout << "\n\t----------------------\n";
}

/*****************************************************************
							MOVING
*****************************************************************/

ConnectNGame::Position ConnectNGame::playerMove()
{
	cout << "\nColumn: ";
	cin >> m_playerPos.col;
	//while (m_playerPos.col < 1 || m_playerPos.col > m_cols || m_pBoard[0][m_playerPos.col - 1] != '*')
	while (m_playerPos.col < 1 || m_playerPos.col > m_cols || *(*(m_pBoard + 0) + (m_playerPos.col - 1)) != '*')
	{
		cout << "\n\tInvalid piece placement, try again.\n\tColumn: ";
		cin >> m_playerPos.col;
	}
	for (int i = m_rows - 1; i >= 0; i--)
	{
		//if (m_pBoard[i][m_playerPos.col - 1] == '*')
		if (*(*(m_pBoard + i) + (m_playerPos.col - 1)) == '*')
		{
			//m_pBoard[i][m_playerPos.col - 1] = 'p';
			*(*(m_pBoard + i) + (m_playerPos.col - 1)) = 'p';
			m_playerPos.row = i;
			break;
		}
	}
	return m_playerPos;
}


ConnectNGame::Position ConnectNGame::computerMove()
{
	srand(static_cast<unsigned int>(time(NULL)));
	m_computerPos.col = 1 + rand() % m_cols;
	//while (m_pBoard[0][m_computerPos.col - 1] != '*')
	while (*(*(m_pBoard + 0) + (m_computerPos.col - 1)) != '*')
	{
		m_computerPos.col = 1 + rand() % m_cols;
	}
	for (int i = m_rows - 1; i >= 0; i--)
	{
		//if (m_pBoard[i][m_computerPos.col - 1] == '*')
		if (*(*(m_pBoard + i) + (m_computerPos.col - 1)) == '*')
		{
			//m_pBoard[i][m_computerPos.col - 1] = 'c';
			*(*(m_pBoard + i) + (m_computerPos.col - 1)) = 'c';
			m_computerPos.row = i;
			break;
		}
	}
	return m_computerPos;
}

/*****************************************************************
							CHECK WINS
*****************************************************************/

bool ConnectNGame::checkWin(Position rPos)
{
	if (checkRowWin(rPos))return true;
	if (checkColumnWin(rPos))return true;
	if (checkRightDiagonalWin(rPos))return true;
	if (checkLeftDiagonalWin(rPos))return true;

	return false;
}

bool ConnectNGame::checkColumnWin(Position rPos)
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			if (checkNext(i, j, 1, 0, rPos.team) >= m_spacesToWin)return true;

	return false;
}

bool ConnectNGame::checkRowWin(Position rPos)
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			if (checkNext(i, j, 0, 1, rPos.team) >= m_spacesToWin)return true;

	return false;
}

bool ConnectNGame::checkRightDiagonalWin(Position rPos)
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			if (checkNext(i, j, 1, 1, rPos.team) >= m_spacesToWin)return true;

	return false;
}

bool ConnectNGame::checkLeftDiagonalWin(Position rPos)
{
	for (int i = 0; i <= m_rows; i++)
		for (int j = 0; j <= m_cols + 1; j++)
			if (checkNext(i, j, 1, -1, rPos.team) >= m_spacesToWin)return true;

	return false;
}

int ConnectNGame::checkNext(int row, int col, int rowInc, int colInc, char x)
{
	int count = 0;
	col = col - 1;

	for (int i = 0; i < m_spacesToWin; i++)
		if (col + colInc <= m_cols && row + rowInc < m_rows)
			//if (m_pBoard[row += rowInc][col += colInc] == x)count++;
			if (*(*(m_pBoard + (row += rowInc)) + (col += colInc)) == x)count++;
	
	return count;
}

bool ConnectNGame::checkTie(Position rPos)
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			//if (m_pBoard[i][j] == '*')return false;
			if (*(*(m_pBoard + i) + j) == '*')return false;
		}
	}
	return true;
}

/*****************************************************************
							CONCLUSIONS
*****************************************************************/

void ConnectNGame::winner()
{
	displayGameBoard();
	if (m_winner)
	{
		cout << "\n\n\tCONGRATULATIONS! You are the winner!\n\n";
	}
	else
	{
		cout << "\n\n\tSorry, the computer has defeated you.\n\n";
	}
}

void ConnectNGame::tie()
{
	displayGameBoard();
	cout << "\n\n\tLooks like there's a tie.\n\n";
}