/*Design a PayRoll class that has data members for an employee's hourly
pay rate and number of hours worked. Write a program with an array of
seven PayRoll objects. The program should read the number of hours each
employee worked and their hourly pay rate from a file and call class
functions to store this information in the appropriate objects. It should
then call a class function, once for each object, to return the employee's
gross pay, so this information can be displayed. Sample data to test this
program can be found in the payroll.dat file.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <fstream>

using namespace std;

class PayRoll{
public:
	PayRoll();
	void setRate(double);
	void setHours(double);
	double getRate();
	double getHours();
	double getPay();

private:
	double payRate, hours;
};

PayRoll::PayRoll(){

}

void PayRoll::setRate(double number){
	payRate = number;
}

void PayRoll::setHours(double number){
	hours = number;
}

double PayRoll::getRate(){
	return payRate;
}

double PayRoll::getHours(){
	return hours;
}

double PayRoll::getPay(){
	double gross = hours * payRate;
	return gross;	
}

const int SIZE = 7;
PayRoll pay[SIZE];

void printTitle();
void getData(PayRoll[]);
void printGross(PayRoll[]);

int main(){

	printTitle();
	getData(pay);
	printGross(pay);

	return 0;
}

void printTitle(){

	cout << "\n****************************";
	cout << "\nArray of Payroll Objects   |";
	cout << "\n****************************";

}

void getData(PayRoll array[]){
	double hours, rate;

	ifstream fin("payroll.dat");
	for(int i = 0; i < SIZE; i++){
		fin >> hours;
		fin >> rate;
		array[i].setHours(hours);
		array[i].setRate(rate);
	}
}

void printGross(PayRoll array[]){

	cout << "\n\n\tHours worked\tPay Rate\tGross";
	cout << "\n\t-------------------------------------";
	for(int i = 0; i < SIZE; i++){
		cout << "\n\t\t" << array[i].getHours();
		cout << "\t   " << array[i].getRate();
		cout << "\t\t" << array[i].getPay();
	}

}