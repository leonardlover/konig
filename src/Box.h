#ifndef BOX_H
#define BOX_H

#include "Point.h"

class Box
{
    private:
        Point upper;
        Point lower;

    public:
        Box(Point p, Point q);
        Point getUpper(void);
        Point getLower(void);
        bool contains(Point p);
};

#endif
