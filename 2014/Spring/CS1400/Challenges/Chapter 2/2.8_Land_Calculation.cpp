/*In the United States, land is often measured in square feet. In many other 
counteries it is measured in square meters. One acre of land is equivalent 
to 43,560 square feet. A square meter is equivalent to 10.7639 square feet. 
Write a program that computes and displays the number of square feet and the 
number of square meters in 1/4 acre of land.*/
//Hint: Because a square meter is larger than a square foot, there will be fewer
//square meters in 1/4 acre than there are square feet.
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	float sqMeter = 10.7639, sqAcreInFeet = 43560;

	cout << "\nThere are " << sqAcreInFeet / 4 
		<< " square feet in one fourth an acre.\n"
		<< "\nThere are " << (sqAcreInFeet / 4) / sqMeter
		<< " square meters in one fourth an acre.\n";


	return 0;
}