/*Create a Stats class whose member data includes an array capable of
storing 30 double data values, and whose member functions include total,
average, lowest, and highest functions for returning information about
the data to the client program. These are general versions of the same
functions you created for Programming Challenge 7, but now they belong
to the Stats class, not the application program. In addition to these
functions, the Stats class should have a Boolean storeValue function
that accepts a double value from the client program and stores it in
the the array, so it will know where to put the next value it receives
and will know how many values there are to process when it is carrying
out its other functions. It is also the job of this function to make
sure that no more than 30 values are accepted. If the storeValue
functionis able to successfully store the value sent to it, it should
return true to the client program. However, if the client program 
tries to store a thirty-first value, the function should not store the
value and should return false to the client program.

The client program should create and use a Stats object to carry out
the same rainfall analysis requested by Programming Challenge 7. Notice
that the Stats object does no I/O. All input and output is done by the
client program.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Stats{

public:
	Stats();
	double getTotal();
	double getAverage();
	int getLowest();
	int getHighest();
	bool storeValue(double);

private:
	double total, average;
	int lowest, highest;
	int SIZE;
	vector<double> vec;

};

Stats::Stats(){
	SIZE = 0;

}

double Stats::getTotal(){
	total = 0;

	for(int i = 0; i < SIZE; i++){
		total += vec[i];
	}

	return total;
}

double Stats::getAverage(){
	average = 0;

	for(int i = 0; i < SIZE; i++){
		average += vec[i];
	}

	average = average / SIZE;

	return average;
}

int Stats::getLowest(){
	lowest = vec[0];
	int place = 0;

	for(int i = 0; i < SIZE; i++){
		if(vec[i] < lowest){
			lowest = vec[i];
			place = i;
		}
	}
	return lowest;
}

int Stats::getHighest(){
	highest = vec[0];
	int place = 0;

	for(int i = 0; i < SIZE; i++){
		if(vec[i] > highest){
			highest = vec[i];
			place = i;
		}
	}
	
	return highest;
}

bool Stats::storeValue(double number){
		
	if(vec.size() < 12){
		vec.push_back(number);
		SIZE += 1;
		return true;
	}else{
		return false;
	}
}

void printTitle();

int main(){
	Stats rainfall;
	double value;

	printTitle();

	cout << "\n\n\tEnter the rainfall for each month?\n";
	for(int i = 0; i < 12; i++){
		cout << "\tEnter value: ";
		cin >> value;
		while(value < 0){
			cout << "Enter a valid number";
			cin >> value;
		}
		if(!rainfall.storeValue(value)){
			cout << "\nThat's more than enough";
			break;
		}
	}

	cout << fixed << setprecision(1);
	cout << "\n\n\t\t2014 Rain Report for Cache County\n";
	cout << "\n\tTotal  : " << rainfall.getTotal();
	cout << "\n\tAverage: " << rainfall.getAverage();
	cout << "\n\tLowest : " << rainfall.getLowest();
	cout << "\n\tHighest: " << rainfall.getHighest();
	return 0;
}

void printTitle(){

	cout << "\n****************************************";
	cout << "\n Stats Class and Rainfall Statistics   |";
	cout << "\n****************************************";

}