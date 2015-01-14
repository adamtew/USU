/*Design a class for a widget manufacturing plant. Assuming that 10 widgets may be 
produced each hour, the class object will calculate how many days it will take to
produce any number of widgets. (The plany operates two 9-hour shifts per day.) Write
a program that asks the user for the number of widgets that have been ordered and then
display the number of days it will take to produce them. Think about what values your
program should accept for the number of widgets ordered.*/
// Adam Tew ---- CS1400

#include "Widget_Factory.h"

using namespace std;

void printTitle();

int main(){
	int ordered;

	WidgetFactory first;

	printTitle();

	cout << "\n\n\tHow many widgets have been ordered? ";
	cin >> ordered;

	first.setWidgets(ordered);
	cout << "\n\n\tThat will take " << first.daysToProduce() << " day(s) to produce.\n";

	return 0;
}

void printTitle(){

	cout << "\n******************";
	cout << "\nWidget Factory   |";
	cout << "\n******************";

}