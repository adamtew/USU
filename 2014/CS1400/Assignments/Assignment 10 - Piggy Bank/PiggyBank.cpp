#include "PiggyBank.h"

using namespace std;

PiggyBank::PiggyBank(double c, bool b){
	if (!broken){
		savings = c;
		broken = b;
	}
}

double PiggyBank::countSavings(){
	if (!broken)return savings;
	return 0;
}

void PiggyBank::depositMoney(double cash){
	if (!broken && cash > 0)
	savings += cash;
}

void PiggyBank::smash(){
	broken = true;
	cout << "The smahed piggybank had $" << savings << endl;
}
