/*Write a program that uses nested loops to display the triangle pattern shown below.

	+
	+++
	+++++
	+++++++
	+++++
	+++
	+ 		*/
// Adam Tew ---- CS1400
#include <iostream>

using namespace std;

int main(){
	
	for(int i = 0; i <= 7; i++){
 		cout << "\n";
 		for(int j = 0; j <= 10; j++){
 			cout << " ";
 			//if(j == i)cout << "+";
 			if(j == 5 && i == 1)cout << "+";
 			if(j == 5 && i == 2)cout << "+++";
 			if(j == 5 && i == 3)cout << "+++++";
 			if(j == 5 && i == 4)cout << "+++++++";
 			if(j == 5 && i == 5)cout << "+++++";
 			if(j == 5 && i == 6)cout << "+++";
 			if(j == 5 && i == 7)cout << "+";
 		}
 	}

	return 0;
}