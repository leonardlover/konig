#ifndef NODE_H
#define NODE_H

#include "Point.h"

template<typename T>
class Node
{
    private:
        T &data;
        Point above;
        Point below;
        bool color;

        Node *parent;
        Node **children;

    public:
        // TODO
};

#endif
