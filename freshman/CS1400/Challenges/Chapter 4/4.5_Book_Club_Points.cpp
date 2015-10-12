/*An online book club awards points to its customers based on the number of books
purchased each month. Points are awarded as follows:
	-----------------------------------------
		Books purchased		Points Earned
	-----------------------------------------
			0					 0
			1					 5
			2					15
			3					30
		4 of more				60
	-----------------------------------------

Write a program that asks the user to enter the number of books purchased this month
and then displays the number of points awarded.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	int points, books = 0;

	cout << "\n\tHow many books were sold this month? ";
	cin >> books;

	if(books == 0)
			cout << "\n\n\tNo books? Sad day, no points for you.\n\n";
	else if(books == 1){
			cout << "\n\n\t1 book sold equals 5 points.\n\n";
	}else if(books == 2){
			cout << "\n\n\t2 books sold equals 15 points.\n\n";
	}else if(books == 3){
			cout << "\n\n\t3 books sold equals 30 points.\n\n";
	}else if(books >= 4){
			cout << "\n\n\t4 or more books sold equals 60 points.\n\n";
	}else{
		cout << "\n\n\tInvalid Input.\n\n";
	}

	return 0;
}