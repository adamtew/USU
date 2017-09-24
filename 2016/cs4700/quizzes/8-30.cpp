#include <iostream>

using namespace std;

void swap(int *num1, int *num2);

int main() {

  cout << "Hello World";
  int a = 5;
  int b = 6;

  cout << "\n\n a and be are:\n";
  cout << "a: " << a << endl;
  cout << "b: " << b;

  swap(a, b);

  cout << "\n\n a and be are now:\n";
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;

  return 0;
}

void swap(int *num1, int *num2) 
{
  int *temp = num1;
  num2 = num1;
  num1 = temp;

}