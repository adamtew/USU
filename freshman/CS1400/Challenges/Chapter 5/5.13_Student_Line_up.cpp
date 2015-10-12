/*A teacher asked all her students to line up single file according to their first
name. For example, in one class Amy will be at the front of the line and Yolanda will
be at the end. Write a program that propmts the user to enter a number between 1 and 
25 for the number of students in the class, then loops to read in that many names.
Once all the names have been read in it reports which student would be at the front
of the line and which one wouldbe at the end of the line. You may assume that no two
students have the same name.*/
// Adam Tew ----CS1400

#include <iostream>

using namespace std;

int main(){
	int number, IntName;
	string name, firstName = "ZZ";

	cout << "\n*******************";
	cout << "\nStudent Line UP   |";
	cout << "\n*******************";

	cout << "\n\nEnter a number between 1 and 25 for the number of students";
	cout << "\n\nNumer: ";
	cin >> number;
	while(number < 1 || number > 25){
		cout << "\nEnter a number beween 1 and 25";
		cout << "\n\nNumber: ";
		cin >>number;
	}
	for(int i = 1; i <= number; i++){
		cout << "\tName " << i << ": ";
		cin >> name;
		if(name < firstName)firstName = name;
	}

	cout << "\nThe first person in line will be: ";
	cout << firstName;
	cout << "\n\n";

	return 0;
}