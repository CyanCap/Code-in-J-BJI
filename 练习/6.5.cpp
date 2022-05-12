#include<bits/stdc++.h>
using namespace std;

int i, j, cou = 0;
int main()
{
    int n;
    cin >> n;
    for (i = 0; i <= n / 5;i++)
        for (j = 0; j <= n / 2;j++)
        {
            if((i*5+j*2)>n)
                break;
            for (int k = 0; k <= n;k++)
            {
                if((i*5+j*2+k)>n)
                    break;
                else if((i*5+j*2+k)==n)
                    cou++;
            }
        }
    cout << cou << endl;
    return 0;
}

// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n;i++)
//     {
        
//         if(i%3==0)
//         {
//             int tmp = i;
//             while(tmp!=0)
//             {
//                 if(tmp%10==5)
//                 {
//                     cout << i << endl;
//                 }
//                 break;
//                 tmp / 10;
//             }
//         }
//     }
//     return 0;
// }


// int main()
// {
//     int x, y, z;
//     cin >> x >> y;
//     while(x!=y)
//     {
//         z = abs(x-y);
//         x = y;
//         y = z;

//     }
//     cout << x;
//     return 0;
// }

// int main()
// {
//     int n, sum;
//     cin >> n;
//     for (int i = 1; i <= n;i++)
//     {
//         if(i%7==0)
//             sum += i;
//     }
//     cout << sum << endl;
//     return 0;
// }

// int A(int x)
// {
//     if(x==1)
//         return 0;
//     else if(x==2)hg
//         return 1;
//     else if(x==3)
//         return 1;
//     else if(x>3)
//         return (A(x - 3) + 2 * A(x - 2) + A(x-1));
// }
// int main()
// {
//     int n;
//     int fun;
//     cin >> n;
//     fun = A(n);
//     cout << fun << endl;
//     return 0;
// }

// int a(int x)
// {
//     if(x==1)
//         return 1;
//     else if(x==2)
//         return 1;
//     else if(x>2)
//         return (a(x - 1) + a(x - 2));
// }
// int main()
// {
//     int n;
//     int sum;
//     cin >> n;
//     sum = a(n);
//     cout << sum << endl;
//     return 0;
// }

// int sum(int x)
// {
//     int sum = 0;
//     for (int i = 1; i <= x;i++)
//     {
//         sum += i;
//     }
//     return sum;
// }
// int main()
// {
//     int ans;
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n;i++)
//     {
//         ans += sum(i);
//     }
//     cout << ans << endl;
//     return 0;
// }



// double fen(int x)
// {
//     double sum = 0;
//     for (int i = 1; i <= x;i++)
//     {
//         sum += pow(1, i) * (2 * i - 1);
//     }
//     return sum;
// }
// int main()
// {
//     double ans;
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n;i++)
//     {
//         ans += 1.0 / fen(i);
//     }
//     printf("%.3lf", ans);
//     return 0;
// }

// int altsum(int x)
// {
//     int sum = 0;
//     for (int i = 1; i <= x; i++)
//     {
//         if(i%2!=0)
//             sum += i;
//         else if(i%2==0)
//             sum -= i;
//     }
//     return sum;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     cout << altsum(n) << endl;
// }

// int main()
// {
//     int x, y, z;
//     cin >> x >> y >> z;
//     cout << "The maximum number is : " << max(max(x, y), z) << endl;
//     cout << "The minimum number is : " << min(min(x, y), z) << endl;
//     return 0;
// }

// int main()
// {
//     int w;
//     cin >> w;
//     if(w%2==0 && (w/2)%2==0)
//         cout << "YES, you can divide the watermelon into two even parts." << endl;
//     else
//         cout << "NO, you can't divide the watermelon into two even parts." << endl;
//     return 0;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     if(n%2==0)
//     {
//         cout << "even";
//     }else
//     {
//         cout << "odd";
//     }
//     return 0;
// }

// int main()
// {
//     int x, y;
//     cin >> x >> y;
//     printf("%d+%d=%d\n", x, y, x + y);
//     printf("%5d\n+%4d\n-------\n%5d", x, y, x + y);
//     return 0;
// }

// int main()
// {
//     long long n;
//     cin >> n;
//     if((n%10)>=5)
//     {
//         cout << (n + (10 - n % 10)) << endl;
//     }
//     else{
//         cout << (n - n % 10) << endl;
//     }
//     return 0;
// }