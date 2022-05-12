#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, m;
    int a[25];
    while(cin>>n)
    {
        for (i = 0; i < n;++i)
        {
            cin >> a[i];
        }
        cin >> m;
        for (i = 0; i < n;i++)
        {
            if(a[i]==m)
            {
                cout << i;
                break;
            }
        }
    }
    return 0;
}




// int main()
// {
//     int n, i;
//     int ans = 0;
//     cin >> n;
//     for (i = 1; i <= n;i++)
//     {
//         if(n%i==0)
//             ans = ans + i;
//     }
//     cout << ans;
//     return 0;
// }