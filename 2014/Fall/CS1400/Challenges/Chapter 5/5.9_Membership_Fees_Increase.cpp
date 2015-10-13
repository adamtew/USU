/*A country  lub, which currently charges $2500 per year for membership. has announced
it will increase its membership fee by 4% eah year for the next six years. Write a 
program that uses a loop to display the projected rates for the next six years.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	float rate = .04, charge = 2500;


	cout << "\n\n***************************";
	cout << "\nMembership Fees Increase  |";
	cout << "\n***************************";

	cout << "\n\n\t----------------";
	for(int i = 0; i <=6; i++){
		charge += charge * rate;
		cout << "\n\t" << i << "\t" << charge;
	}
	cout << "\n\t----------------\n\n";

	return 0;
}