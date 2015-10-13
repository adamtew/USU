/*Write a client program that uses the Stats class you created for
Programming Challenge 9 to store and analyze "best" 100-yard dash times 
for each of the 15 runners on a track team. As in Programming Challenge
8, all I/O is done by the client program. In addition to main, the client
program should have two other functions: a getData function to accept
input from the user and send it to the Stats object and createReport 
function that creates and displays a report similar ro the one shown here

				Tulsa Tigers Track team

	Average 100 yard-dash time: 11.16 seconds
	Slowest runner: Jack		13.09 seconds
	Fastest runner: Will		10.82 seconds*/
// Adam tew ---- CS1400

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
	int lowest, highest, SIZE;
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
Stats getData(Stats, double);
void createReport(Stats);

int main(){
	Stats dash;
	double value;

	printTitle();
	dash = getData(dash, value);

	

	createReport(dash);
	

	
	return 0;
}

void printTitle(){

	cout << "\n*************************************";
	cout << "\n Stats Class and Track Statistics   |";
	cout << "\n*************************************";

}

Stats getData(Stats dash, double value){

	cout << "\n\n\tEnter the dash for each month?\n";
	for(int i = 0; i < 12; i++){
		cout << "\tEnter value: ";
		cin >> value;
		while(value < 0){
			cout << "Enter a valid number";
			cin >> value;
		}
		if(!dash.storeValue(value)){
			cout << "\nThat's more than enough";
			break;
		}
	}
	
	return dash;
}

void createReport(Stats dash){

	cout << fixed << setprecision(1);
	cout << "\n\n\t\tTulsa Tigers Track Team\n";
	cout << "\n\tAverage 100 yard-dash time: " << dash.getAverage();
	cout << "\n\tSlowest runner: Jack        " << dash.getLowest();
	cout << "\n\tFastest runner: Will        " << dash.getHighest();

}