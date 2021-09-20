#include <math.h>
#include "main.h"

double Perimeter(struct Rhombus Key) {
    return 4 * sqrt(pow(Key.PointSide_1.x - Key.PointSide_2.x, 2) +
    pow(Key.PointSide_1.y - Key.PointSide_2.y, 2));
}

double Area(struct Rhombus Key) {
    return 4 * sqrt(pow(Key.Center.x - Key.PointSide_2.x, 2) +
    pow(Key.Center.y - Key.PointSide_2.y, 2)) * sqrt(pow(Key.PointSide_1.x -
    Key.Center.x, 2) + pow(Key.PointSide_1.y - Key.Center.y, 2));
}