#ifndef INVENTORY_CLASS_H
#define INVENTORY_CLASS_H

#include <iostream>

using namespace std;

class Inventory{

private:
	int itemNumber, quantity;
	double cost, totalCost;

public:
	Inventory();
	Inventory(int, int, double);

	void setItemNumber(int);
	void setQuantity(int);
	void setCost(double);
	void setTotalCost();
	int getItemNumber();
	int getQuantity();
	double getCost();
	double getTotalCost();

};

#endif