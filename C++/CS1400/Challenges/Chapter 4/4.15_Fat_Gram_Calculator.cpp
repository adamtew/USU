/*Write a program that asks for the number of calories and fat grams in a food.
The program should display the percentage of calories that come from fat. If the
calories from fat are less than 30 percent of the total calories ofthe food, it
should display a message indicatin the food is low in fat.

One gram of fat has 9 calories, so

	calories from fat = fat grams * 9

The percentage of calories from fat can be calculated as

	calories from fat + total calories

	Input Validation: The program should make sure that the number of calories is
	greater than 0, the number of fat grams is 0 or more, and the number of calories
	from fat is not greater than the total number of calories.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	float gramsOfFat = 0, calories = 0, fatCal, percentCal;

	cout << "\n\tCalories: ";
	cin >> calories;
	if(calories <= 0)return 0;

	cout << "\n\tGrams of fat: ";
	cin >> gramsOfFat;

	fatCal = gramsOfFat * 9;

	if(gramsOfFat < 0 || fatCal > calories){
		cout << "\n\tThat would exceed the number of calories\n";
		return 0;
	}

	percentCal = (fatCal/calories) * 100;

	cout << fixed << setprecision(0);
	cout << "\n\tCalories from Fat: " << fatCal;
	cout << "\n\tTotal Calories: " << calories << setprecision(1);
	cout << "\n\tPercent Fat: " << percentCal;
	cout << "\n\t";
	
	


	return 0;
}