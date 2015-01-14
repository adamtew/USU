#include "Gratuity_Calculator.h"

using namespace std;

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