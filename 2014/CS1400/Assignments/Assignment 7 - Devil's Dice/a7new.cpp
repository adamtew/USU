#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void printTop(){
	cout << "      ----------------------\n";
	cout << "      You              Devil\n";
	cout << "      ---              -----\n\n";
	return;
}

void printYourScore(int yourScore, int i){
	if(yourScore <= 9 && yourScore <= i && yourScore >= i - 4){
		cout << "   "<< yourScore << " >";
	//}else if(yourScore >= 100 && yourScore <= i && yourScore >= i - 4){
	//	cout << "  "<< yourScore << " >";
	}else if(yourScore > 9 && yourScore <= i && yourScore >= i - 4){
		cout << "  "<< yourScore << " >";
	}else{
		cout << "      ";
	}

	return;
}

void printYourScoreTile(int i){
	cout << "-- " << i << "\t";

	return;
}

void printDevilScore(int devilScore, int i){
	if(devilScore <= i && devilScore >= i - 4){
		cout << "< "<< devilScore;
	}else{
		cout << "      ";
	}

	return;
}

void printDevilScoreTile(int i){
	if(i == 100)cout << "    " << i << " --";
	if(i < 100 && i >= 10)cout << "     " << i << " --";
	if(i < 10)cout << "      " << i << " --";


	return;
}

void printPicture(int yourScore, int devilScore, int number, int i){
	if(i <= 90 && i > 70){
		if(i == 90) cout << " die ";
		if(i == 85) cout << " --- ";
		if(i == 80) cout << "| " << number << " |";
		if(i == 75) cout << " --- ";
	}else if(yourScore >= 100 && i <= 65 && i >= 55){
		if(i == 65)cout << " You ";
		if(i == 60)cout << " win!";
		if(i == 55)cout << "<<<<<";
	}else if(devilScore >= 100 && i <= 65 && i >= 55){
		if(i == 65)cout << "Devil";
		if(i == 60)cout << " won!";
		if(i == 55)cout << ">>>>>";
	}else{
		cout << "     ";
	}

	return;
}

void winner(int yourScore, int devilScore){
	ifstream fin("scores.txt");
	ofstream fout;
	int yourInt = 0, devilInt = 0;

	if(fin){
			fin >> yourInt;
			fin >> devilInt;
	}else{
		fout.open("scores.txt");
	}

	if(yourScore >= 100)yourInt++;
	if(devilScore >= 100)devilInt++;
	cout << "\n\twin/loss record: " << yourInt << "/" << devilInt << endl;

	fout.open("scores.txt");
	fout << yourInt;
	fout << "\r\n";
	fout << devilInt;
	fout.close();

	if(yourScore >= 100){	
	}else if(devilScore >=100){
	fout << "devilScore: " << devilScore;
	}

	return;
}

char printStuff(int yourScore, int devilScore, int number){
	char response;

	printTop();
	for(int i = 100; i >= 0; i -= 5){
		printYourScore(yourScore, i);
		printYourScoreTile(i);
		printPicture(yourScore, devilScore, number, i);
		printDevilScoreTile(i);
		printDevilScore(devilScore, i);
		cout << endl;
	}

	if(devilScore >= 100 || yourScore >= 100){
		winner(yourScore, devilScore);
	}

	cout << "\nPass[p], roll[r], or forfeit[f]: ";

	if(devilScore >= 100 || yourScore >= 100){
		cout << "\n\n Would you like to play again? (y/n): ";
		cin >> response;
	}

	if(response == 'n' && (devilScore >= 100 || yourScore >= 100)){
		response = 'f';
	}else if(response == 'y' && (devilScore >= 100 || yourScore >= 100)){
		return response;
	}else{
		cin >> response;
	}

	return response;
}

int rollDice(){
	int roll;

	roll =  (rand() % 6) + 1;

	return roll;
}

int main(){
	char response;
	int yourScore = 99, devilScore = 0, number = 0;
	bool devilTurn, yourTurn, roll, forfeit;
	
	while(response != 'f'){

		response = printStuff(yourScore, devilScore, number);
		switch(response){
			case 'p':
					number = rollDice();
					if(number != 1){
						number = rollDice();
						devilScore += number;
					}else{
						devilScore = 0;
					}
				break;
			case 'r':
					if(yourScore > 99 || devilScore > 99){
						yourScore = 0;
						devilScore = 0;
					}
					 number = rollDice();
					 if(number != 1)
					 	yourScore += number;
					 else
					 	yourScore = 0;
					break;
			case 'y':
					if(devilScore >= 100 || yourScore >= 100){
						yourScore = 0;
						devilScore = 0;
					}
					break;
			default:
				break;
		}
	}
	
	return 0;
}