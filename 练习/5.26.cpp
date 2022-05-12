#include<bits/stdc++.h>
using namespace std;

int y, m, x;
int i, j;
// int yc = 0, dc = 0, mc = 0;
int bs[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int find(int num, int x)
{
    if(x==0&&x<=10)
        return 1;
    int a = 0;
    while(num)
    {
        if(num%10==x)
        {
            a++;
            num /= 10;
        }
    }

    return a;
}

int main()
{
    while(cin>>y>>m>>x)
    {
        if((y%4==0&&y%100!=0)||y%400==0)
            bs[2] = 29;

        int sum = 0;
        for (i = 1; i <= bs[m];i++)
        {
            sum += find(y, m) + find(m, x) + find(i, x);
        }
        cout << sum;

        // for (i = 1; i <= bs[m];i++)
        // {
        //     if(m<10)
        //     {
        //         for (j = 1; j <= 4;j++)
        //         {
        //             yc = y % 10;
        //             while(yc==x)
        //                 sum++;
        //         }
        //         if(x==0)
        //             sum += bs[m];
        //         else
        //         {
        //             mc = m % 10;
        //             while(x==mc)
        //                 sum++;
        //         }
        //         dc = i % 10;
        //         while(x==dc)
        //             sum++;
        //     }
        //     else if(m>=10)
        //     {
        //         for (j = 1; j <= 4;j++)
        //         {
        //             yc = y % 10;
        //             while(yc==x)
        //                 sum++;
        //         }
        //         for (j = 1; j <= 2;j++)
        //         {
        //             mc = m % 10;
        //             while(x==mc)
        //                 sum++;
        //         }
        //         dc = i % 10;
        //         while(x==dc)
        //             sum++;
        //     }
        }   
    return 0;
}
//                                          TOO LARGE!