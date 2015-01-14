/*A bag of cookies holds 40 coookies. The calorie information on the bad claims that 
there are 10 "servings" in the bag and that a serving equals 300 calories.
Wire a program that asks the user to input how many cookies they actually ate and
then reports how many total calories were consumed.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	const float calPerCookie = 30;
	float munched = 0, calConsumed = 0;

	cout << "\nHow many cookies did you eat? ";
	cin >> munched;

	calConsumed = munched * calPerCookie;

	cout <<"\nLooks like you consumed " << calConsumed << " calories.\n";

	return 0;
}