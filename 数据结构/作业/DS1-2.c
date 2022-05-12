#include<stdio.h>

int main()
{
    int num = 0;
    int ge, shi, bai;
    for (int i = 100; i <= 999; i++)
    {
        num = i;
        ge = num % 10;
        shi = (num / 10) % 10;
        bai = num / 100;
        if(ge*ge*ge+shi*shi*shi+bai*bai*bai==num)
            printf("%d\n", num);
    }
    return 0;
}