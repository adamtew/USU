#include <iostream>
#include "TUStack.h"
#include <string>

using namespace std;

int main()
{
	cout << "Stack using integers\n\n";
	TUStack<int> a(5);
	cout << "The stack has a capacity of " << a.size() << endl;

	a.push(5);
	cout << "The stack contains " << a[0] << " at position 0\n\n";

	cout << "The stack is currently at position " << a.position() << endl;

	int x = a.pop();
	cout << "Retrieved " << x << " from the top of the stack\n";

	cout << "The stack is currently at position " << a.position() << endl;

	a.push(6);
	cout << "The stack contains " << a[0] << " at position 0\n\n";

	cout << "The stack is currently at position " << a.position() << endl;

	cout << "The stack contains " << a[a.position()] << " at the top\n\n";

	//try
	//{
	//	a.push(5);
	//	cout << "The stack contains " << a[0] << " at the top of the stack\n";
	//}
	//catch (string e)
	//{
	//	cout << "Error thrown " << e;
	//}

	cout << "Stack using strings\n\n";
	TUStack<string> b(10);

	cout << "The stack has a capacity of " << b.size() << endl;

	b.push("element");
	cout << "The stack contains '" << b[0] << "' at position 0\n\n";

	cout << "The stack is currently at position " << b.position() << endl;

	string y = b.pop();
	cout << "Retrieved '" << y << "' from the top of the stack\n";

	cout << "The stack is currently at position " << b.position() << endl;

	b.push("another element");
	cout << "The stack contains '" << b[0] << "' at position 0\n\n";

	cout << "The stack is currently at position " << b.position() << endl;

	cout << "The stack contains '" << b[b.position()] << "' at the top\n\n";

	
	cout << "Exception Handling\n\n";
	try
	{
		cout << "Attempting to initialize stack to a negative number\n";
		TUStack<int> c(-1);
	}
	catch (string e)
	{
		cout << e;
	}

	try
	{
		cout << "Attempting to push items to a full stack\n";
		a.push(5);
		a.push(5);
		a.push(5);
		a.push(5);
		a.push(5);
	}
	catch (string e)
	{
		cout << e;
	}

	try
	{
		cout << "Attempting to access illegal index\n";
		a[-1];
	}
	catch (string e)
	{
		cout << e;
	}

	try
	{
		cout << "Attempting to pop empty stack\n";
		a.pop();
		a.pop();
		a.pop();
		a.pop();
		a.pop();
		a.pop();
		a.pop();
	}
	catch (string e)
	{
		cout << e;
	}


	return 0;
}