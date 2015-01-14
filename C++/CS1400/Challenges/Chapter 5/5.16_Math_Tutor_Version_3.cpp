/*This program started in Chapter 3 and was modified in Chapter 4. Starting with the
version described in Chapter 4, modify the program again so it displays a menu
allowing the user to select an addition, subtraction, or multiplication problem.
The final selection on the menu should let the user quit the program. After the
user has finished the math problem, the program should display the menu again. This
process must repeat until the user chooses to quite the program. If the user selects
an item not on the menu, the program should print an error message and then
display the menu again.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	
	int num1, num2, totalAdd, totalSub, totalMul, totalDiv, answer = 0;
	bool correct;
	char operation;

	cout << "\n\n************************";
	cout << "\nMath Tutor Version 3   |";
	cout << "\n************************";

	while(operation != 'q'){

		cout << "\n\n\t------------------------";
		cout << "\n\t  Choose an operation";
		cout << "\n\t------------------------";
		cout << "\n\t|Addition       (+)   1|";
		cout << "\n\t|Subtraction    (-)   2|";
		cout << "\n\t|Multiplication (+)   3|";
		cout << "\n\t|Division       (/)   4|";
		cout << "\n\t|                      |";
		cout << "\n\t|Quit                 q|";
		cout << "\n\t------------------------";
		cout << "\n\n\tOperation: ";
		cin >> operation;


	
		srand(time(0));
		num1 = rand() % 40 + 10;
		num2 = rand() % 40 + 10;
		totalAdd = num1 + num2;
		totalSub = num1 - num2;
		totalMul = num1 * num2;
		totalDiv = num1 / num2;

		switch(operation){
			case '1':cout << "\n\t\tWhat is " << num1 << " + " << num2 << "? ";
					cin >> answer;
					answer == totalAdd ? correct = true : correct = false;
					if(correct){
						cout << "\tExcellent, the correct answer was " << totalAdd << "!\n";
					}else{
						cout << "\tOoops, the correct answer was " << totalAdd << endl;
					}
				break;

			case '2':cout << "\n\t\tWhat is " << num1 << " - " << num2 << "? ";
					cin >> answer;
					answer == totalSub ? correct = true : correct = false;
					if(correct){
						cout << "\tExcellent, the correct answer was " << totalSub << "!\n";
					}else{
						cout << "\tOoops, the correct answer was " << totalSub << endl;
					}
				break;

			case '3':cout << "\n\t\tWhat is " << num1 << " * " << num2 << "? ";
					cin >> answer;
					answer == totalMul ? correct = true : correct = false;
					if(correct){
						cout << "\tExcellent, the correct answer was " << totalMul << "!\n";
					}else{
						cout << "\tOoops, the correct answer was " << totalMul << endl;
					}
				break;

			case '4':cout << "\n\t\tWhat is " << num1 << " / " << num2 << "? ";
					cin >> answer;
					answer == totalDiv ? correct = true : correct = false;
					if(correct){
						cout << "\tExcellent, the correct answer was " << totalDiv << "!\n";
					}else{
						cout << "\tOoops, the correct answer was " << totalDiv << endl;
					}
				break;

			case 'q':
				break;

			default:cout << "Invalid Input: ";
					cin >> operation;
				break;

		}


	}

	return 0;
}