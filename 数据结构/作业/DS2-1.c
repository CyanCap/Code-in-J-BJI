#include<stdio.h>

void swap(double *a,double *b)
{
    double t;
    t = *a;
    *a = *b;
    *b = t;
}
int main()
{
    double a, b;
    scanf("%lf %lf", &a, &b);
    swap(&a, &b);
    printf("%lf\n%lf", a, b);
    return 0;
}