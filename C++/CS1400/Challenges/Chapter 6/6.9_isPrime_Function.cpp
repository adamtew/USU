/*A prime number is an integer greater than 1 that is evenly divisible by only 1 and
itself. For example, the number 5 is prime because it can only be evenly divided by
1 and 5. The number 6, however, is not prime because it can be divided by 1, 2, 3,
and 6.

Write a Boolean function named isPrime, which takes an integer as an argument and
returns true if the argument is a prime number, and false otherwise. Demonstrate the
function in a complete program.

-------------------------------------------------------------------------------------
| TIP: Recall that the % operator divides one number by another and returns the 	|
| remainder of the division. In an expression such as num1 % num2, the % operator	|
| will return 0 if num1 is evenly divisible by num2.								|
------------------------------------------------------------------------------------*/

// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

void printTitle();
bool isPrime(int);

int main(){
	int num;
	bool prime;

	printTitle();

	cout << "\n\n\tEnter a number and I'll tell you if it's prime or not.";
	cout << "\n\tEnter Number: ";
	cin >> num;

	prime = isPrime(num);

	if(prime){
		cout << "\n\tPrime.";
	}else{
		cout << "\n\tNot prime.";
	}

	return 0;
}

void printTitle(){

	cout << "\n********************";
	cout << "\nisPrime Function   |";
	cout << "\n********************";

}

bool isPrime(int number){

	for(int i = 2; i < number; i++){
		if(number % i == 0)return false;
	}

	return true;
}