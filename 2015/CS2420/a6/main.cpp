#include <iostream>
#include "UnionFind.h"
#include "Simulator.h"
#include <fstream>

using namespace std;


int main() {
    srand(time(nullptr));

//    PART I Testing
    cout << "\n\n\tPart I\n";
    UnionFind uf(3);
    cout << "\nUnion Find initialized: " << uf.toString();
    uf.unionSets(3, 4);
    cout << "Union 3 and 4: " << uf.toString();

    uf.unionSets(4 , 5);
    uf.unionSets(4 , 6);
    uf.unionSets(4 , 7);
    cout << "Union 3 with 5, 6, and 7 with path compression: " << uf.toString() << endl;
    cout << "Find a parent with no children\nFind(1): " << uf.find(1) << endl;
    cout << "Find a parent with children\nFind(3): " << uf.find(3) << endl;
    cout << "Find a child that points to a parent\nFind(5): " << uf.find(5) << endl;


//    PART II Implementation
    cout << "\n\nPart II\n";
    ofstream fout;
     fout.open("/Users/at/gitSchool/usu/2015/CS2420/a6/readme.txt");
//   fout.open("readme.txt");
    int n = 20;
    Simulator runner(n);

    int iter = 1;
    while(!runner.perc())
    {
        runner.put();
        if(iter % 50 == 0) {
            fout << iter << endl;
            fout << runner.toString();
        }
        iter++;
    }
    fout << "\nIt took " << iter << " iterations to percolate\n";
    fout << runner.toString();
    cout << "\nOutput to readme.txt file\n";

    return 0;
}