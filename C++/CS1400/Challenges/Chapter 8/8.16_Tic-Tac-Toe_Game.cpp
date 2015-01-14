/*Write a modular program that allows two players to play a game of
tic-tac-toe. Use a two-dimensional char array with 3 rows and 3 columns
as the game board. Each element of the array should be initialized with
an asterisk (*). The prorgam should display the initial board configuration
and then start a loop that does the following:

	• Allow player 1 to select a location on the board for an X by
	  entering a row and column number. Then redisplay the board with
	  an X replacing the * in the chosen locaiton.
	• If there is no winner yet and the board is not yet full, allow 
	  player 2 to select a location on the board for an O by entering
	  a row and column number. THen redisplay the board with an O 
	  replacing the * in the chosen location.

The loop should continue until a player has won or a tie has occurred,
then display a message indication who won, or reporting that a tie
occurred.

	• Player 1 wins when there are three Xs in a row, a column, or a
	  diagonal on the game board.
	• Player 2 wins when there are three Os in a row, a column, or a
	  diagonal on the game board.
	• A tie occurs when all of the locations on the board are full, but
	  there is no winner.

	Input Validation: Only allow legal moved to be entered. The row must
	be 1, 2, or 3. The column must be 1, 2, or 3. The (row, column)
	position entered myst cyrrently be empty (i.e., still have an
	asterisk in it).*/

#include <iostream>

using namespace std;

void printTitle();
void showGame();
void setBoard();
void startGame();
void setPosition();
void printOptions();
bool checkWinner();

const int ROW = 3, COL = 3;
char board[ROW][COL];
int position[2];

int main(){

	printTitle();
	startGame();

	return 0;
}

void printTitle(){

	cout << "\n********************";
	cout << "\nTic-Tac-Toe Game   |";
	cout << "\n********************";

}

void showGame(){

	cout << "\n";

	for(int i = 0; i <= 2; i++){
		cout << "\n  ";
		for(int j = 0; j <= 2; j++){
			cout << board[i][j];
		}
	}

	cout << "\n";

}

void setBoard(){

	for(int i = 0; i <= 2; i++){
		for(int j = 0; j <= 2; j++){
			board[i][j] = '*';
		}
	}
}

void startGame(){
	bool winner = false;

	setBoard();
	while(!winner){
		for(int i = 2; i < 11; i++){
			if(i % 2 == 0){
				cout << "\n\n----Player 1----";
				showGame();
				setPosition();
				board[position[0] - 1][position[1] - 1] = 'O';
				winner = checkWinner();
				if(winner){
					cout << "\n\tPlayer 1 is the winner!";
					break;
				}
			}else{
				cout << "\n\n----Player 2----";
				showGame();
				setPosition();
				board[position[0] - 1][position[1] - 1] = 'X';
				winner = checkWinner();
				if(winner){
					cout << "\n\tPlayer 2 is the winner!";
					break;
				}
			}
			if(i == 10)winner = true;
		}
	}
	showGame();
}

void setPosition(){

	cout << "\n   Row: ";
	cin >> position[0];
	cout << "   col: ";
	cin >> position[1];

	while(position[0] < 0 || position[0] > 3 ||
		position[1] < 0 || position[1] > 3){
		cout << "\n\tEnter a valid position.";
		cout << "\n   Row: ";
		cin >> position[0];
		cout << "   col: ";
		cin >> position[1];
	}
	
	while(board[position[0] - 1][position[1] - 1] == 'X' || 
		board[position[0] - 1][position[1] - 1] == 'O'){
		cout << "\n\tSomeone already went there. Try again.";
		cout << "\n   Row: ";
		cin >> position[0];
		cout << "   col: ";
		cin >> position[1];
	}
	
}

bool checkWinner(){

if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')return true;
if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')return true;
if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')return true;
if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')return true;
if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')return true;
if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')return true;
if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')return true;
if(board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')return true;

if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')return true;
if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')return true;
if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')return true;
if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')return true;
if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')return true;
if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')return true;
if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')return true;
if(board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')return true;

	return false;
}