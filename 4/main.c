#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d", &a); //задание 1
    c = (a >= -3 && a <= 6);
    printf("%s\n", c ? "yea" : "no");
    scanf("%o", &b); //2 задание, считывание с консоли числа в 8-ой сс
    printf("%d\n", (b >> 4) & 1);
    return 0;

}