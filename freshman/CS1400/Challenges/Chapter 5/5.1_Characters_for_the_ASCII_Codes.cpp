/*Write a program that uses a loop to display the characters for each ASCII code 32
through 127. Display 16 characters on each line with one space between characters.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	char a = 32;

	cout << "\n\n*******************************";
	cout << "\nCharacters for the ASCII Codes";
	cout << "\n*******************************\n\n";

	for(int i = 32; i <= 127; i++){
		//if(i == 48 || i == 64 || i == 80 || i == 96 || i == 112)		
		if((i % 16) == 0){
			cout << "\n";
			cout << " " << a++;	
		}else{
			cout << " " << a++;
		}
	}

	cout << "\n\n";

	return 0;
}