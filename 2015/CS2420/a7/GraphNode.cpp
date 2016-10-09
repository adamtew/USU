//
// Created by Adam on 11/30/15.
//


#include "GraphNode.h"
#include <sstream>

string GraphNode::toString()
{
    stringstream ss;
    if(parentID1 != -1)
    {
        ss << "(" << nodeID << ", " << parentID << ", " << parentID1 << ")";
        return ss.str();
    }
    ss << "(" << nodeID << ", " << parentID << ")";
    return ss.str();
}
