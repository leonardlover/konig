#ifndef QUADTREE_H
#define QUADTREE_H

#include "Point.h"
#include "Node.h"
#include <vector>
#include <stack>

using namespace std;

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
        void insert(Point *p, bool test);
        void insertAt(Node *node, Point *p, bool test);
        std::vector<Point*> list(void);
        int countRegion(Point p, int d);
        int aggregateRegion(Point p, int d);
};

#endif