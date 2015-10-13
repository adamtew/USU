/*Write a program that uses a structure names MovieData to store the following 
information about a movie:

	Title
	Director
	Year Released
	Running time (in minutes)

Include a constructor that allows all four of these member data values to be specified
at the time a MovieData variable is created. The program should create two MovieData
variables and pass each one in turn to a function that displays the information about
the movie in a clearly formatted manner. pass the MovieData variables to the display
function by value.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

struct MovieData{

	string title, director;
	int yearReleased, runTime;

	MovieData(){
		title = "Unknown Title";
		director = "Unknown Director";
		yearReleased = 0000;
		runTime = 00;
	}

};
void printTitle();
void displayData(MovieData);


int main(){

	MovieData tangled,frozen;
	tangled.title = "Tangled";
	tangled.director = "Not sure...";
	tangled.yearReleased = 2010;
	tangled.runTime = 110;

	printTitle();
	displayData(tangled);
	displayData(frozen);

	return 0;
}

void printTitle(){

	cout << "\n**************";
	cout << "\nMovie Data   |";
	cout << "\n**************";

}

void displayData(MovieData movie){

	cout << "\n\n" << movie.title;
	cout << "\n" << movie.director;
	cout << "\n" << movie.yearReleased;
	cout << "\n" << movie.runTime;

}