#include "Point.h"

Point::Point(int x, int y)
{
    _x = x;
    _y = y;
}

int Point::x(void)
{
    return _x;
}

int Point::y(void)
{
    return _y;
}
