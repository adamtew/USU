/*Write a program that uses a structure named CorpData to store the following
information on a company division:

	Division name (such as East, West, North, or South)
	First quarter sales
	Second quarter sales
	Third quarter sales
	Fourth quarter sales

Include a constructor that allows the division name and four quarterly sales amounts
to be specified at the time a CorpData variable is created.

The program should create four CorpData variables, each representing one of the
following corporate divisions: East, West, North, and South. These variables should
be passed one at a time, as constant references, to a function that computes the 
division's annual sales total and quarterly average, and displays these along with
the division name.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

struct CorpData{
	string name;
	double first, second, third, fourth;

	CorpData(string n = "Division", double f = 0, double s = 0, double t = 0, 
		double fo = 0){
		name 	= n;
		first 	= f;
		second 	= s;
		third 	= t;
		fourth 	= fo;
	}
};

void printTitle();
void printDivision(const CorpData&);

int main(){
	CorpData north("North",500,600,700,800), 
			south("South",100,600,200,500), 
			east("East",250,1000,216.8,45), 
			west("West",99,99,2000,1500);
	
	printTitle();

	printDivision(north);
	printDivision(south);
	printDivision(east);
	printDivision(west);

	cout << endl;

	return 0;
}

void printTitle(){

	cout << "\n************************";
	cout << "\nCorporate Sales Data   |";
	cout << "\n************************";

}

void printDivision(const CorpData& d){
	double avg = (d.first + d.second + d.third + d.fourth) / 4;
	double total = d.first + d.second + d.third + d.fourth;
	cout << "\n\nDivision Name:     " << d.name;
	cout << "\nAnnual earnings:   $" << total;
	cout << "\nQuarterly average: $" << avg;
}