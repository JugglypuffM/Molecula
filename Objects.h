//
// Created by Jugglyuser on 05.04.2023.
//

#include "iostream"
#include "Vector.h"
#include "cmath"
#include "string"
#include "limits"

using namespace std;

#ifndef MOLECULA_OBJECTS_H
#define MOLECULA_OBJECTS_H

class Plane{
public:
    double a, b, c ,d;
    Plane(double, double, double, double);
    Plane();
};

class Point{
public:
    double x, y, z;
    Point(double, double, double);
    Point();
};

class Line{
public:
    Point p;
    Vector v;
    Line(Point, Vector);
    Line();
};

#endif //MOLECULA_OBJECTS_H
