#include <iostream>
#include "Point.h"
#include "QuadTree.h"

using namespace std;

int main(void)
{
    QuadTree *qt = new QuadTree();
    qt->insert(Point(100.0, 100.0, "cl", "mulchen", 100));
    cout << qt->totalPoints() << endl;
    cout << qt->totalNodes() << endl;
    qt->insert(Point(100.0, 100.0, "cl", "mulchen", 100));
    cout << qt->totalPoints() << endl;
    cout << qt->totalNodes() << endl;
    qt->insert(Point(200.0, 100.0, "cn", "beijing", 100));
    cout << qt->totalPoints() << endl;
    cout << qt->totalNodes() << endl;

    for (auto p : qt->list())
        cout << p.country << " " << p.city << " " << p.x << " " << p.y << " " << p.population << endl;

    cout << qt->aggregateRegion(Point(180.0, 180.0), 180) << endl;

    delete qt;

    return 0;
}
