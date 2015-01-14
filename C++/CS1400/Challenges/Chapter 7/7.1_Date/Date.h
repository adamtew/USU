#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date{

private:
	int month, day, year;

public:
	Date();

	Date(int, int, int);

	void format1();
	void format2();
	void format3();
	bool validate(int);

};

#endif