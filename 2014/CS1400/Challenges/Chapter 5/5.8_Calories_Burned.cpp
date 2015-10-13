/*Running on a particular treadmill you burn 3.9 calories per minute. Write a program
that uses a loop to display the number of calories burned after 10, 15, 20, 25, and 30
minutes*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	float cal = 3.9;

	cout << "\n\n******************";
	cout << "\nCalories Burned  |";
	cout << "\n******************";

	cout << "\n\n\t--------------------------------------";
	for(int i = 10; i <= 30; i +=5){
		cout << "\n\t" << cal * i << "\tcalories burned in " << i << " minutes";
	}
	cout << "\n\t--------------------------------------\n\n";


	return 0;
}