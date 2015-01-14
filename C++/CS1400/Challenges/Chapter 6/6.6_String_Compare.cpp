/*You know that the == operator can be used to test if two string objects are equal.
However, you will recall that they are not considered equal, even when they hold the
exact same letters, if the cases of any letters are different. So, for example, if
name1 = "Jack" and name2 = "JACK", they are not considered the same. Write a program
that asks the user to enter two names and stores them in string objects. It should 
then report whether or not, ignoring case, they are the same.
To help the program accomplish its task, it should use two functions in addition to 
main, upperCaseIt() and sameString(). Here are their function headers.

	string upperCaseIt(string s)
	Boolean sameString (string s1, string s2)

The sameString function, which receives the two strings to be compared, will need to 
call upperCaseIt for each of them before testing if they are the same. The upperCaseIt
function should use a loop so that it can call the toupper function for every
character in the string it receives before returning it back to the sameString
function.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <string>
using namespace std;

void printTitle();
string upperCaseIt(string);
bool sameString(string, string);

int main(){
	string name1, name2;
	bool same;
	printTitle();

	cout << "\tEnter two names and I will compare them.";
	cout << "\n\tFirst name: ";
	cin >> name1;
	cout << "\tSecond Name: ";
	cin >> name2;

	name1 = upperCaseIt(name1);
	name2 = upperCaseIt(name2);
	same = sameString(name1, name2);

	if(same){
		cout << "\n\n\tYep, They're the same\n";
	}else{
		cout << "\n\n\tYeah, nope, not the same.\n";
	}

	return 0;
}

void printTitle(){

	cout << "\n******************";
	cout << "\nString Compare   |";
	cout << "\n******************\n\n";
}

string upperCaseIt(string s){

	for(int i = 0; i < s.length(); i++){
		s[i] = toupper(s[i]);
	}

	return s;
}

bool sameString(string s1, string s2){

	if(s1 == s2)return true;
	if(s1 != s2)return false;
}