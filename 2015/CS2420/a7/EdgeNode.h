//
// Created by Adam on 11/30/15.
//

#ifndef A7_EDGENODE_H
#define A7_EDGENODE_H


class EdgeNode
{
public:
        int toNode;  // Node id of target of edge
        int fromNode;  // Node id of source of edge
//        int distance;   // Cost of Edge (for a weighted graph only)
        EdgeNode *next;  // Next edge in linked list for adjacency list representation
        // Constructor – note the use of default parameters.
// Note the strange assignments (distance(dist)) – they aren’t my favorite either, but texts seem      to like them
        EdgeNode( int from = -1, int to=-1, int dist=0, EdgeNode *nextEdge = nullptr):
                toNode( to ), fromNode(from), next(nextEdge){};
}; // EdgeNode


#endif //A7_EDGENODE_H
