#ifndef FIGURE_H
#define FIGURE_H
#include <math.h>
struct Point { float x; float y; };
struct Rhombus { struct Point Center; struct Point PointSide_1; struct Point PointSide_2; };
float Perimeter(struct Rhombus Key);
float Area(struct Rhombus Key);
#endif