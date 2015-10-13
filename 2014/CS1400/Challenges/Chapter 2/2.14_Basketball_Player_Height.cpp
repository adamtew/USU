/*The star player of a high school basketball team is 73 inches tall. 
Write a program to compute anddisplay the height in feet / inches form.*/
//Hint: Try using the modulus and integer divide operations.
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
		int height = 73;

		cout << "\nThe player is " << height / 12 << " foot " << height % 3 << "\n";


	return 0;
}