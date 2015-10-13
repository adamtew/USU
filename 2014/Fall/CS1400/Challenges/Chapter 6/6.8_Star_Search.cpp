/*A particular talent competition has 5 judges, each of whom awards a score between 0
and 10 to each performer. Fractional scores, such as 8.3, are allowed. A performer's
final score is determined by dropping the highest and lowest score received, then
averaging the 3 remaining scores. Write a program that uses these rules to calculate
and display a contestant's score. It should include the following functions:

	• void getJudgeData() should ask the user for a judge's score, store it in a
	  reference parameter variable, and validate it. This function should be called
	  by main once for each of the 5 judges.
	• double calcScore() should calculate and return the average of the 3 scores
	  that remain after dropping the highest and lowest scores the performer
	  received. This function should be called just once bymain and should be passed
	  the 5 scores.

Two additional functions, described below, should be called by calcScore, which uses
the returned information to determine which of the scores to drop.

	• int findLowest() should find and return the lowest of the 5 scores passed to it.
	• int findHighest() should find and return the highest of the 5 scores passed to 
	  it.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

void printTitle();
void getJudgeData(double&);
double calcScore(double, double, double, double, double);
int findLowest(double, double, double, double, double);
int findHighest(double, double, double, double, double);
int main(){
	
	printTitle();

	return 0;
}

void printTitle(){
	double judge1, judge2, judge3, judge4, judge5, average;

	cout << "\n***************";
	cout << "\nStar Search   |";
	cout << "\n***************\n\n";

	getJudgeData(judge1);
	getJudgeData(judge2);
	getJudgeData(judge3);
	getJudgeData(judge4);
	getJudgeData(judge5);

	average = calcScore(judge1, judge2, judge3, judge4, judge5);

	cout << "\n\tThe average score is " << average << endl;
}

void getJudgeData(double& score){

	cout << "What was the judges score? ";
	cin >> score;
	while(score < 0  && score > 10){
		cout << "\nEnter a number between 0 and 10.";
		cin >> score;
	}

}

double calcScore(double score1, double score2, double score3, double score4, double score5){
	int lowest, highest;
	double average;
	lowest = findLowest(score1, score2, score3, score4, score5);
	highest = findHighest(score1, score2, score3, score4, score5);

	average = (score1 + score2 + score3 + score4 + score5 - lowest - highest) / 3;

	return average;
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

}

int findHighest(double score1, double score2, double score3, double score4, double score5){

	if(score1 >= score2 && score1 >= score3 && score1 >= score4 && score1 >= score5)
		return score1;
	if(score2 >= score1 && score2 >= score3 && score2 >= score4 && score2 >= score5)
		return score2;
	if(score3 >= score1 && score3 >= score2 && score3 >= score4 && score3 >= score5)
		return score3;
	if(score4 >= score1 && score4 >= score3 && score4 >= score2 && score4 >= score5)
		return score4;
	if(score5 >= score1 && score5 >= score3 && score5 >= score4 && score5 >= score2)
		return score5;
}