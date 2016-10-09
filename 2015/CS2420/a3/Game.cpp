// This file implements the Game.h definitions
#include "Game.h"

// default constructor
Game::Game(){

}

// other constructor
Game::Game(string title, int boardArray[]){
	classTitle = title; // initialize the title variable
	classBoard.makeBoard(boardArray); // make the board from the given array (boardArray)
	classQueue = new BoardQueue(); // create a new queue to store boards
	int solved[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 0 }; // create an array in the order of a solved board
	classSolvedBoard.makeBoard(solved); // create a solved board to compare other with other boards
}

// getter
string Game::getTitle() const{
	return classTitle;
}

// the main game loop. This function iteratively checks all of the possible moves you can make until it finds a solution
void Game::play(bool showMe = false){
	classBoard.moves = " "; // initialize the boards moves to an empty string
	BoardNode* newBoard = new BoardNode(classBoard, nullptr); // create a new boardnode to add to the queue
	classQueue->push(newBoard);	// add the first boardnode to the queue
	Board original; // an original board to reference back to after each move
	Board board = classBoard; // initialize the board that will be used in the loop
//	cout << board.toString() << endl; // show the board before it's altered at all
	int dequeues = 0;
	char lastMove; // setup a variable to show the last move made
	while (!(board == classSolvedBoard)){ // while the board isn't solved, continue trying
		board = classQueue->pop()->getBoard(); // pop off the node to evaluate
		dequeues++;
		if(showMe)cout << board.toStringPretty();
		lastMove = board.moves.back(); // grab the last character off of the moves array to pass into the move functions
		original = board; // setup the original board to be referenced back to after each atempt
		
		if(move(board, 'L', lastMove))break; // attempt moving left, if this solves the board, break out of the loop
		board = original; // reset the board
		if(move(board, 'R', lastMove))break; // repeat for each direction
		board = original;
		if(move(board, 'D', lastMove))break;
		board = original;
		if(move(board, 'U', lastMove))break;
		board = original;
	}
	// output the moves to solve the puzzle
	cout << "Moves: " << dequeues << ", " << board.moves << " (Dequeued Boards)\n";
	cout << "End Board: " << board.toString() << endl; // output the puzzle
}

// the move function is used to evaluate each move to see if it's valid and if it will solve the puzzle
bool Game::move(Board &b, char m, char lastMove){
	char a = b.makeMove(m, lastMove); // the last move variables gets changed to whatever direction you move
	b.moves += a; // add the last move to the string of moves
	if (a != ' ') // if the move == ' ' then the move could not be made, therefore don't add to the queue
		classQueue->push(new BoardNode(b)); // add a valid move to the queue
	if (b == classSolvedBoard) // if the board is solved return true
		return true;
	return false; // else return false
}

// the playgiven function is used to add a board and have it played
void Game::playGiven(string title, int newBoard[], bool showMe){
	classTitle = title; // set the class title
	classBoard.makeBoard(newBoard); // create a new board with the given array
	play(showMe); // play the board
}

// the playRandom() function is used to play a random puzzle
void Game::playRandom(string title, int randValue){
	classTitle = title; // setup the title
	classBoard.jumble(randValue); // create a random puzzle to be solved
	play(); // play the board
}




/*
 * Priority Queue
 */

void Game::playPriority(bool showMe = false){
    classBoard.moves = " "; // initialize the boards moves to an empty string
    tree.insert(classBoard);
    Board original; // an original board to reference back to after each move
    Board board = classBoard; // initialize the board that will be used in the loop
//    cout << board.toString() << endl; // show the board before it's altered at all
    int numberOfMoves = 0;
    char lastMove; // setup a variable to show the last move made
    while (!(board == classSolvedBoard)){ // while the board isn't solved, continue trying
        board = tree.removeMin();
        numberOfMoves++;
		if(showMe)cout << board.toStringPretty();
        lastMove = board.moves.back(); // grab the last character off of the moves array to pass into the move functions
        original = board; // setup the original board to be referenced back to after each atempt

        if(movePriority(board, 'L', lastMove))break; // attempt moving left, if this solves the board, break out of the loop
        board = original; // reset the board
        if(movePriority(board, 'R', lastMove))break; // repeat for each direction
        board = original;
        if(movePriority(board, 'D', lastMove))break;
        board = original;
        if(movePriority(board, 'U', lastMove))break;
        board = original;
    }
    // output the moves to solve the puzzle
//    cout << board.moves << " in " << classQueue->getCount() << " boards\n";
    cout << "Moves: " << numberOfMoves << ", "<< board.moves << " (Dequeued Boards)\n";
    cout << "End Board: " << board.toString() << endl; // output the puzzle
}

// the move function is used to evaluate each move to see if it's valid and if it will solve the puzzle
bool Game::movePriority(Board &b, char m, char lastMove){
    char a = b.makeMove(m, lastMove); // the last move variables gets changed to whatever direction you move
    b.moves += a; // add the last move to the string of moves
    if (a != ' ') // if the move == ' ' then the move could not be made, therefore don't add to the queue
//        classQueue->push(new BoardNode(b)); // add a valid move to the queue
        tree.insert(b);
    if (b == classSolvedBoard) // if the board is solved return true
        return true;
    return false; // else return false
}

void Game::playRandomPriority()
{

}

void Game::playGivenPriority()
{

}


