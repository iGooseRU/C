#include <stdio.h>
#include "main.h"

int main()
{
    struct Rhombus Key;
    printf("If ur not pidor - enter fucking cords: ");
    scanf("%lf %lf", &Key.Center.x, &Key.Center.y);
    scanf("%lf %lf", &Key.PointSide_1.x, &Key.PointSide_1.y);
    scanf("%lf %lf", &Key.PointSide_2.x, &Key.PointSide_2.y);
    printf("Perimeter = %.2lf\n", Perimeter(Key));
    printf("Area = %.2lf\n", Area(Key));
    return 0;
}