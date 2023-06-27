#ifndef QUADTREE_H
#define QUADTREE_H

#include "Node.h"
#include "Point.h"

class QuadTree
{
    private:
        Node *root;
        long long pointCount;
        long long nodeCount;

    public:
        QuadTree(void);
        ~QuadTree(void);
        long long totalPoints(void);
        long long totalNodes(void);
        void insert(Point p);
        vector<Point> list(void);
        long long countRegion(Point p, double d);
        long long aggregateRegion(Point p, double d);
};

#endif
