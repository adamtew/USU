/*Write a program that displays an inchworm on the left-hand side of the screen,
facing right. Then slowly move him accross the screen, until he disappears off the 
right-hand side. You may wish to do this in a loop so that after disappearing to
the right, the worm appears again on the left. The diagram below shows how he may
look at various points on the screen.

		\/ 				\/ 				\/ 					\/ 					\/
		00 			 0  00 			000 00 				 0  00  				00
~000000000		~0000 0000 		~000   000 			~0000 0000 			~000000000  */
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

void printTitle();

int main(){
	
	printTitle();

	return 0;
}

void printTitle(){
	
	cout << "\n*******************";
	cout << "\nMoving Inchworm   |";
	cout << "\n*******************";

}