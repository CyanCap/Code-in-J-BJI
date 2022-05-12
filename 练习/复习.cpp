#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char a[100];
    // scanf("%s", a);
    gets(a);
    puts(a);
    printf("%d", strlen(a));
}

// int main()
// {
//     char str[100];
//     gets(str);
//     printf("|%-25s|", str);
//     return 0;
// }