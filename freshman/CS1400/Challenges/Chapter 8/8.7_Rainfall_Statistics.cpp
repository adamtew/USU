/*Write a modular program that analyzes a year's worth of rainfall data.
In addition to main, the program should ahve a getData function that
accepts the total rainfall for each of 12 months from the user and stores
it in a double array. It should also have four value-returning functions
that compute and return to main the totalRainfall, averageRainfall,
driestMonth, and wettestMonth. These alst two function return the number
of the month with the lwoest and highest rainfall amounts, not the amount
of rain that fell those months. Notice that this month number can be used
to obtain the amount of rain that fell those months. This information 
should be used either by main or by a displayReport function called by 
main or by a displayReport function called by main to print a summary
rainfall report similar to the following:

		2010 Rain Report for Neversnows County

	Total rainfall: 23.19 inches
	Average monthly rainfall: 1.93 inches
	The least rain fell in Januart with 0.24 inches.
	The most rain fell in April with 4.29 inches.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 12;
double data[SIZE];
string months[SIZE] = {"January", "Februray", "March", "April",
						"May", "June", "July", "August", "September",
						"October", "November", "December"};

void printTitle();
void getData(double[], string[]);
double totalRainfall(double[]);
double averageRainfall(double[]);
int driestMonth(double[]);
int wettestMonth(double[]);
void displayReport(double[], string[], double, double, int, int);

int main(){
	double tot, avg, dri, wet;

	printTitle();
	getData(data, months);
	tot = totalRainfall(data);
	avg = averageRainfall(data);
	dri = driestMonth(data);
	wet = wettestMonth(data);
	displayReport(data, months, tot, avg, dri, wet);

	return 0;
}

void printTitle(){

	cout << "\n***********************";
	cout << "\nRainfall Statistics   |";
	cout << "\n***********************";
}

void getData(double array[], string month[]){

	cout << "\nEnter the rainfall for each month\n";
	for(int i = 0; i < SIZE; i++){
		cout << month[i] << ": ";
		cin >> array[i];
	}

}

double totalRainfall(double array[]){
	double total;

	for(int i = 0; i < SIZE; i++){
		total += array[i];
	}

	return total;
}

double averageRainfall(double array[]){
	double average = 0;

	for(int i = 0; i < SIZE; i++){
		average += array[i];
	}

	average = average / SIZE;

	return average;
}

int driestMonth(double array[]){
	double driest = array[0];
	int place = 0;

	for(int i = 0; i < SIZE; i++){
		if(array[i] < driest){
			driest = array[i];
			place = i;
		}
	}
	return place;
}

int wettestMonth(double array[]){
	double wettest = array[0];
	int place = 0;

	for(int i = 0; i < SIZE; i++){
		if(array[i] > wettest){
			wettest = array[i];
			place = i;
		}
	}
	
	return place;
}

void displayReport(double array[], string month[], double total, 
	double average, int driest, int wettest){

	cout << fixed << setprecision(1);
	cout << "\n\n\t\t2014 Rain Report for Cache County\n";
	cout << "\n\tTotal rainfall: " << total;
	cout << "\n\tAverage rainfall: " << average;
	for(int i = 0; i < SIZE; i++){
		if(i == driest)cout << "\n\tThe least rain fell in " <<
			month[i] << " with " << array[i] << " inches.";
	}
	for(int i = 0; i < SIZE; i++){
		if(i == wettest)cout << "\n\tThe most rain fell in " <<
			month[i] << " with " << array[i] << " inches.";
	}
	cout << endl;
}