#include "Inventory_Class.h"

using namespace std;

Inventory::Inventory(){
	itemNumber = quantity = cost = totalCost = 0;
}

Inventory::Inventory(int i, int q, double c){

	itemNumber = i;
	quantity = q;
	cost = c;
	setTotalCost();
}

void Inventory::setItemNumber(int i){
	itemNumber = i;
}

void Inventory::setQuantity(int q){
	quantity = q;
}

void Inventory::setCost(double c){
	cost = c;
}

void Inventory::setTotalCost(){
	totalCost = quantity * cost;
}

int Inventory::getItemNumber(){
	return itemNumber;
}

int Inventory::getQuantity(){
	return quantity;
}

double Inventory::getCost(){
	return cost;
}

double Inventory::getTotalCost(){
	setTotalCost();
	return totalCost;
}