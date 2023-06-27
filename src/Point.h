#ifndef POINT_H
#define POINT_H

#include <string>

using namespace std;

class Point
{
    public:
        double x;
        double y;
        string country;
        string city;
        int population;

        Point(double X, double Y);
        Point(double X, double Y, const string &Country, const string &City, int Population);
};

#endif
