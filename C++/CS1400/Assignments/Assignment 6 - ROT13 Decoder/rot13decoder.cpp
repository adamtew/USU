#include <iostream>
#include <fstream>

using namespace std;

int main () {
	ifstream fin;
	ofstream fout;
	char c;
	int ci;

	fin.open("secretMessage.txt");
	fout.open("decodedMessage.txt");

	while(!fin.eof()){
		c = fin.get();
			ci = c;
			if(c >= 97 && c < 110 || c >= 65 && c < 78){
			ci = ci + 13;
			c = ci;
			}else if(c < 123 && c >= 110 || c < 91 && c >= 78){
				ci = ci - 13;
				c = ci;
			}
		if(!fin.eof())cout << c;

	}

	return 0;
}