#include <iostream>
#include <string>
#include <vector>


using namespace std;
const int SIZE = 4;
const int SIZE2 = SIZE*SIZE + (2 * SIZE);
const int lastRow = SIZE * SIZE + SIZE;

class DisjSets{
  public:
  	DisjSets();
    explicit DisjSets( int numElements );
    int find( int x ) const;
    int find( int x );
    void unionSets( int root1, int root2 );

    // Print output
    void print();
  // private:
    vector<int> s;
};
void showVector(DisjSets ds);

DisjSets::DisjSets( int numElements ) : s{ numElements, - 1 }{
	for (int i=0; i<SIZE*SIZE; i++)
		s.push_back(-1);
}

DisjSets::DisjSets()
{
	// int lastRow = SIZE*SIZE + SIZE;
	for (int i=0; i<(SIZE*SIZE) + 2 * SIZE; i++)s.push_back(-1);
	for (int i = 0; i < SIZE; i++)
		if(i != 1)unionSets(1, i);
	for(int i = lastRow; i < SIZE*SIZE + (2 * SIZE); i++)
		if(i != lastRow)unionSets(lastRow, i);
}

// void DisjSets::unionSets(int root1, int root2){
// 	s[ root2 ] = root1;
// }



int DisjSets::find( int x ) const{
    if( s[ x ] < 0 )
        return x;
    else
        return find( s[ x ] );
}

int DisjSets::find(int x)
{
    if( s[ x ] < 0 )
        return x;
    else
        return s[ x ] = find( s[ x ] );
}

void DisjSets::unionSets( int root1, int root2 ){
	if( s[ root2 ] < s[ root1 ] )
	    s[ root1 ] = root2;
	else {
		if( s[ root1 ] == s[ root2])
		    --s[ root1 ];
		s[ root2 ] = root1;
	}
}

void DisjSets::print(){
	cout << " \t ";
	for (int i =0; i < SIZE; i++){
		cout << "_";
	}
	cout << endl;
	for (int i = 0; i<SIZE+2; i++){
		cout << "\t|";
		for(int j = 0; j<SIZE; j++){
			// if(i/SIZE == -1 || j%SIZE == -1)
			if(find(SIZE*i+j) != SIZE*i+j)		// parent == index
			{
				// if(s[SIZE*i+j] < 0)
					cout << "X";
			}
			else
			{
				if(s[SIZE*i+j] < -1)
				{
					cout << "X"; // parent < -1
					continue;
				}
				cout << " ";
			}
				// cout << SIZE*i+j;
		}
		cout<< "|" <<endl;
	}
	cout << " \t ";
	for (int i =0; i < SIZE; i++){
		cout << "_";
	}
	cout << endl;
}

void showVector(DisjSets ds)
{
	for(int i = 0; i < SIZE * SIZE + (2 * SIZE); i++)cout << ds.s[i] << " ";
		cout << endl;		
}


int main(){
	srand(time(nullptr));

	// DisjSets myUnion(SIZE);
	DisjSets myUnion;
	showVector(myUnion);
	myUnion.print();
	// cout << myUnion.find(1) << endl;
	showVector(myUnion);
	myUnion.unionSets(SIZE, SIZE + 2);
	showVector(myUnion);
	// myUnion.unionSets(1, 3);
	// showVector(myUnion);
	// myUnion.unionSets(0, 5);
	// showVector(myUnion);
	int rNum1;
	int rNum2;
	// if(myUnion.find(0) == )
	for(int i = 0; i < 10; i++)
	// while(myUnion.find(0) != myUnion.find(lastRow))
	{
	cout << endl << myUnion.find(0) << " " << myUnion.find(lastRow) << endl;;
		rNum1 = SIZE + rand() % lastRow - 1;
		rNum2 = SIZE + rand() % lastRow - 1;
		cout << rNum1 << " " << rNum2 << endl;
		if(rNum1 != rNum2)myUnion.unionSets(rNum1, rNum2);
		myUnion.print();
	}

	// cout << "rand Nums: "; 
	// for (int i = 0; i < SIZE; i++){
	// 	int randNum = rand()%SIZE;
	// 	cout << randNum << ",";
	// 	myUnion.unionSets(3, randNum);
	// }
	cout << endl;
	myUnion.print();

	return 0;
}



