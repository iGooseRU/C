#include <stdio.h>
int main()
{   int a;
    char b[10]; // Объявление массива
    gets(b);  // Считывание массива
    printf("%s",&b);  // Вывод полученных значений в консоль
    return 0;
}