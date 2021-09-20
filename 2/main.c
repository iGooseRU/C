#include <stdio.h>
#define _USE_MATH_DEFINES // для числа пи
#include <math.h>
int main()
{
	double z1, z2, deg, rad;
	     printf("Enter degree:");
	     scanf("%lf", &deg);    // ввод градусов
	          rad = (deg * M_PI / 180.0);  // перевод из градусов в радианы
	          z1 = (1.0 -((sin(2*rad)*sin(2*rad))/4)+cos(2*rad));  // ищем z1
	          z2 = ((cos(rad)* (cos(rad)) + (((cos(rad)* (cos(rad))*(cos(rad) * (cos(rad)))))))); //  ищем z2
	     printf("z1=""%f\n", z1 );  // вывод z1
	     printf("z2=""%f\n", z2);  // вывод z2
		 printf("%f", deg );         // вывод перевода градусов в радианы
	     printf(" degrees = ""%f", rad);
		 printf(" radians");
	return 0;
}