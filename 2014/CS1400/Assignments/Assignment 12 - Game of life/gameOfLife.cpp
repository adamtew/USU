#include <iostream>
#include "life.h"
#include <cstdlib>

const int GENERATIONS=100;

using namespace std;

//make a random array of initial living cells
void gen(bool a[ROWS][COLS]){
	for(int i=0;i<ROWS;++i){
		for(int j=0;j<COLS;++j){
			if(rand()%100<10)a[i][j]=true;
			else a[i][j]=false;
		}
	}
	a[5][5]=true;
	a[5][6]=true;
	a[5][7]=true;
	return;
}

// check to see if two arrays are equal
bool equal(const bool a[ROWS][COLS], const bool b[ROWS][COLS]){
	int i,j;
	for(i=0;i<ROWS;++i)for(j=0;j<COLS;++j)if(a[i][j]!=b[i][j])return false;
	return true;
}

//copy the b array into the a array
void copy(bool a[ROWS][COLS], const bool b[ROWS][COLS]){
	for(int i=0;i<ROWS;++i){
		for(int j=0;j<COLS;++j){
			a[i][j]=b[i][j];
		}
	}
	return;
}

//print out the array
void print(const bool a[ROWS][COLS]){
	for(int i=0;i<ROWS;++i){
		for(int j=0;j<COLS;++j){
			if(a[i][j])cout << 'X';
			else       cout << ' ';
		}
		cout << endl;
	}
	return;
}


int main(){
	bool current[ROWS][COLS];
	bool next[ROWS][COLS];
	int i=0;

	//initialze the cell array and print it out
	gen(current);
	print(current);

	while(i<GENERATIONS){
		//get a carriage return before the next generation
		cin.get();

		//give the current generation to life()
		//it puts the next generation into next
		life(current,next);

		//copy the next generation into the current
		copy(current,next);

		//print it out
		print(current);
		i++;
	}

	return 0;
}
