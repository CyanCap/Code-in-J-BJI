#include<bits/stdc++.h>
using namespace std;
int a, b, x, y;
int sum = 0;
int main()
{
    while(cin>>x>>y>>a>>b)
    {
        here:
        if(a>=x)
        {
            a = a - x;
            a++, sum++;
            goto here;
        }
        else if(b>=y)
        {
            b = b - x;
            b++, sum++;
            goto here;
        }
        cout << sum;
        sum = 0;
    }
    return 0;
}

// long long n;
// int fact(long long);
// int main()
// {
//     cin >> n;
//     cout << fact(n);

//     return 0;
// }

// int fact(long long n)
// {
//     if(n==0)
//         return (1);
//     else
//         return (n * fact(n - 1));
// }