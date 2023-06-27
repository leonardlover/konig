#ifndef NODE_H
#define NODE_H

#include "Point.h"

//template<typename T>
class Node
{
    private:
        //T &data;
        Point above; // upper left boundary
        Point below; // bottom right boundary
        Point point; // inserted point
        bool color; // capacity = 1, if there is a point, the node is black(true), otherwise it is white(false)
        Node *parent;
        Node *children[4]; // 0: TopLeft, 1: TopRight; 2: BottomLeft, 3: BottomRight
        bool divided;

    public:
        // TODO
        Node(int tl, int tr, int bl, int br, Node *p);
        void setPoint(Point p);
        void subdivide(Point p);
        bool isDivided(void);
        bool isPainted(void);
        Node *getChild(int n);
        void setColor(bool c);
        Point getPoint(void);
        bool contains(Point p);
};

#endif
