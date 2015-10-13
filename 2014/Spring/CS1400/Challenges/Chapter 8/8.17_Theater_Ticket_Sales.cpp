/*Create a TicketManager class and a program that uses it to sell tickets
for a single performance theater production. This project is intended to
be designed and written by a team of 2-4 students. Here are some suggestions:

	• One student might design and write a client program that uses the
	  class, while other team members design and write the TicketManager
	  class and all of its functions.
	• Each student should be given about the same workload.
	• The class design and the names, parameters, and return types of
	  each function should be decided in advance.
	• The project can be implemented either as a multi-file program,
	  or all of the functions can be cut and pasted into a single file.

Here are the specifications:

	• The theater's auditorium has 15 rows, with 30 seats in each row.
	  To represent the seats, the TicketManager class should have a 
	  two-dimensional array of SeatStructures. Each of these structures
	  should have data members to keep track of the seat's price and 
	  whether or not it is available or already sold.
	• The seat prices should be read in from the SeatPrices.dat file. It 
	  contains 15 values representing the price for each row. All seats 
	  in a given row are the same price, but different rows have 
	  different prices. The seat availability information should be 
	  read in from the SeatAvailability.dat file. It conatins 450
	  characters (15 rows with 30 characters each), indicating which
	  seats have been sold('*') and which are available('#'). 
	  Initially all seats are available. However, once the program runs
	  and the file is updated, some of the seats will have been sold. The
	  Obvious function to read in the data from these files and set up
	  the array is the constructor that runs when the TicketManager
	  object is first created.
	• The client proram should be a menu-driven program that provides the
	  user with a menu of box office options, accepts and validates
	  user inputs, and calls appropriate class functions to carry out
	  desired tasks. The menu should have options to display the 
	  seating chart, request tickets, print a sales report, and exit the
	  program.
	• When the user selects the display seats menu option, a TicketManager
	  function should be called that creates and return a string  holding
	  a chart, similar to the one shown here. It should indicate which
	  seats are already sold(*) and which are still available for 
	  purchase (#). The client proram should then display the string

	  					Seats
				123456789012345678901234567890
		Row 1 	***###***###*########*****####	
		Row 2 	####*************####*******##
		Row 3 	**###**********########****###
		Row 4 	**######**************##******
		Row 5 	********#####*********########
		Row 6 	##############************####
		Row 7 	#######*************##########
		Row 8 	************##****############
		Row 9 	#########*****############****
		Row 10 	#####*************############
		Row 11 	#**********#################**
		Row 12 	#############********########*
		Row 13 	###***********########**######
		Row 14 	##############################
		Row 15 	##############################

	• When the user selects the request tickets menu option, the proram
	  should prompt for the number of seats the patron wants, the desired
	  starting seat number. A TicketManager ticket request function
	  should then be called and passed this information so that it can
	  handle the ticket request. If any of the requested seats do not
	  exist, or are not available, an appropriate message should be 
	  returned to be displayed by the client program. If the seats
	  exist and are available, a string should be created and returned
	  that lists the number of requested seats, the price per seat in the
	  requested row, and the total price for the seats. Then the user
	  program should ask if the patron wishes to purchase the seats.
	• If the patron indicates they do want to buy the requestes seats,
	  a TicketManager purchase tickets module should be called to handle
	  the actual sale. This module must be able to accept money, ensure,
	  that it is sufficient to continue with the sale, and if it is, mark
	  the seat(s) as sold, and create and return a string that includes
	  a ticket for each seat sold (with the correct row, seat number,
	  and price on it).
	• When the user selects the sales report meny option, a TicketManager
	  report module should be called. This module must create and return a
	  string holding a report that tells how many seats have been sold,
	  how many are still available, and how much money has been collected
	  so far for the sold seats. Think about how your team will either
	  calculate or collect and store this information so that it will be
	  available when it is needed for the report.
	• When the day of tickets sales is over and the quit menu choice is 
	  selected, the program needs to be able to write the updated seat
	  availability data back out to the file. The obvious palce to 
	  do this is in the TicketManager destructor.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <fstream>

using namespace std;

class TicketManager{
public:
	TicketManager();
	char getAvailable(int, int);
	double getPrice(int, int);

private:
	void readData();
	struct SeatStructure{

		double price;
		char available;

	};
	SeatStructure seats[15][30];
};

TicketManager::TicketManager(){

	readData();
	
}

void TicketManager::readData(){

	ifstream getPrices("SeatPrices.dat"),
			getAvailable("SeatAvailability.dat");

	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 30; j++){
			getPrices >> seats[i][j].price;
			getAvailable >> seats[i][j].available;
		}
	}
}

char TicketManager::getAvailable(int rIndex, int cIndex){
	return seats[rIndex][cIndex].available;
}

double TicketManager::getPrice(int rIndex, int cIndex){
	return seats[rIndex][cIndex].price;
}
void printTitle();
void menu(TicketManager);
void showSeats(TicketManager);
void requestTickets(TicketManager);
void printReport(TicketManager);

int main(){
	TicketManager theater;

	printTitle();
	menu(theater);

	return 0;
}

void printTitle(){

	cout << "\n************************";
	cout << "\nTheater Ticket Sales   |";
	cout << "\n************************";

}

void menu(TicketManager theater){
	bool inLine = true;
	char choice;

	while(inLine){
		cout << "\n\n\t(S)how Seats, (R)equest ticket, (P)rint Report, ";
		cout << "or (Q)uit.";
		cout << "\n\n\tMake a selection: ";
		cin >> choice;
		switch(choice){
			case 's':	showSeats(theater);
				break;
			case 'r':	requestTickets(theater);
				break;
			case 'p':	printReport(theater);
				break;
			case 'q':	inLine = false;
				break;
			default:
				break;
		}
	}
}

void showSeats(TicketManager theater){

	cout << "\n\n\tAvailable(#) and sold(*)";
	cout << "\n\t--------------------------\n";
	for(int i = 0; i < 15; i++){
		cout << "\n\t";
		for(int j = 0; j < 30; j++){
			cout << theater.getAvailable(i, j);
		}
	}

}

void requestTickets(TicketManager theater){
	int row = 0, col = 0;
	bool available = false;

	while(!available){
		cout << "\n\nEnter the row and column of your seat.";
		cout << "\nRow: ";
		cin >> row;
		cout << "\nCol: ";
		cin >> col;

		if(theater.getAvailable(row - 1, col - 1) == '*'){
			cout << "\nI'm sorry, that seat is taken.";
			cout << "\nPlease choose another: ";
			available = false;
		}else{
			cout << "\nLooks like that's free.";
			cout << "\nIt'll cost you " <<
				theater.getPrice(row - 1, col - 1) << " dollars.";
			available = true;
		}
	}
}

void printReport(TicketManager theater){
	int sold = 0, notSold = 0;
	double profit = 0;

	for(int i = 0; i < 15; i++){
		cout << "\n\t";
		for(int j = 0; j < 30; j++){
			cout << theater.getAvailable(i, j);
			if(theater.getAvailable(i, j) == '*'){
				sold += 1;
				profit += theater.getPrice(i, j);
			}
			if(theater.getAvailable(i, j) == '#')notSold += 1;
		}
	}

	cout << "\n\nSold " << sold << " tickets with a profit of " << profit;
	cout << "\nWith " << notSold << " tickets remaining";

}