#include "QuadTree.h"
#include <iostream>
using namespace std;

int main() {
    int xb, yb; // xbound, ybound
    cin >> xb >> yb;
    
    QuadTree *qt = new QuadTree(xb,yb);

    double x, y;
    string country, city;
    int population;
    Point* list;

    int c = 0;
    while(cin >> country >> city >> population >> x >> y) { // insert points data
        c++;
        Point *p = new Point(x, y, country, city, population);
        qt->insert(p);
        list = qt->list();
        for(int i = 0; i < c; i++) {
            cout << list[i].city() << " ";
        }
    }
    cout << endl;

    return 0;
}