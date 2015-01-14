#ifndef PiggyBank_H
#define PiggyBank_H


#include <cstdlib>
#include <iostream>

using namespace std;

//class specification
class PiggyBank{
public:

	bool broken = false;
	double savings;

	//constructor
	PiggyBank(){ 
		broken = false;
		savings = 0;
	}
	PiggyBank(double c, bool b);

	//member functions
	double countSavings();
	void depositMoney(double);
	void smash();

	//destructor
	~PiggyBank(){
		if (broken)
			cout << "NOOOOOOOOOOOO!\n";
	}

private:
	//private data

};


#endif