/*Design and write an object-oriented program for managing inventory bins
in a warehouse. To do this you will use two classes: InvBin and 
BinManager. The InvBin class holds information about a single bin. The
BinManager class will own and manage an array of InvBin objects. Here
is a skeleton of what the InvBin and BinManager class declarations should
look like:

class InvBin
{
	private:
		string description; 					// Item name
		int qty; 								// Quantity of items
												// in this bin
	public:
		InvBin (string d = "empty", int q = 0) 	// 2-parameter constructor
		{ 	description = d; qty = q; 	} 		// with default values

		// It will also have the following public member functions.They
		// will be used by the BinManager class, not the client program.
		void setDescription(string d)
		string getDescription()
		void setQty( int q)
		int getQty( )
};

clas BinManager
{
	private:
		InvBin bin[30]; 					// Array of InvBin objects
		int numBins 						// Number of bins
											// currently in use

	public:
		BinManager() 						// Default constructor
		{	numBins = 0; 	}

		BinManager(int size, string d[], int q[]) // 3-parameter constructor
		{ 	// Receives number of bins in use and parallel arrays of item
			// names and quantities. Uses this info. to store values in the
			// elements of the bin array. Remember, these elements are
			// InvBin objects.
		}

		// The class will also have the following public member functions
		string getDescription(int index)		// Returns name of one item
		int getQuantity(int index)				// Returns qty of one item
		bool addParts(int binIndex, int q)		// These return true if the
		bool removeParts(int binIndex, int q) 	// actions was done and
												// false if it could not
												// be done- see 
												// validation information
};

Client Program 

Once you have created these two classes, write a menu-driven client
program that uses a BinManager object to manage its warehouse bins. It
should initialize it to use 9 of the bins, holding the following item 
descriptions and quantities. The bin index where the item will be
stored is also shown here.

1. regular pliers 25 		2. n. nose pliers 5 	3. screwdriver 25
4. p. head screw driver 6 	5. wrench-large 7 		6. wrench-small 18
7. drill 51 				8. cordless drill 16 	9. hand saw 12

The modular client program should have functions to display a menu,
get and validate the user's choice, and carry out the necessary
activites to handle that choice. This includes adding items to a bin,
removing items from a bin, and displaying a report of all bins. Think
about what calls the displayReport client function will need to make to
the BinManager object to create this report. When the user chooses the
"Quit" option from the meny, the program should call its displayReport
function one last time to display the final bin information. All I/O
should be done in the client class. The BinManager class only accepts
information, keeps the array of InvBin objects up to date, and returns
information to the client program.

	Input Validation in the BinManager class: The class functions 
	should not accept numbers less than 1 for the number of parts
	being added or removed from a bin. They should also not allow the
	user to remove more items from a bin than it currently holds.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

class InvBin{

private:
	string description;
	int qty;
public:
	InvBin (string d = "empty", int q = 0)
	{ 	description = d; qty = q; 	}

	void setDescription(string d);
	string getDescription();
	void setQty(int q);
	int getQty();

};

void InvBin::setDescription(string d){

	description = d;

}

string InvBin::getDescription(){

	return description;

}

void InvBin::setQty(int q){

	qty = q;

}

int InvBin::getQty( ){

	return qty;

}

class BinManager{

private:
	InvBin bin[30];
	int numBins;

public:
	BinManager() 						
	{	numBins = 0; 	}

	BinManager(int size, string d[], int q[]) 
	{ 	
		numBins = size;
		for(int i = 0; i < size; i++){
			bin[i].setQty(q[i]);
			bin[i].setDescription(d[i]);
		}

	}

	string getDescription(int index);
	int getQuantity(int index);
	bool addParts(int binIndex, int q);
	bool removeParts(int binIndex, int q); 

};

string BinManager::getDescription(int index){

	return bin[index].getDescription();

}

int BinManager::getQuantity(int index){

	return bin[index].getQty();

}	

bool BinManager::addParts(int binIndex, int q){

	bin[binIndex].setQty(bin[binIndex].getQty() + q);

	return true;

}

bool BinManager::removeParts(int binIndex, int q){

	bin[binIndex].setQty(bin[binIndex].getQty() - q);

	return true;

}

void printTitle();
void display();
char choose();
void result(BinManager, int);

int main(){

	int SIZE = 9;
	string names[] = {"regular pliers", "nose pliers", "screwdriver",
		"head s. driver", "wrench-large", "wrench-small",
		"drill        ", "cordless drill", "hand saw"};
	int qs[] = {25, 5, 25, 6, 7, 18, 51, 16, 12};
	BinManager binny(SIZE, names, qs);

	printTitle();

	result(binny, SIZE);

	return 0;
}

void printTitle(){

	cout << "\n*********************";
	cout << "\nBin Manager Class   |";
	cout << "\n*********************";

}

void display(){

	cout << "\n\n\t(A)dd Items, (R)emove Items, (V)iew Inventory, (Q)uit ";

}

char choose(){
	char choice;

	cin >> choice;

	return choice;

}

void result(BinManager binny, int SIZE){
	int q = 0, binSlot = 0;
	char choice;

	while(choice != 'q'){
		display();
		choice = choose();
		switch(choice){
			case 'a':
				cout << "\n\tHow many items do you want to add? ";
				cin >> q;
				cout << "\n\tWhich Bin slot? ";
				cin >> binSlot;
				SIZE++;
				binny.addParts(binSlot, q);
				break;
			case 'r':
				cout << "\n\tHow many items do you want removed? ";
				cin >> q;
				cout << "\n\tWhich Bin slot? ";
				cin >> binSlot;
				SIZE++;
				binny.addParts(binSlot, q);
				break;
			case 'v':
				cout << "\n\n\tDescription\t\tQuantity";
				cout << "\n\t*********************************\n";
				for(int i = 0; i < SIZE; i++){
					cout << "\n\t" << binny.getDescription(i) << "\t\t" <<
					binny.getQuantity(i);
				}
				break;
			case 'q':
				break;
			default:
				cout << "\n\n\tYeah, that's not a thing. Try again.";
				break;
		}
	}
}