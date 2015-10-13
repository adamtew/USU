/*Write a program to find a baseball player's batting average. The program 
should ask the user to enter the number of times the player was at 
bat and the number of hits he got. It should then display his batting 
average to 4 decimal places.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	float atBat = 0, numHits = 0, batAvg = 0;

	cout << "\nHow many times did the player bat? ";
	cin >> atBat;
	cout << "How many hits did the player get? ";
	cin >> numHits;

	batAvg = numHits / atBat;

	cout << fixed << setprecision(4);
	cout << "\nThe players batting average was " << batAvg << endl;

	return 0;
}