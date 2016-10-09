//
// Created by Adam on 11/30/15.
//

#include <sstream>
#include "Graph.h"

void Graph::insert(int node, int parent)
{
    if(G[node].parentID != -1)
        G[node].parentID1 = parent;
    else
        G[node].parentID = parent;
};

//Traverse the graph
void Graph::traverse(int node, bool second)
{
    cout << "\nTraverse " << node << endl;
    GraphNode g = G[node];
    q.push(g);
    int from;
    int length = 0;
    while(!q.empty())
    {
        from = g.nodeID;
        length = G[g.nodeID].pathLenth + 1;
        g = q.front();
        q.pop();
        second ? G[g.nodeID].visited1 = true : G[g.nodeID].visited = true;
        if(G[g.nodeID].visited && G[g.nodeID].visited1)
        {
            if(firstLength + secondLength > G[g.nodeID].pathLenth + length)
            {
                pathLength = G[g.nodeID].pathLenth + length;
//                cout << endl << pathLength << endl;
                second = from;
                first = G[g.nodeID].from;
                firstLength = G[g.nodeID].pathLenth;
                secondLength = length;
                sca = G[g.nodeID];
            }
        }
        G[g.nodeID].from = from;
        G[g.nodeID].pathLenth = length;

        toString(G[g.nodeID]);

        if(g.parentID != -1)
            q.push(G[g.parentID]);
        if(g.parentID1 != -1)
            q.push(G[g.parentID1]);
    }
};

void Graph::toString(GraphNode node)
{
    cout << node.toString() << "\tFrom:  " << node.from;
    node.visited ? cout << "\tpath1" : cout << "\t_____";
    node.visited1 ? cout << "\tpath2" : cout << "\t_____";
    cout << "\tLength: " << node.pathLenth;
    cout << endl;
}


void Graph::SCA(int v, int w)
{
    resetGraph();
    traverse(v, false);
    traverse(w, true);
    if(v == w)pathLength = 0;
    cout << "\nleast Common Ancestor for (" << v << ", " << w << "): " << sca.nodeID;
    cout << "\nLength: " << pathLength << endl;
}

void Graph::SCA(int v[], int w[])
{
    resetGraph();
    cout << "\nFirst Group:\n";
    for(int i = 0; i < (sizeof(v)/sizeof(*v) + 1); i++)traverse(v[i], false);
    cout << "\nSecond Group:\n";
    for(int i = 0; i < (sizeof(w)/sizeof(*w) + 1); i++)traverse(w[i], false);
    if(v == w)pathLength = 0;
//    cout << "\nleast Common Ancestor for (" << v << ", " << w << "): " << sca.nodeID;
    cout << "\nLeast Common Ancestor for ( ";
    for(int i = 0; i < (sizeof(v)/sizeof(*v) + 1); i++)cout << v[i] << " ";
    cout << ", ";
    for(int i = 0; i < (sizeof(w)/sizeof(*w) + 1); i++)cout << w[i] << " ";
    cout << "): " << sca.nodeID;
    cout << "\nLength: " << pathLength << endl;

}

string Graph::toString()
{
    stringstream ss;
    for(int i = 0; i < nodeCt; i++)
        ss << endl << G[i].toString();
    ss << endl;
    return ss.str();
}

void Graph::resetGraph()
{
    firstLength = secondLength = 100;
    for(int i = 0; i < nodeCt; i++)
    {
        G[i].visited = G[i].visited1 = false;
        G[i].pathLenth = G[i].from = -1;
    }
}

