#ifndef REPORT_HANDLING_H
#define REPORT_HANDLING_H

#include <iostream>

using namespace std;

class Heading{

private:
	string companyName, reportName;

public:
	Heading();
	Heading(string, string);

	void oneLine();
	void boxed();

};

#endif