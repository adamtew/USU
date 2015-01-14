/*A soft drink company recently surveyed 12,467 of its customers and found that 
approximately 14 percent of those surveyed purchase one of more energy drinks per 
week. Of those customers who purchase energy drinks, approximately 64 
percent of them prefer citrus flaored energy drinks. Write a program 
that displays the following:
	The approximate number of customers in the survey who purchase one or 
	more energy drinks per week.
	The approximate number of customers in the survey who prefer citrus 
	flavored energy drinks.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	float surveyed = 12467, purchPerWeek = surveyed * .14, 
	prefCitrus = purchPerWeek * .64;

	cout << "\nCustomers surveyed who purchase per week: " 
		<< purchPerWeek
		<< "\nCustomers surveyed that prefer citrus: "
		<< prefCitrus << endl;


	return 0;
}