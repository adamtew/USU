#include <iostream>

using namespace std;

int Belomorkanal = 10, Lyubimiye = 10, BlossomAndDecay = 10, BlackDeath = 10, counter = 0;

void menu(){
	

	cout << "\t s - report the machine status\n";
	cout << "\t d - drop in a quarter\n";
	cout << "\t 1 - pull the 1th knob\n";
	cout << "\t 2 - Pull the 2th knob\n";
	cout << "\t 3 - Pull the 3th knob\n";
	cout << "\t 4 - pull the 4th knob\n";
	cout << "\t r - restock the machine\n";
	cout << "\t q - quit\n";
	cout << ">";
	
	return;
}

void response(){
	
	char response;
	while(response != 'q'){
		menu();
		cin >> response;
		switch(response){
			case 's':
				cout << Belomorkanal << " - Belomorkanal's\n";
				cout << Lyubimiye << " - Lyubimiye's\n";
				cout << BlossomAndDecay << " - Blossom and Decay's\n";
				cout << BlackDeath << " - Black Death's\n\n";
				break;
			case 'd':
				cout << "Ching.\t";
				counter++;
				cout << counter << " coin(s) remaining in the machine.\n\n";
				break;
			case '1':
				cout << "You pulled the 1th knob.\n";
				if(counter >= 1 && Belomorkanal > 0){
					cout << "You got a Belomorkanal!\t";
					Belomorkanal--;
					counter -= 1;
					cout << counter << " coin(s) remaining in the machine.\n\n";
				}else{
					cout << "No Belomorkanal for you!\n";
				}
				break;
			case '2':
				cout << "You pulled the 2th knob.\n";
				if(counter >= 2 && Lyubimiye > 0){
					cout << "You got a Lyubimiye!\t";
					Lyubimiye--;
					counter -= 2;
					cout << counter << " coin(s) remaining in the machine.\n\n";
				}else{
					cout << "No Lyubimiye for you!\n";
				}
				break;
			case '3':
				cout << "You pulled the 3th knob.\n";
				if(counter >= 3 && BlossomAndDecay > 0){
					cout << "You got a Blossom and Decay!\t";
					BlossomAndDecay--;
					counter -= 3;
					cout << counter << " coin(s) remaining in the machine.\n\n";
				}else{
					cout << "No Blossom and Decay for you!\n";
				}
				break;
			case '4':
				cout << "You pulled the 4th knob.\n";
				if(counter >= 4 && BlackDeath > 0){
					cout << "You got a Black Death!\t";
					BlackDeath--;
					counter -= 4;
					cout << counter << " coin(s) remaining in the machine.\n\n";
				}else{
					cout << "No Black Death for you!\n";
				}
				break;
			case 'r':
				cout << "You pulled the rth knob.\n";
				Belomorkanal = 10, Lyubimiye = 10, BlossomAndDecay = 10, BlackDeath = 10;
				cout << Belomorkanal << " - Belomorkanal's\n";
				cout << Lyubimiye << " - Lyubimiye's\n";
				cout << BlossomAndDecay << " - Blossom and Decay's\n";
				cout << BlackDeath << " - Black Death's\n\n";
				break;
			case 'q':
				cout << "So long!\n";
				break;
			default: 
				cout << "I do not understand.\n";
				break;
		}
	}
}

int main(){

	response();
	
}