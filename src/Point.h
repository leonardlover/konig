#ifndef POINT_H
#define POINT_H

#include <string>

class Point
{
    private:
        double _x;
        double _y;
        std::string _country;
        std::string _city;
        int _population;

    public:
        Point();
        Point(double x, double y);
        Point(double x, double y, std::string country, std::string city, int population);
        double x(void);
        double y(void);
        std::string country(void);
        std::string city(void);
        int population(void);
};

#endif
