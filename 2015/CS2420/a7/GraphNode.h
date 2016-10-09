//
// Created by Adam on 11/30/15.
//

#ifndef A7_GRAPHNODE_H
#define A7_GRAPHNODE_H

#include <iostream>
using namespace std;

class GraphNode {
public:
    int nodeID;       // ID of node; something that makes it easy to find the node in the array
    int parentID;
    int parentID1;
    int pathLenth;
    int from;
//       string name;    // Node name
//       EdgeNode *adj;  // Adjacency list
    bool visited;  // true if visited already
    bool visited1;
    GraphNode( int  id= -1):
        nodeID(id), parentID(-1), parentID1(-1), from(-1), visited(false), visited1(false), pathLenth(-1){ }

    string toString();
}; // GraphNode

#endif //A7_GRAPHNODE_H
