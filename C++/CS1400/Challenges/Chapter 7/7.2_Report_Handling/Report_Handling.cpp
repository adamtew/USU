#include "Report_Handling.h"

using namespace std;

Heading::Heading(){
	companyName = "ABC Industries";
	reportName = "Report";
}
Heading::Heading(string cn, string rn){

	companyName = cn;
	reportName = rn;

}

void Heading::oneLine(){

	cout << companyName << " " << reportName;

}

void Heading::boxed(){
	int cLength = companyName.length();
	int rLength = reportName.length();

	cout << "\n*****************************\n";
	for(int i = 0; i < cLength; i++){
		if(i % 2 == 0 && cLength < rLength)cout << "  ";
		if(i % 3 == 0 && cLength > rLength)cout << " ";
	}
	cout << companyName << "\n";
	for(int i = 0; i < rLength; i++){
		if(i % 2 == 0 && cLength > rLength)cout << "  ";
		if(i % 3 == 0 && cLength < rLength)cout << " ";
	}
	cout << reportName;		
	cout << "\n*****************************\n";


}