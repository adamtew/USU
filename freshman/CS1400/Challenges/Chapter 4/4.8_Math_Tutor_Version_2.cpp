/*This is a modification of the math tutor problem in Chapter 3. Write a program that
can be used as a math tutor for a young student. The program should display two
random numbers between 10 and 50 that are to be added, such as:

	  24
	+ 12
	-----

The program should then wait for the student to enter the answer. If the answer is
correct, a message of congratulations should be printed. If the answer is incorrect,
a message should be printed showing the correct answer.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	int num1, num2, total, answer = 0;
	bool correct;
	while(true){
	srand(time(0));
	num1 = rand() % 40 + 10;
	num2 = rand() % 40 + 10;
	total = num1 + num2;

	cout << "\n\t\tWhat is " << num1 << " + " << num2 << "? ";
	cin >> answer;

	answer == total ? correct = true : correct = false;

	if(correct){
		cout << "\tExcellent, the correct answer was " << total << "!\n";
	}else{
		cout << "\tOoops, the correct answer was " << total << endl;
	}
}
	return 0;
}