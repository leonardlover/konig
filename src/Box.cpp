#include "Box.h"
#include "Point.h"

Box::Box(Point p, Point q) : upper(p), lower(q)
{
}

Point Box::getUpper(void)
{
    return upper;
}

Point Box::getLower(void)
{
    return lower;
}

bool Box::contains(Point p)
{
    return upper.x <= p.x && p.x <= lower.x && upper.y <= p.y && p.y <= lower.y;
}

bool Box::contains(Box b)
{
    return contains(b.getUpper()) && contains(b.getLower());
}
