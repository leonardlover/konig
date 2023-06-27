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
        int countRegion(Point p, int d);
        int aggregateRegion(Point p, int d);
};

#endif
