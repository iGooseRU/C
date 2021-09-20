#include <stdio.h>

int main()
{
    /// Ex 1
    char sub[256];
    char c;
    int j = 0;
    while ((c = getchar()) != EOF)
    {
        sub[j++] = c;
    }

    int digits = 0;
    int bigLetters = 0;
    int littleLetters = 0;

    for (int i = 0; sub[i] != '\n'; i++)
    {
        if (sub[i] >= '0' && sub[i] <= '9')
        {
            digits++;
        }
        else if (sub[i] >= 'a' && sub[i] <= 'z')
        {
            littleLetters++;
        }
        else if (sub[i] >= 'A' && sub[i] <= 'Z')
        {
            bigLetters++;
        }
    }
    printf("Digits = %d\nLittleLetters = %d\nBigLetters = %d\n",
           digits, littleLetters, bigLetters);
    /// Ex. 2
    int n;
    scanf("%d", &n);

    char digit[128];
    int k = 0;
    while (n > 0)
    {
        digit[k++] = n % 10 + '0';

        n /= 10;
    }
    for (int i = k - 1; i >= 0; i--)
    {
        printf("%c", digit[i]);
    }

    return 0;
}
