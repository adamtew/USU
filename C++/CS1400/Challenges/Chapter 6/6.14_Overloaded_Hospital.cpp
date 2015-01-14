/*Write a program that computes and displays the charges for a patient's hospital 
stay. First, the program should ask if the patient was admitted as an in-patient or an
out-patient. If the patient was an in-patient the followingdata should be entered:

	• The number of days spent in the hospital
	• The daily rate
	• Charges for hospital services (lab tests, etc.)
	• Hospital medication charges.

If the patient was an out-patient the following data should be entered:

	• Charges for hospital services (lab tests, etc.)
	• Hospital medication charges.

Use a single, seperate function to validate that no input is less then zero. If it is,
it should be re-entered before being returned.

Once the required data has been input and validated, the program should use two
overloaded functions to calculate the totl charges. One of the functions accept
arguments for the in-patient data, while the other function accepts arguments for
out-patient data. Both functions should return the total charges.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

void printTitle();
	// in-patient
double ioPatient(double, double, double, double);
	// out-patient
double ioPatient(double, double);
double validate(double);

int main(){
	char patient;
	double dailyRate, services, medication, daysInHospital, total;

	printTitle();
	cout << "\n\n\tWhat kind of patient was it? ";
	cout << "\n\t\"i\" for in-patient\n\t\"o\"for out-patient\n\tPatient Type: ";
	cin >> patient; 

	switch(patient){
		case 'i':
			cout << "\n\n\tEnter the following information for in-patient charges:";
			cout << "\n\tDays spent in hospital: ";
			cin >> daysInHospital;
			validate(daysInHospital);
			cout << "\tDaily rate: ";
			cin >> dailyRate;
			validate(dailyRate);
			cout << "\tCharges for services: ";
			cin >> services;
			validate(services);
			cout << "\tMedication charges: ";
			cin >> medication;
			validate(medication);

			total = ioPatient(daysInHospital, dailyRate, services, medication);

			break;
		case 'o':
			cout << "\n\n\tEnter the following information for out-patient charges:";
			cout << "\n\tSevice charges (lab tests, etc): ";
			cin >> services;
			validate(services);
			cout << "\tMedication Charges: ";
			cin >> medication;
			validate(medication);

			total = ioPatient(services, medication);
			break;
		default:
			cout << "\n\tThat wasn't one of the suggestions...";
			break;
	}

	cout << "\n\n\tYour total charges come to $" << total << endl;

	return 0;
}

void printTitle(){

	cout << "\n***********************";
	cout << "\nOverloaded Hospital   |";
	cout << "\n***********************";

}

double validate(double number){

	while(number < 0){
		cout << "\n\tEnter a number valid number (greater than 0): ";
		cin >> number;
	}
	return number;
}
	
	//In-patient function
double ioPatient(double daysInHospital, double dailyRate, double services, 
	double medication){
	dailyRate = dailyRate / 100;
	return (dailyRate * daysInHospital) + services + medication;
}

	//Out-patient function
double ioPatient(double services, double medication){

	return services + medication;
}