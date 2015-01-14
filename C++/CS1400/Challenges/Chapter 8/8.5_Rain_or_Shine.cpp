/*An amateur meteorologist wants to keep track of weather conditions during the
past year's three month summer season and has designated each day as either rainy
('R'), cloudy ('C'), or sunny ('S'). Write a program that stores this information
in a 3 x 30 array of characters, where the row indicates the onth (0 = June, 
1 = July, 2 = August) and the column indicates the day of the month. Note that data
is not being collected for the 31st of any month. The program should begin by 
reading the weather data in from a file. Then it should create a report that
displays for each month and for the whole three-month period, how many days were
rainy, how many were cloudy, and how many were sunny. It should also report which
of the three months had the largest number of rainy days. Data for the program can
be found in the RainOrShine.dat file.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <fstream>

using namespace std;

const int ROW = 3, COL = 30;
char stats[ROW][COL];

void printTitle();
void getData(char[][COL]);

int main(){
	
	printTitle();
	getData(stats);


	return 0;
}

void printTitle(){

	cout << "\n*****************";
	cout << "\nRain or Shine   |";
	cout << "\n*****************";
}

void getData(char array[][COL]){
	int i = 0, j = 0;
	char random;
	ifstream fin("RainOrShine.dat");	

	cout << endl;

	while(!fin.eof()){
		array[i][j++] = fin.get();
	}

	cout << "\n\tDate\tJune\tJuly\tAugust";
	cout << "\n\t------------------------------";
	for(j = 0; j < 30; j++){
		cout << "\n\t" << j + 1 << "\t" << array[0][j] << "\t" << 
		array[1][j] << "\t" << array[2][j];
	}

}