#include <iostream>
#include "Graph.h"
#include <fstream>
using namespace std;

void play();

Graph g;

int main() {
//    ifstream fin("/Users/at/gitSchool/usu/2015/CS2420/a7/digraph1.txt");
//    ifstream fin("/Users/at/gitSchool/usu/2015/CS2420/a7/digraph2.txt");
//    ifstream fin("/Users/at/gitSchool/usu/2015/CS2420/a7/digraph3.txt");

//    Input files
//    ifstream fin("digraph1.txt");
    ifstream fin("digraph2.txt");
//    ifstream fin("digraph3.txt");
    if(!fin.is_open())
    {
        cout << "Error with input file";
        return 0;
    }
    int nodes;
    int edges;
    int node;
    int parent;
    fin >> nodes;
    fin >> edges;
    cout << "There are " << nodes << " nodes and " << edges << " paths in this file\n";
    switch(node)
    {
        1: cout << "one";
    }
// Create the graph and load the nodes into it.

//    Graph g(nodes);
    g.makeGraph(nodes);
    while(!fin.eof())
    {
        fin >> node;
        fin >> parent;
        g.insert(node, parent);
    }

    cout << g.toString();

//    Traverse the graph
//    g.traverse(5, false);

//    Part I
    cout << "\n\n-------------------\n";
    cout << "Part I";
    cout << "\n-------------------\n";
    g.SCA(2, 8);

//  Part II
    cout << "\n\n-------------------\n";
    cout << "Part II";
    cout << "\n-------------------\n";
    int set1[3] = {13, 23, 24};
    int set2[3] = {16, 17, 6};
    g.SCA(set1, set2);

//    User Interface for single path travesal
    cout << "\n\n-----------------\n";
    cout << "Runner";
    cout << "\n-----------------\n";
    play();
    return 0;
}

void play()
{
    int first = 0;
    int second = 0;
    while(true)
    {
        cout << g.toString();
        cout << "-1 to quit\n";
        cout << "Enter the nodes you want visited\n";
        cout << "First: ";
        cin >> first;
        if(first < 0)break;
        cout << "Second: ";
        cin >> second;
        if(second < 0)break;
        g.SCA(first, second);
    }
    cout << "\nThanks for playing";
}