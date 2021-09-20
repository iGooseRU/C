#include <stdio.h>
#include <string.h>

int clbuf() {
    int ch;
    while (((ch = getchar()) != EOF) && (ch != '\n')) /* void */;
    return ch;
}


char del(char* str1, int j) // ����������� ������� �������� ������� �������
{
    int i;
    for (i = j; i < strlen(str1) - 1; i++)
        str1[i] = str1[i + 1];
    str1[i] = 0;
    return *str1;
}

int NODEuclid(a, b)
{
    if (b ==0) {
        return a;
    } else{
        return NODEuclid(b, a % b);
    }
}

int NOK(int a, int b)
{
    int res = a / NODEuclid(a, b)*b;
    return res;
}

/*char del(char* str1, int k)
{
    int f;
    for (f = k; f < strlen(str1) - 1; f++)
        str1[f] = str1[f + 1];
    str1[f] = 0;
    return *str1;
}
*/
int main()
{
 int i, j, r, t;
 printf("Task 1:\n");
   printf("i =:");
   scanf("%d", &i);
   printf("j =:");
   scanf("%d", &j);
   t = NODEuclid(i, j);
   r = NOK(i, j);
   printf("NOD %d and %d = %d\n", i, j, t);
   printf("NOK %d and %d = %d\n", i, j, r);
   printf("____________________");
   clbuf();

   printf("Task 5:\n\n");
   printf("Enter str:");
   char str[256];
        gets(str);
        for (int i = 0; i < 256; i++) {
            if (str[i] == ' ' && str[i + 1] == ' ')
            del(str, i);
        }
        for (int i = strlen(str); i > 0; i--)
        {
            if (str[i] == '.') {
                int j = i + 1;
                while (str[j] == ' ')
                    del(str, j);
                i = 0;
            }
        }
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == ' ' && str[i + 1] == '(')
            del(str, i);
            if (str[i] == ' ' && str[i + 1] == '<')
            del(str, i);
            if (str[i] == ' ' && str[i + 1] == '"')
            del(str, i);
        }
        printf("%s", str);
        return 0;
    }