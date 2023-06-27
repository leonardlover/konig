#ifndef QUADTREE_H
#define QUADTREE_H

#include "Node.h"
#include "Point.h"

class QuadTree
{
    private:
        Node *root;
        int pointCount;
        int nodeCount;

    public:
        QuadTree(void);
        ~QuadTree(void);
        int totalPoints(void);
        int totalNodes(void);
        void insert(Point p);
        vector<Point> list(void);
        int countRegion(Point p, double d);
        int aggregateRegion(Point p, double d);
};

#endif
