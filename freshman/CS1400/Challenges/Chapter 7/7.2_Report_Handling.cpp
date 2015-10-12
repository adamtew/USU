/*Design a class called Heading that has data members to hold the company name and the
report name. A two-parameter default constructor should allow these to be specified at
the time a new Heading object is created. If the user creates a Heading object without
passing any arguments, "ABC Industries" should be used as a default value for the 
company name and "Report" should be used as a default for the report name. The class
should have member function to printa heading in either one-line format, as shown
here:

	Pet Pals Payroll Report

or in four-line "boxed" format, as shown here:

	*****************************
				Pet Pals		
			Payroll Report
	*****************************
Try to figure out a way to center the headings on the screen, based on their lengths.
Demonstrate the class by writing a simple program that uses it.*/
// Adam Tew ---- CS1400
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

Heading::Heading(){
	companyName = "ABC Industries";
	reportName = "Report";
}
Heading::Heading(string cn, string rn){

	companyName = cn;
	reportName = rn;

}

void Heading::oneLine(){

	cout << companyName << " " << reportName;

}

void Heading::boxed(){
	int cLength = companyName.length();
	int rLength = reportName.length();

	cout << "\n*****************************\n";
	for(int i = 0; i < cLength; i++){
		if(i % 2 == 0 && cLength < rLength)cout << "  ";
		if(i % 3 == 0 && cLength > rLength)cout << " ";
	}
	cout << companyName << "\n";
	for(int i = 0; i < rLength; i++){
		if(i % 2 == 0 && cLength > rLength)cout << "  ";
		if(i % 3 == 0 && cLength < rLength)cout << " ";
	}
	cout << reportName;		
	cout << "\n*****************************\n";


}


int main(){
	
	Heading company1, company2("TewFinder", "Employee Earnings");

	cout << endl;company1.oneLine();
	cout << endl;company2.oneLine();

	cout << endl;company1.boxed();
	cout << endl;company2.boxed();



	return 0;
}