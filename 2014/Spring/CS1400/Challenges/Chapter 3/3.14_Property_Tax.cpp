/*Madison County collects property taxes on the assessed value of property, which is
60 percent of its actual value. For example, if a house is valued at $158,000 its
assessed value is $94,800. This is the amount the homeowner pays tax on. At last
year's tax rate of $2.64 for each $100 of assessed value, the annual property tax
for this house would be $2502.72. Write a program that asks the user to input the 
actual value of a piece of property and the current tax rate for each $100 of assessed
value. The program should then calculate and report how much annual property
tax the homeowner will be charged for this property.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	const float propTax = .6;
	float propVal = 0, taxRate = 0, annualTax, assessed;

	cout << "\nWhat is the property value? ";
	cin >> propVal;
	cout << "What is the tax rate for each $100? ";
	cin >> taxRate;

	assessed = propVal * propTax;
	annualTax = (assessed / 100) * taxRate;

	cout << fixed << setprecision(2);
	cout << "\nThe assessed value of the house is $" << assessed;
	cout << "\nThe annual charge will be $" << annualTax << endl;

	return 0;
}