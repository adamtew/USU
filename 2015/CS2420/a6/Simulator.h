//
// Created by Adam on 11/23/15.
//

#ifndef A6_SIMULATOR_H
#define A6_SIMULATOR_H

#include <vector>
#include "UnionFind.h"

using namespace std;

class Simulator {
public:
    int n;
    int n2;
    UnionFind uf;
    vector<vector<int> > s;

    Simulator( int size );

    string toString();
    void put();
    bool perc();

};




#endif //A6_SIMULATOR_H
