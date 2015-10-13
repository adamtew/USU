/*	• Write a program that calculates the average ofa groups of test scores, where the
	lowest score in the group is dropped. It should use the following functions:
		• void getScore() should ask the user for a test score, store it in a reference
		  parameter variable, and validate that it is not lower than 0 or higher than
		  100. This function should be called by main once for each of the five
		  scores to be entered.

		• void calcAverage() should calculate and display the average of the four
		  highest scores. This function should be called just once by main and be
		  passed the five scores.

		• int findLowest() should find and return the lowest of the five scores
		  passed to it. It should then be called by calcAverage, which uses the 
		  function to determine which one of the five scores to drop.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

void printTitle();
void getScore(double&);
void calcAverage(double, double, double, double, double);
int findLowest(double, double, double, double, double);

int main(){
	double score1, score2, score3, score4, score5;

	printTitle();

	
	getScore(score1);
	getScore(score2);
	getScore(score3);
	getScore(score4);
	getScore(score5);
	
	calcAverage(score1, score2, score3, score4, score5);



	return 0;
}

void printTitle(){

	cout << "\n*********************";
	cout << "\nLowest Score Drop   |";
	cout << "\n*********************\n\n";

}

void getScore(double& score){
	

	cout << "\tEnter score: ";
	cin >> score;
	while(score < 0 || score > 100){
		cout << "Enter a value greater than 0 and less than 100\nEnter Score: ";
		cin >> score;
	}

}

void calcAverage(double score1, double score2, double score3, double score4, double score5){
	int lowest;
	cout << "\nThe average is score is: " << (score1 + score2 + score3 + score4 + score5) /5;
	lowest = findLowest(score1, score2, score3, score4, score5);

	cout << "\nThe We will drop the " << lowest << " because it's the lowest";
}

int findLowest(double score1, double score2, double score3, double score4, double score5){
	
	if(score1 <= score2 && score1 <= score3 && score1 <= score4 && score1 <= score5)
		return score1;
	if(score2 <= score1 && score2 <= score3 && score2 <= score4 && score2 <= score5)
		return score2;
	if(score3 <= score1 && score3 <= score2 && score3 <= score4 && score3 <= score5)
		return score3;
	if(score4 <= score1 && score4 <= score3 && score4 <= score2 && score4 <= score5)
		return score4;
	if(score5 <= score1 && score5 <= score3 && score5 <= score4 && score5 <= score2)
		return score5;

	return 0;
}