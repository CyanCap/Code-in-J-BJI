#include<bits/stdc++.h>
#include<string.h>
using namespace std;

string a;
int i, l;
int main()
{
    cin >> a;
    l = a.size();
    for (i = l - 1; i >= 0;i--)
    {
        cout << a[i];
    }
    // cout << a << endl;
    return 0;
}

// #define pi 3.14159265358979323
// int r;
// double s;
// int main()
// {
//     cin >> r;
//     s = r * r * pi;
//     printf("%.7f", s);
//     return 0;
// }

// int t, x;
// long long sum;
// int main()
// {
//     cin >> t;
//     while(t--)
//     {
//         while(cin>>x)
//         {
//             sum += x;
//             if(getchar()=='\n')
//                 break;
//         }
//         cout << sum << endl;
//         sum = 0;
//     }
//     return 0;
// }

// int finddif(int [], int [], int );
// int n, m,differ;
// int i, j;
// int m = 100000000;
// int a[1009], b[1009];
// int main()
// {
//     cin >> n;
//     for (i = 0; i < n;i++)
//     {
//         cin >> a[i];
//     }
//     cin >> m;
//     for (i = 0; i < m;i++)
//     {
//         cin >> b[i];
//     }
//     if(n<m)
//     {
//         cout << finddif(a, b, n) << endl;
//     }
//     else
//     {
//         cout << finddif(a, b, m) << endl;
//     }
//     return 0;
// }