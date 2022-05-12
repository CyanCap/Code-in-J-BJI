#include<stdio.h>
#define MAX 10010

float findam(float num[],int n)                    //arthmetic mean
{
    int i = 0;
    float avg = 0, sum = 0;
    for (i = 0; i < n; i++)
        sum = sum + num[i];

    avg = sum / n;
    return (avg);
}
float findhm(float num[],int n)                   //harmonic mean
{
    int i = 0;
    float havg = 0, hsum = 0;
    for (i = 0; i < n; i++)
        hsum = hsum + (1 / num[i]);

    havg = n / hsum;
    return (havg);
}

int main()
{
    int j = 0;
    float nums[MAX];
    while(scanf("%f",&nums[j])!=EOF)
        j++;

    printf("\narthmetic mean:%f\nharmonic mean:%f\n", findam(nums, j),findhm(nums, j));
    return 0;

}