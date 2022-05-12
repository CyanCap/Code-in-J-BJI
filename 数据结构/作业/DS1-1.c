#include<stdio.h>
void rstr(char* str)
{
    int l = 0;
    char* p = str;
    while (*p != 0)
    {
        l++;
        p++;
    }
    int i = 0;
    char c;
    while (i <= l / 2 - 1)
    {
        c = *(str + i);
        *(str + i) = *(str + l - 1 - i);
        *(str + l - 1 - i) = c;
        i++;
    } 
}
int main()
{
    char str[10010] = "";
    gets(str);
    rstr(str);

    printf("%s\n", str);
    return 0;
}