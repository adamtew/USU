/*Modfiy the MovieData program written for Programming Challenge 8 to include two
more members that hold the movie's production costs and first-year revenues. The
constructor should be modified so that all six member values can be specified when a
MovieData variable is created. Modify the function that displays the movie data to 
display the movie data to display the title, director, release year, running time,
and first year's profit or loss. Also, improve the program by having the MovieData
variables passed to the display function as constant references.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

struct MovieData{

	string title, director;
	int yearReleased, runTime;
	double prodCost, revenue;

	MovieData(){
		title = "Unknown Title";
		director = "Unknown Director";
		yearReleased = 0000;
		runTime = 00;
		prodCost = 0.0;
		revenue = 0.0;
	}

};
void printTitle();
void displayData(const MovieData&);

int main(){
	MovieData tangled,frozen;
	tangled.title = "Tangled";
	tangled.director = "Not sure...";
	tangled.yearReleased = 2010;
	tangled.runTime = 110;
	tangled.prodCost = 50000;
	tangled.revenue = 100000;

	printTitle();
	displayData(tangled);
	displayData(frozen);


	return 0;
}

void printTitle(){
	
	cout << "\n***************";
	cout << "\nMovie Profit  |";
	cout << "\n***************";

}

void displayData(const MovieData& movie){

	cout << "\n\n" << movie.title;
	cout << "\n" << movie.director;
	cout << "\n" << movie.yearReleased;
	cout << "\n" << movie.runTime;
	cout << "\n" << movie.prodCost;
	cout << "\n" << movie.revenue;

}