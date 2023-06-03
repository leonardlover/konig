#ifndef QUADTREE_H
#define QUADTREE_H

#include "Point.h"
#include "Node.h"

//template<typename T>
class QuadTree
{
    private:
        Node *root;
        int pointCount;
        int nodeCount;

    public:
        QuadTree(int xBound, int yBound);
        int totalPoints(void);
        int totalNodes(void);
        void insert(Point *p);
        void insertAt(Node *node, Point *p);
        Point *list(void);
        int countRegion(Point p, int d);
        int aggregateRegion(Point p, int d);
};

#endif
