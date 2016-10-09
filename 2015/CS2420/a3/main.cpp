// this file is the main entry point of the program.
#include <iostream>
#include "Game.h"
#include "Board.h"
#include "avlTree.h"

using namespace std;

void useRandom();
void user();
void playPriorityGames(string name, int board[], bool showMe);
void playBruteGames(string name, int board[], bool showMe);

const int SIZE = 3;
int main()
{
    /*
     * PART I
     */

    AvlTree<int> tree;
//    •	Add: 1 3 5 7 9 11 2 4 8  (now print tree)
    cout << "\n\nPART I\n\n";
    cout << "\nAdd: 1 3 5 7 9 11 2 4 8 \n";
    int values[9] = {1, 3, 5, 7, 9, 11, 2, 4, 6};
    for(int i = 0; i < 9;i++)
        tree.insert(values[i]);
    cout << tree.toString();

//    •	Remove 7 9(now print tree)
    cout << "\nRemove 7, 9\n";
    tree.remove(7);
    tree.remove(9);
    cout << tree.toString();

//    •	Add 50 30 15 18 (now print tree)
    cout << "\nAdd 50 30 15 18\n";
    int newValues[4] = {50, 30, 15, 18};
    for(int i = 0; i < 4; i++)
        tree.insert(newValues[i]);
    cout << tree.toString();

//    •	Remove Min (now print tree)
    cout << "\nRemove Min\n";
    tree.removeMin();
    cout << tree.toString();

//    •	Remove Min (now print tree)
    cout << "\nremove Min\n";
    tree.removeMin();
    cout << tree.toString();

//    •	Remove Min (now print tree)
    cout << "\nRemove min\n";
    tree.removeMin();
    cout << tree.removeMin();

//    •	Add 17(now print tree)
    cout << "\nAdd 17\n";
    tree.insert(17);
    cout << tree.toString();

    /*
     * PART II
     */

	int game0[SIZE*SIZE] = { 1, 2, 3, 7, 4, 0, 6, 5, 8 };
	int game1[SIZE*SIZE] = { 1, 3, 2, 4, 5, 6, 8, 7, 0 };
	int game2[SIZE*SIZE] = { 1, 3, 8, 6, 2, 0, 5, 4, 7 };
	int game3[SIZE*SIZE] = { 4, 0, 1, 3, 5, 2, 6, 8, 7 }; // Takes forever long time to solve

	AvlTree<Board> boardTree;

	/*
	 * Priority
	 */

	cout << "\n\nPart II\n\n";
	cout << "The best example first\n\n";
	cout << "Type: Priority\n";
	cout << "Start Board: ";
	for(int i = 0; i < SIZE*SIZE;i++)cout << game0[i] << " ";
	cout << "\n";
	Game g("Title", game1);
	g.playPriority(true);

	/*
	 * Brute Force
	 */

	int gameBoard[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 0 };
	cout << "\n\n\nType: Brute Force\n";
	cout << "Start Board: ";
	for(int i = 0; i < SIZE*SIZE;i++)cout << game0[i] << " ";
	cout << "\n";
	Game go("Title", gameBoard);
	go.playGiven("Title", game1, false);

	/*
	 * All of the other examples (some of them take quite a while....
	 */
	cout << "\n\nAll of the other examples (the last one takes quite a while....)\n\n";


	// game 1
	playPriorityGames("Game 1", game0, false);
	playBruteGames("Game 1", game0, false);

	// game 2
	playPriorityGames("Game 2", game1, false);
	playBruteGames("Game 2", game1, false);

	// game 3
	playPriorityGames("Game 3", game2, false);
	playBruteGames("Game 3", game2, false);

	// game 4
	playBruteGames("Game 4", game3, false);
	playPriorityGames("Game 4", game3, false);


	return 0;
}

void playPriorityGames(string name, int board[], bool showMe)
{
	cout << "\n\n" << name << "\n\n";
	cout << "Type: Priority\n";
	cout << "Start Board: ";
	for(int i = 0; i < SIZE*SIZE;i++)cout << board[i] << " ";
	cout << "\n";
	Game g("Title", board);
	g.playPriority(showMe);
}

void playBruteGames(string name, int board[], bool showMe)
{
	cout << "\n\n" << name << "\n\n";

	int gameBoard[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 0 };
	cout << "Type: Brute Force\n";
	cout << "Start Board: ";
	for(int i = 0; i < SIZE*SIZE;i++)cout << board[i] << " ";
	cout << "\n";
	Game g("Title", gameBoard);
	g.playGiven("Title", board, showMe);
}