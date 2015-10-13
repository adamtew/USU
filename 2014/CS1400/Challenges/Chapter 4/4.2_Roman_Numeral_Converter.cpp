/*Write a program that asks the user to enter a number within the range of 1 through
10. Use a switch statement to display the Roman numeral version of that number.

	Input Validation: Decide how the program should handle an input that is less
	than 1 or greater than 10.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	int switched = 0;
	string romanNumeral;

	cout << "\n\n--------------------------------------\n";
	cout << "\n\t---Enter a Decimal---";
	cout << "\n\t1...............I...|";
	cout << "\n\t2...............II..|";
	cout << "\n\t3...............III.|";
	cout << "\n\t4...............IV..|";
	cout << "\n\t5...............V...|";
	cout << "\n\t6...............VI..|";
	cout << "\n\t7...............VII.|";
	cout << "\n\t8...............VIII|";
	cout << "\n\t9...............IX..|";
	cout << "\n\t10..............X...|";
	cout << "\n\n--------------------------------------\n\n\t> ";
	cin >> switched;
	
	if(switched >= 1 && switched <= 10){
		switch(switched){	
			case 1:
				cout << "\t 1 is equal to I\n";
				break;
			case 2:
				cout << "\t 2 is equal to II\n";
				break;
			case 3:
				cout << "\t 3 is equal to III\n";
				break;
			case 4:
				cout << "\t 4 is equal to IV\n";
				break;
			case 5:
				cout << "\t 5 is equal to V\n";
				break;
			case 6:
				cout << "\t 6 is equal to VI\n";
				break;
			case 7:
				cout << "\t 7 is equal to VII\n";
				break;
			case 8:
				cout << "\t 8 is equal to VIII\n";
				break;
			case 9:
				cout << "\t 9 is equal to IX\n";
				break;
			case 10:
				cout << "\t 10 is equal to X\n";
				break;
			default:
				break;
		}
	}else{
		cout << "\n\tInvalid input.\n";
	}


	return 0;
}