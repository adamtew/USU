//
// Created by Adam on 11/30/15.
//

#ifndef A7_GRAPH_H
#define A7_GRAPH_H

#include "GraphNode.h"
#include <queue>

class Graph {
protected:
    GraphNode *G;  // Array of nodes of graph – will be given space once the size is known
    int nodeCt;    // Size of G
    queue<GraphNode> q;
    GraphNode sca;
    int first;
    int second;
    int firstLength;
    int secondLength;
    int pathLength;

public:
    Graph(int size) {
        G = new GraphNode[size];
        for(int i = 0; i < size; i++)
        {
            G[i].nodeID = i;
        }
        firstLength = 100;
        secondLength = 100;
        pathLength = 0;
        nodeCt = size;
    };  // create node array
    Graph()
    {
        firstLength = 100;
        secondLength = 100;
        pathLength = 0;
    }
    void makeGraph(int size)
    {
        G = new GraphNode[size];
        for(int i = 0; i < size; i++)
        {
            G[i].nodeID = i;
        }
        nodeCt = size;
    }
//    string toString(string label, ostream &fout);
    string toString();
    void traverse(int node, bool second);
    void toString(GraphNode node);
    void SCA(int w, int v);
    void resetGraph();

//  sets
    void SCA(int v[], int w[]);

    void insert(int node, int parent);
}; // Graph

#endif //A7_GRAPH_H
