/*You have been gien a job as a programmer on a Cyborg supercomputer. In order to 
accomplish some alculations, you need to know how many bytes the following data 
types use: char, int, float, and double. You don't have any manuals, so you can't 
look up this information. Write a C++ program that will dertermine the amount of 
memory used by each of these types and display the information on the screen*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){

	cout << "\nThe size of a   char is " << sizeof(char) << " bytes.";
	cout << "\nThe size of an   int is " << sizeof(int) << " bytes.";
	cout << "\nThe size of a  float is " << sizeof(float) << " bytes.";
	cout << "\nThe size of a double is " << sizeof(double) << " bytes.";
	cout << "\n";

	return 0;
}