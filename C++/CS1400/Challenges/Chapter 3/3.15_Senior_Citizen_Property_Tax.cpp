/*Madison County provides a $5000 homeowner exemption for senior citizens.
For example, if their house is valued at $158,000 its assessed value would be 
$94,800, as explained above. However they would only pay tax on $89,800.
At last year's tax rate of $2.64 for each $100 of assessed value, their property 
tax would be $2370.72. In addition to the tax break, senior citizens are allowed to 
pay their property tax in 4 equal payments The quarterly payment due on this property 
would be $592.68. Write a program that asks the user to input the actual value of 
a piece of property and the current tax rate for eah $100 of assessed value. 
The program should then calculate and report how much annual property tax a senior 
homeowner will be charged for this property and what their quarterly bill will be.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	const float tax = .6;
	float propVal = 0, propTax = 0, assessed, quarterlyCharge, annualCharge,
		assessedTax;

	cout << "\nWhat is the value of the house? ";
	cin >> propVal;
	cout << "What is the tax rate for each $100? ";
	cin >> propTax;

	assessed = (propVal) * tax;
	assessedTax = assessed - 5000;
	annualCharge = (assessedTax / 100) * propTax;
	quarterlyCharge = annualCharge / 4;

	cout << fixed << setprecision(2);
	cout << "\nThe assessed value of the home is $" << assessed;
	cout << "\nThe taxed assessed value of the home is $" << assessedTax;
	cout << "\nThe annual charge wll be $" << annualCharge;
	cout << "\nThe quarterly charge will be $" << quarterlyCharge << endl;
	return 0;
}