#include "Node.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "OrderedQueue.h"

#include <iostream>

using namespace std;

int main()
{
	int num1 = 5;
	int num2 = 10;
	int num3 = 15;
	int num4 = 20;

	cout << "Created a new Stack:\n";
	Stack<int> stack(5, 5);
	stack.push(&num1);
	cout << "This is the new top: " << *stack.top() << endl;
	stack.push(&num2);
	cout << "This is the new top: " << *stack.top() << endl;
	int* x = stack.pop();
	cout << *x << " was popped the new top is: " << *stack.top() << "\n\n";

	cout << "Created a new Queue:\n";
	Queue<int> queue(5, 5);
	cout << "Push:\n";
	queue.push(&num1);
	cout << "Pushed: " << num1 << " Front: " << *queue.top() << endl;
	queue.push(&num2);
	cout << "Pushed: " << num2 << " Front: " << *queue.top() << endl;
	queue.push(&num3);
	cout << "Pushed: " << num3 << " Front: " << *queue.top() << "\n\n";

	cout << "Pop:\n";
	int* y = queue.pop();
	cout << "Popped: " << *y << " Front: " << *queue.top() << endl;
	y = queue.pop();
	cout << "Popped: " << *y << " Front: " << *queue.top() << endl;
	y = queue.pop();
	cout << "Popped: " << *y << " Front: " << *queue.top() << "\n\n";
	

	cout << "Created a new OrderedQueue:\n";
	OrderedQueue<int> oQueue(5, 15);
	cout << "Push:\n";
	cout << "Pushed: " << 15 << " Front: " << *oQueue.top() << endl;
	oQueue.push(&num3);
	cout << "Pushed: " << num3 << " Front: " << *oQueue.top() << endl;
	oQueue.push(&num1);
	cout << "Pushed: " << num1 << " Front: " << *oQueue.top() << "\n";




	return 0;
}