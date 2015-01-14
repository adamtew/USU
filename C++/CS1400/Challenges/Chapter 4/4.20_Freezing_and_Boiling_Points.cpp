/*The following table lists the freezing and boiling points of several substances.
Write a program that asks the user to enter a temperature, and then shows all the
substances that will freeze at that temperature and all that will boil at that
temperature. For example, if the user enters -20 the program should report that
water will freeze and oxygen will boil at that temperature.

-------------------------------------------------------------------------------------
	Substance 					Freezing Point(F) 				Boiling Point(F)
-------------------------------------------------------------------------------------
	Ethyl alcohol					-173							172
	Mercury							-38								676
	Oxygen 							-362						   -306
	Water 							 32 							212
-----------------------------------------------------------------------------------*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	const int eFreeze = -173, eBoil = 172, mFreeze = -38, mBoil = 676,
			oFreeze = -362, oBoil = -306, wFreeze = 32, wBoil = 212;
	int temp = 0;

	cout << "\n\tEnter a temperature: ";
	cin >> temp;

	cout << right;
	cout << "\n\tAt this temperature:\n";
	if(temp >= eBoil)cout << "\n\tEthyl alcohol" << setw(12) << "boils";
	if(temp >= mBoil)cout << "\n\tMercury" << setw(18) << "boils";
	if(temp >= oBoil)cout << "\n\tOxygen" << setw(19) << "boils";
	if(temp >= wBoil)cout << "\n\tWater" << setw(20) << "boils";
	if(temp <= eFreeze)cout << "\n\tEthyl alcohol" << setw(12) << "freezes";
	if(temp <= mFreeze)cout << "\n\tMercury" << setw(18) << "freezes";
	if(temp <= oFreeze)cout << "\n\tOxygen" << setw(19) << "freezes";
	if(temp <= wFreeze)cout << "\n\tWater" << setw(20) << "freezes";
	cout << endl;



	return 0;
}