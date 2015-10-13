/*Write a program that asks for the names of three runners and the time it took each
of them to finish a race. The program should display who came in first, second, and
third place. Think about how many test cases are needed to verify that your problem
works corretly. (That is, how many different finish orders are possible?)

	Input Validation: Only allow the program to accept positive number for the times.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	string name1, name2, name3, firstName, secondName, thirdName;
	float time1, time2, time3, firstTime, secondTime, thirdTime;

	cout << "\nGive me the name of three runners";
	cout << "\nWho was the first person? ";
	cin >> name1;
	cout << "What was their time? ";
	cin >> time1;
	cout << "\nWho was the second person? ";
	cin >> name2;
	cout << "What was their time? ";
	cin >> time2;
	cout << "\nWho was the third person? ";
	cin >> name3;
	cout << "What was their time? ";
	cin >> time3;

	if(time1 > 0 && time2 > 0 && time3 > 0){
		if(time1 == time2 && time1 == time3 && time2 == time3){
			cout << "\nIt was a tie.\n";
		}else if((time1 > time2 && time1 > time3) && time2 > time3){
			firstTime = time1;
			firstName = name1;
			secondTime = time2;
			secondName = name2;
			thirdTime = time3;
			thirdName = name3;
		}else if((time1 > time2 && time1 > time3) && time3 > time2){
			firstTime = time1;
			firstName = name1;
			secondTime = time3;
			secondName = name3;
			thirdTime = time2;
			thirdName = name2;
		}else if((time2 > time1 && time2 > time3) && time1 > time3){
			firstTime = time2;
			firstName = name2;
			secondTime = time1;
			secondName = name1;
			thirdTime = time3;
			thirdName = name3;
		}else if((time2 > time1 && time2 > time3) && time3 > time1){
			firstTime = time2;
			firstName = name2;
			secondTime = time3;
			secondName = name3;
			thirdTime = time1;
			thirdName = name1;
		}else if((time3 > time1 && time3 > time2) && time1 > time2){
			firstTime = time3;
			firstName = name3;
			secondTime = time1;
			secondName = name1;
			thirdTime = time2;
			thirdName = name2;
		}else if((time3 > time1 && time3 > time2) && time2 > time1){
			firstTime = time3;
			firstName = name3;
			secondTime = time2;
			secondName = name2;
			thirdTime = time1;
			thirdName = name1;	
		}
	}else{
		cout << "\n\tInvalid input\n";
	}

	if(time1 > 0 && time2 > 0 && time3 > 0){
		cout << "\n\tThe winners are:";
		cout << "\n\t1st place goes to " << thirdName << " with a time of " << thirdTime;
		cout << "\n\t2nd place goes to " << secondName << " with a time of " << secondTime;
		cout << "\n\t3rd place goes to " << firstName << " with a time of " << firstTime;
	}
	
	return 0;
}