/*Design a Tips class that calculates the gratuity on a restaurant meal. Its only
class member variable taxRate, should be set by a one-parameter constructor to
whatever rate is passed to it when a Tips object is created. If no argument is passed,
a default tax rate of .065 should be used. The class should have just one public
function, computeTip. This function needs to accept two arguments, the total bill
amount and the tip rate. It should use this information to compute what the cost
portion of the bill to compute  what the cost of the meal was before the tax was added. 
It should then applu the tip rate to just the meal cost portion of the bill and return 
the tip amount. Demonstrate the class by creating a program that creates a single Tips 
object, then loops multiple times to allow the program user to retrieve the correct 
tip amount using various bill totals and desired tip rates.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

class Tips{

private:
	double taxRate;

public:
	Tips();
	Tips(double);

	double computeTip(double, double);

};

Tips::Tips(){
	taxRate = .065;
}

Tips::Tips(double t){
	if(t < 0)t = 0;
	taxRate = t;
}

double Tips::computeTip(double bill, double tipRate){
	double meal = bill + (bill * taxRate);
	meal = meal * tipRate;

	return meal;
}

void printTitle();

int main(){
	double cost = 50.6, tax = .9, tip = .3;

	Tips itip, utip(tax);

	printTitle();

	cout << "\nitip: " << itip.computeTip(cost, tip);
	cout << "\nutip: " << utip.computeTip(cost, tip);


	return 0;
}

void printTitle(){

	cout << "\n***********************";
	cout << "\nGratuity Calculator   |";
	cout << "\n***********************";

}