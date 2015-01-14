/*Create a CharConverter class that performs various operations on strings.
It should have the following two public member functions to start with.
Your instructor may ask you to add additional functions to the class.

	• The uppercase member function accepts a string and returns a copy
	  of it with all lowercase letters converted to uppercase. If a 
	  character is already uppercase, or is not a letter, it should be
	  left alone.
  	• The properWords member function accepts a string of words seperated
  	  by spaces and returns a copy of it with the first letter of each
  	  word converted to uppercase.

Write a simple program that uses the class. It should prompt the user to
input a string. Then it should call the properWords function and display
the resulting string. Finally, it should call the uppercase function and
display this resulting string. The program should loop to allow additional
strings to be converted and displayed until the user choose to quit.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <string>

using namespace std;

class CharConverter{
public:
	CharConverter();

	string uppercase(string);
	string properWords(string);

private:


};

CharConverter::CharConverter(){

}

string CharConverter::uppercase(string str){
	string newString;

	for(int i = 0; i < str.size(); i++){
		if(str[i] >= 97 && str[i] < 123){
			str[i] = str[i] - 32;
		}
		newString += str[i];
	}

	return newString;
}

string CharConverter::properWords(string str){
	string newString;

	for(int i = 0; i < str.size(); i++){
		if((str[i] >= 97 && str[i] < 123) && (i == 0)){
			str[i] = str[i] - 32;
		}
		newString += str[i];
	}

	return newString;

}

void printTitle();

int main(){
	CharConverter reg;
	string word, pWord, uWord;

	printTitle();

	cout << "\nEnter a word to be converted: ";
	cin >> word;

	pWord = reg.properWords(word);
	uWord = reg.uppercase(word);

	cout << "\n" << word << " propperly is  " << pWord;
	cout << "\n" << word << " uppercased is " << uWord;


	return 0;
}

void printTitle(){

	cout << "\n*****************************";
	cout << "\nCharacter Converter Class   |";
	cout << "\n*****************************";

}
