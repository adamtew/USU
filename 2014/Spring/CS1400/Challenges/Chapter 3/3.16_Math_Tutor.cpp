/*Write a program that can be used as a math tutor for a young student. The program
should display two random numbers between 1 and 9 to be added, such as 

			 2
			+1

After the student has entered an answer and pressed the [Enter] key, the program 
should display the correct answer so the student can see if his or her 
answer is correct.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	int num1 = 0, num2 = 0, studentAns = 0, seed = 5;
	float number;
	
	srand(time(0));
	num1 = (rand() % 9) + 1;
	num2 = (rand() % 9) + 1;
	int correctAns = num1 + num2;


	cout << "\nWhat is " << num1 << " + " << num2 << "? ";
	cin >> studentAns;

	cout << "\nThe correct answer is " << correctAns << endl;

	return 0;
}