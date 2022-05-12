#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// ll a[2000005];
// int T = 0;
// int main ()
// {
//     ios::sync_with_stdio(0);
//     int i;
//     cin >> T;
//     while(T--)
//     {
//         int n,k;
//         cin >> n >> k;
//         for (i = 1; i <= n;i++)
//         {
//             cin >> a[i];
//             a[i] += a[i - 1];
//         }
//         ll m = -1e18, ans = -1e18;
//         for (i = k; i + k <= n;i++)
//         {
//             m = max(m, a[i] - a[i - k]);
//             ans = max(ans, m + a[i + k] - a[i]);
//         }
//         cout << ans << endl;
//     }
    
//     return 0;
// }

int w, n, p[30005];
int i;
int main()
{
    cin >> w;
    cin >> n;

    int l = 1, r = n, sum = 0;
    for (i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    sort(p + 1, p + n + 1);
    while(l<=r)
    {
        if(p[l]+p[r]<=w)
        {
            l++, r--;
         sum++;
        }
        else
        {
            r--;
            sum++;
        }
    }
    cout << sum << endl;

    return 0;
}