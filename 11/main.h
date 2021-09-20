#ifndef FIGURE_H
#define FIGURE_H

#include <math.h>

struct Point {
    double x;
    double y;
};

struct Rhombus {
    struct Point Center;
    struct Point PointSide_1;
    struct Point PointSide_2;
};

double Perimeter(struct Rhombus);
double Area(struct Rhombus);

#endif