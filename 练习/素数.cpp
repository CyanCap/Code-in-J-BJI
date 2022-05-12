#include<bits/stdc++.h>
using namespace std;

long long fact(int n)
{

    if(n==1)
    {
        return 1;
    }
    else if(n>1)
    {
        return (n * fact(n - 1));
    }
}


int main()
{
    long long sum = 0;
    int p = 2, m = 1, max;
    while(cin>>max)
    {
    while(p<=max)
    {
        int z = p - m;
        int a = p % z;
        if(a==0)
        {
            if(z==1)
            {
                // cout << p << endl;
                sum += fact(p);
                p++;
                m = 1;
            }
            else
                p++;
            
            m = 1;
        }
        else
        {
            m++;
        }
    }
    cout << sum << endl;
    sum = 0;
    }
}





// int main()
// {
//     int N;
//     cin >> N;
//     int primes[N]={0};
//     int i, j;
//     int p = 2;
//     step2:
//     if((p^2) <= (N^4))
//     {
//         for (i = 0; i < N;i++)
//         {
//             if(i*p < N && i!=1)
//                 primes[i] = i * p;
//         }
//         while(p<N)
//         {
//             p++;
//             goto step2;
//         }
//     }else
//     {
//         for (j = 0; j < N;j++)
//         {
//             cout << primes[j] << endl;
//         }
//     }
//     return 0;
// }