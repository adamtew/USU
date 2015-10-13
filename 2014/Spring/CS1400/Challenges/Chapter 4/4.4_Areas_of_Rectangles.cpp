/*The area of a rectangle is the rectangle's length times its width. Write a program
that asks for the length and the width of two rectangle. The program should then
tell the user which rectangle has the greater area, or if the areas are the same.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	float recLen1 = 0, recWid1 = 0, recLen2 = 0, recWid2 = 0, a1, a2;

	cout << "\n    Give me the length and width of two rectangles and I'll\n"
		<< "     tell you which one has a greater area.";
	cout << "\n\n\t1st Rectangle Length: ";
	cin >> recLen1;
	cout << "\t1st Rectangle Width : ";
	cin >> recWid1;
	cout << "\t2nd Rectangle Length: ";
	cin >> recLen2;
	cout << "\t2nd Rectangle Width : ";
	cin >> recWid2;

	a1 = recLen1 * recWid1;
	a2 = recLen2 * recWid2;

	if(a1 > a2){
		cout << "\n\tRectangle 1 is bigger with an area of " << a1 << endl;
	}else if(a2 > a1){
		cout << "\n\tRectangle 2 is bigger with an area of " << a2 << endl;
	}else{
		cout << "\n\tThey're the same size with an area of " << a1 << endl;
	}


	return 0;
}