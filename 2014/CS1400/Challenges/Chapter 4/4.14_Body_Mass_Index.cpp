/*Write a program that calculates and displays a person's body mass index (BMI). The
BMI is often used to determine whether a person with a sedentary lifestyle is
overweight or underweight for his or her height. A person's BMI is calculated with
the following formula:

	BMI = weight x 703/height^2

where weight is measured in pounds and height is measured in inches. The program should
display a message indicating whether a person has optimal weight, is underweight, or 
is overweight. A sedentary person's weight is considered to be optimal if his or her
BMI is between 18.5 and 25. If the BMI is less than 18.5 the person is considered to
be underweight. If the BMI value is greater than 25, the person is considered to be
overweight.

	Input Validation: Determine what inputs the program needs the user to enter and
	what legal values the program should accept for these inputs.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	float BMI, weight = 0, height, feet = 0, inches = 0;
	string BMIness;

	cout << "\n\tWe're going to calculate your BMI";
	cout << "\n\tWhat's your height? ";
	cout << "\n\tFeet: ";
	cin >> feet;
	if(feet < 0 || feet > 7)return 0;
	cout << "\tInches: ";
	cin >> inches;
	if(inches < 0 || inches > 12)return 0;

	height = (feet * 12) + inches;

	cout << "\n\tWhat's your weight? ";
	cin >> weight;
	if(weight < 0)return 0;

	BMI = weight * (703 / pow(height, 2));
	if(BMI <= 25 && BMI >= 18.5)BMIness = "optimal";
	if(BMI < 18.5 && BMI >= 0)BMIness = "underweight";
	if(BMI > 25)BMIness = "overweight";

	cout << fixed << setprecision(1);
	cout << "\n\tYour BMI is " << BMI << endl;
	cout << "\n\tThie is considered " << BMIness << endl;
	return 0;
}