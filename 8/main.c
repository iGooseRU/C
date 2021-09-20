#include<stdio.h>
#include<string.h>

int main()
{
    char str1[50];
    char str2[50];
    char str3[50];
    gets(str1);
    gets(str2);
    int i,n,k;

    scanf("%d",&n);

    for (i = 0; i < 50; i ++)
    {
        str3[i] = str1[i];
    }
    printf("Exercise 1:\nstr1=: ");
    puts(strncat(str1, str2,n));
    printf("\n");

    printf("Exercise 2:");
    if (strncmp(str3,str2,n)==0){
        printf("yes");
    }
    else{
        printf("no");
    }
    printf("\n");
    printf("Exercise 3:");
    printf(memcpy(str3,str2,n));

    printf("\n\n");
    printf("Exercise 4:");
    printf("%d",strspn(str1,str3),"\n");

    printf("\n\n");
    printf("Exercise 5:");
    printf("%s",strtok(str1,str3));
    return 0;
}
