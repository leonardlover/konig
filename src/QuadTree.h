#ifndef QUADTREE_H
#define QUADTREE_H

#include "Point.h"
#include "Node.h"

template<typename T>
class QuadTree
{
    private:
        Node<T> *root;
        int pointCount;
        int nodeCount;

    public:
        QuadTree();
        int totalPoints(void);
        int totalNodes(void);
        void insert(Point p, T &data);
        void insertAt(Node *node, Point p, T &data);
        Point *list(void);
        int countRegion(Point p, int d);
        int aggregateRegion(Point p, int d);
};

#endif
