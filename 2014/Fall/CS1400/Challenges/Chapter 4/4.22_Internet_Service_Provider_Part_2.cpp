/*Modify the program in problem 21 so it also displays how much money Package A
customers would save if they purchased packages B or C, and how much money package B
customers would save if they purchased package C. If there would be no savings, no
message should be printed.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	const float aCost = 9.95, bCost = 14.95, cCost = 19.95, 
				aRate = .08, bRate = .06;
	const int aTime = 300, bTime = 600;
	int minutes = 0; 
	char package;
	string name = "No input";
	float bill, hours, aHypo, bHypo, cHypo = 19.95, savings;

	cout << "\n***********************************";
	cout << "\nInternet Service Provider Part 2";
	cout << "\n***********************************";
	cout << "\n\n\t------------------------------";
	cout << "\n\t|Package      Monthly Cost   |";
	cout << "\n\t------------------------------";
	cout << "\n\t|  a)               $ 9.95   |";
	cout << "\n\t|  b)               $14.95   |";
	cout << "\n\t|  c)               $19.95   |";
	cout << "\n\t------------------------------";
	cout << "\n\n\tName: ";
	getline(cin, name);
	
	cout << "\tPackage: ";
	cin >> package;
	if(package != 'a' && package != 'b' && package != 'c')return 0;
	
	cout << "\tMinutes Used: ";
	cin >> minutes;
	hours = minutes / 60;
	if(minutes < 0)return 0;
	
	if(aCost < aCost + ((minutes - aTime) * aRate)){
		aHypo = aCost + ((minutes - aTime) * aRate);
	}else{
		aHypo = aCost;
	}

	if(bCost < bCost + ((minutes - bTime) * bRate)){
		bHypo = bCost + ((minutes - bTime) * bRate);
	}else{
		bHypo = bCost;
	}
	
	switch(package){
		case 'a': bill = aHypo;
			package = 'A';
			break;
		case 'b': bill = bHypo;
			package = 'B';
			break;
		case 'c': bill = cCost;
			package = 'C';
			break;
		default:
			break;
	}

	cout << right << fixed << setprecision(0);
	cout << "\n\n\t---------------------------";
	cout << "\n\t| Internet Bill           |";
	cout << "\n\t---------------------------";
	cout << "\n\t| Customer: " << setw(13) << name << " |";
	cout << "\n\t| Package: " << setw(14) << package << " |";
	cout << "\n\t| Hours: " << setw(16) << hours << " |" << setprecision(2);
	cout << "\n\t| Total: " << setw(10) << right << "$" << setw(6) << bill <<  " |";
	cout << "\n\t---------------------------";

	if(bill == aHypo && bill > bHypo){
		savings = aHypo - bHypo;
		cout << "\n-----------------------------------------";
		cout << "\n| Package B would have saved you $" << savings <<" |";
		cout << "\n-----------------------------------------";
	}

	if(bill == aHypo && bill > cHypo){
		savings = aHypo - cHypo;
		cout << "\n-----------------------------------------";
		cout << "\n| Package C would have saved you $" << savings << "  |";
		cout << "\n-----------------------------------------\n";
	}

	if(bill == bHypo && bill > cHypo){
		savings = bHypo - cHypo;
		cout << "\n-----------------------------------------";
		cout << "\n| Package C would have saved you $" << savings << "  |";
		cout << "\n-----------------------------------------\n";
	}

	return 0;
}