#include "Point.h"

Point::Point(){}

Point::Point(double x, double y)
{
    _x = x;
    _y = y;
}

Point::Point(double x, double y, std::string country, std::string city, int population) 
{
    _x = x;
    _y = y;
    _country = country;
    _city = city;
    _population = population;
}

double Point::x(void)
{
    return _x;
}

double Point::y(void)
{
    return _y;
}

std::string Point::country(void)
{
    return _country;
}

std::string Point::city(void)
{
    return _city;
}

int Point::population(void)
{
    return _population;
}