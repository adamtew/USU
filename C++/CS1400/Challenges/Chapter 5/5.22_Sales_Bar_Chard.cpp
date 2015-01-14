/*Write a program that asks the user to enter today's sales rounded to the nearest
$100 for each of three stores. The program should then display a bar graph comparing
each store's sales. Create each bar in the graph by displaying a row of asterisks.
Each asterisk should represent $100 of sales.

Here is an example of the program's output. User input is shown in bold.

Enter today's sales for store 1: 1000[Enter]
Enter today's sales for store 2: 1200[Enter]
Enter today's sales for store 3: 900[Enter]

		DAILY SALES
	(each * = $100)
Store 1: **********
Store 2: ************
Store 3: *********			*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	double store1, store2, store3;
	
	cout << "\n*******************";
	cout << "\nSales Bar Chart   |";
	cout << "\n*******************";

	cout << "\n\n\tEnter the sales for 3 stores rounded to the nearest $100.";

	cout << "\n\n\tEnter today's sales for store 1: ";
	cin >> store1;
	cout << "\tEnter today's sales for store 2: ";
	cin >> store2;
	cout << "\tEnter today's sales for store 3: ";
	cin >> store3;

	cout << "\n\t\tDAILY SALES";
	cout << "\n\t(each * = $100)";

	cout << "\n\tStore 1: ";
	for(int i = 0; i < store1 / 100; i++){
		cout << "*";
	}
	cout << "\n\tStore 2: ";
	for(int i = 0; i < store2 / 100; i++){
		cout << "*";
	}
	cout << "\n\tStore 3: ";
	for(int i = 0; i < store3 / 100; i++){
		cout << "*";
	}

	cout << endl;

	return 0;
}