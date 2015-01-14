#ifndef WIDGET_FACTORY_H
#define WIDGET_FACTORY_H

#include <iostream>

using namespace std;

class WidgetFactory{

private:
	int widgets;
	double productionTime;

public:
	WidgetFactory();

	void setWidgets(int);
	int daysToProduce();

};

#endif