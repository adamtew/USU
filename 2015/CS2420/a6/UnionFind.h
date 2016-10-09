//
// Created by Adam on 11/20/15.
//


#ifndef A6_UNIONFIND_H
#define A6_UNIONFIND_H

#include <vector>
#include <sstream>

using namespace std;

class UnionFind { 
public:
    UnionFind( int size);
    UnionFind();

//    int find( int x ) const;
    int find( int x );
    void unionSets( int root1, int root2 );

    void setUp( int size );
    string toString();


    vector<int> s;
    int n;
    int n2;
};


#endif //A6_UNIONFIND_H
