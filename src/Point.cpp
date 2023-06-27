#include <string>
#include "Point.h"

using namespace std;

Point::Point(double X, double Y)
{
    x = X;
    y = Y;
    country = "";
    city = "";
    population = -1;
}

Point::Point(double X, double Y, const string &Country, const string &City, double Population)
{
    x = X;
    y = Y;
    country = Country;
    city = City;
    population = Population;
}
