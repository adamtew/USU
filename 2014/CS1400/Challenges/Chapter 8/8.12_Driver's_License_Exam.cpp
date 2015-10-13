/*The State Department of Motor Vehicles (DMV) has asked you to write a
program that grades the written portion of the driver's license exam,
which has 20 multiple choice questions. Here are the correct answers:

		---------------------------------------------
		|	1. B	5. C 	 9. C 	13. D 	17. C 	|
		|	2. D 	6. A 	10. D 	14. A 	18. B 	|
		| 	3. A 	7. B 	11. B 	15. D 	19. D 	|
		| 	4. A 	8. A 	12. C 	16. C 	20. A 	|
		---------------------------------------------

To do this you should create a TestGrader class. The class will have an 
answers array of 20 characters, which holds the corret test answers. It
will have two public member functions that enable user programs to
interact with the class: setKey and grade. The setKey function receives
a 20-character string holding the correct answers and copies this
information into its answers array. The grade function receives a
20-character array holding the test taker's answers and compares each of
their answers to the correct one. An applicant must correctly answer 15
or more of the 20 questions to pass the exam. After "grading" the exam,
the grade function should create and return to the user a string that
includes the following information:

	• a message indicating whether the applicant passed or failed the
	  exam
	• the number of right answers and the number of wrong answers
	• a list of the question numbers for all incorrectly answered 
	  questions
	
The client program that creates and uses a TestGrader object should first
make a single call to setKey, passing it a string containing the 20 
correct answers. Once this is done it should allow a test taker's 20
answers to be entered, making sure only answers of A-D are accepted, and
store them in a 20-character array. Then it should call the grade funciton
to grade the exam and should display the string the function returns.
The program should loop to allow additional tests to be entered and 
graded until the user indicates a desire to quit.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

class TestGrader{
public:
	TestGrader();
	TestGrader(string);

	void setKey(string);
	bool grade(string);

private:
	string answers, attempts;


};

TestGrader::TestGrader(){
	answers =  "BDAACABACDBCDADCCBDA";
}

TestGrader::TestGrader(string str){
	answers = str;
}

void TestGrader::setKey(string str){
	answers = str;
}

bool TestGrader::grade(string str){
	int correct = 0;

	for(int i = 0; i < answers.size(); i++){
		if(answers[i] == attempts[i]){
			correct += 1;
			cout << "\nin" << " " << correct << " Attempt " << 
			attempts[i] << " answer " << answers[i] << " " << i;
		}
	}

	if(correct > 14){
		return true;
	}else{
		return false;
	}
}



void printTitle();
string attemptTest(string);
void checkWin(bool);

int main(){
	TestGrader check;
	string attempt;
	bool pass;
	
	printTitle();
	check.setKey("BDAACABACDBCDADCCBDA");
	attempt = attemptTest(attempt);

	pass = check.grade(attempt);
	checkWin(pass);

	return 0;
}

void printTitle(){

	cout << "\n*************************";
	cout << "\nDriver's License Exam   |";
	cout << "\n*************************";

}

string attemptTest(string str){

	cout << "\nHere you will attempt your test.\n";
	for(int i = 0; i < 20; i++){
		if(i < 10)cout << " " << i << ". ";
		if(i >= 10)cout << i << ". ";
		cin >> str[i];
		while(str[i] < 65 || str[i] > 68){
			cout << "Invalid entry. Enter a letter a - d";
			cin >> str[i];
		}
	}
	return str;
}

void checkWin(bool win){
	if(win){
		cout << "\nPassed";
	}else{
		cout << "\nFailed";
	}
}