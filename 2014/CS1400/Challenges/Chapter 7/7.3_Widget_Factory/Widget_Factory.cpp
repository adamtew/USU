#include "Widget_Factory.h"

using namespace std;

WidgetFactory::WidgetFactory(){
	widgets = 0;
}

void WidgetFactory::setWidgets(int n){
	widgets = n;
}

int WidgetFactory::daysToProduce(){
	productionTime = (widgets / 160) + 1;
	return productionTime;
}