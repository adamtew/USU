/*The Yukon Widget Company manufactures widgets that weigh 9.2 pounds each. Write a 
program that calculates how many widgets are stacked on a pallet, based on the total
weight of the pallet. The program should ask the user how much the pallet weighs by
itself and with the widgets stacked on it. It should then calculate and display
the number of widgets stacked on the pallet.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	const float widgetWeight = 9.2;
	float withWidgets = 0, withoutWidgets = 0, difference, widgets = 0;

	cout << "\nHow many pounds does the pallet weigh by itself? ";
	cin >> withoutWidgets;
	cout << "\nHow many pounds does the pallet weigh with the widgets? ";
	cin >> withWidgets;

	difference = withWidgets - withoutWidgets;
	widgets = difference / widgetWeight;

	cout << "\nLooks like there are " << (int)widgets << " on the pallet.\n";


	return 0;
}