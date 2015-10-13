/*Write a program with a loop that lets the user enter a series of integers, followed
by -99 to signal the end of the series. After all the number have been entered, the
program should display the largest and smallest numbers entered.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	int tag = 0, inc = 1, smallest = tag, largest = tag;


	cout << "\n\n**********************************";
	cout << "\nThe Greatest and Least of These  |";
	cout << "\n**********************************";

	cout << "\n\n\tEnter a series of integers";
	cout << "\n\tEnter -99 when you're finished.\n\n";

	cout << "\tNumber " << inc++ << ": ";
	cin >> tag;
	smallest = tag;
	largest = tag;
	while(tag != -99){
		cout << "\tNumber " << inc++ << ": ";
		cin >> tag;
		if(tag != -99 && tag < smallest) smallest = tag;
		if(tag != -99 && tag > largest) largest = tag;
	}
	cout << "\n\n\tSmallest: " << smallest;
	cout << "\n\tLargest: " << largest << endl;

	return 0;
}