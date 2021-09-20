#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char a[10];
    char *p = a;
    char *gets(char *a);
    printf("%c\n%c\n%c\n%c\n", *p, *(p+1), *(p+2), *(p+3));

    printf("\n");

    char *b = (char *) malloc (4*sizeof(char));
    char *w = b;
    *(w) = 'W';
    *(w+1) = 'O';
    *(w+2) = 'R';
    *(w+3) = 'K';
    for (int i=0; i<4; i++)
    {
        printf ("%c\n", *(w+i));
    }
    free (b);
    return 0;
}