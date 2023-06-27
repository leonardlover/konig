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
        int localPoints;
        int localPopulation;

    public:
        Node(Box bx, Node *par);
        ~Node(void);
        void insert(Point p, int &pointCount, int &nodeCount);
        int divide(void);
        Box bound(void);
        vector<Node *> childs(void);
        bool hasPoint(void);
        Point data(void);
        int region(Box bx, bool aggregate);
};

#endif
