#include <stdio.h>

// описание перечисление
enum Music {
    Classic,   // 0
    Pop,       // 1
    Rock,      // 2
    Rap,       // 3
    Phonk };   // 4

    // для задания 2
struct Line{
    int x0, x1;
}pos;

//Описание состояния приборов
struct ADSL_bits {
    unsigned char DSL : 1;
    unsigned char PPP : 1;
    unsigned char Link : 1;
};
//Объединение
typedef union Printer {
    struct ADSL_bits bits;
    unsigned char ADSL;
};

int main() {
   // printf("%d\n",sizeof (struct ADSL_bits);
    // задание 1
    enum Music a = Rock;
    printf("Exercise 1:\n");
    printf("%d\n", a);
    printf("__________\n");

    // задание 2
    pos.x0 = 2;
    pos.x1 = 12;
    printf("Exercise 2:\n");
    printf("Line Length = %d\n", pos.x1 - pos.x0);
    printf("__________\n");

    // задание 3
    printf("Exercise 3:\n");
    union Printer my_printer; //Задание 3
    scanf("%hx", &my_printer.ADSL);
    if (my_printer.bits.DSL == 1) {
        printf("DSL is working\n");
    }
    else {
        printf("DSL isn't working\n");
    }
    if (my_printer.bits.PPP == 1) {
        printf("PPP is working\n");
    }
    else {
        printf("PPP isn't working\n");
    }
    if (my_printer.bits.Link == 1) {
        printf("Link is working\n");
    }
    else {
        printf("Link isn't working\n");
    }
    printf("__________\n");
    return 0;


}

