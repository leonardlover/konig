#ifndef NODE_H
#define NODE_H

#include "Box.h"
#include <vector>

using namespace std;

class Node
{
    private:
        Box boundary;
        Node *parent;
        vector<Node *> children;
        Point point;
        bool isLeaf;
        bool color; // if true, Node has children
        
    public:
        Node(Box bx, Node *par);
        ~Node(void);
        void insert(Point p, long long &pointCount, long long &nodeCount);
        int divide(void); // create 4 children
        Box bound(void);
        vector<Node *> childs(void);
        bool hasPoint(void); // checks if Node has city Point associated with it
        bool getColor(void);
        Point data(void);
        long long region(Box bx, bool aggregate); // computes a query over region delimited by bx
                                                  // aggregate determines if it counts cities or people
};

#endif
