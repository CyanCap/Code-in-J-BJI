#include<bits/stdc++.h>
using namespace std;
string s,a;
int main()
{
    int f = 0;
    cin >> s;
     for(int i=s.length()-1;i>=0;i--)
     {
        f++;
        a+=s[i];
        if(f%3==0) a+=',';
    }

    for(int i=a.length()-1;i>=0;i--)
    {
        if(i==a.length()-1&&a[i] == ',')    continue;
        cout << a[i];
    }
    cout << endl;
    return 0;
}

// int t, i,temp;
// int a[109], b[109], c[109];
// int main()
// {
//     cin >> t;
//     for (i = 0; i < t;i++)
//     {
//         cin >> a[i] >> b[i] >> c[i];
//     }

//     for (int i = 0; i < t;i++)
//     {    if (a[i] >= b[i])
// 		{
// 			temp=a[i];
// 			a[i]=b[i];
// 			b[i]=temp;
// 		}
// 		if(a[i] >= c[i])
// 		{
// 			temp=a[i];
// 			a[i]=c[i];
// 			c[i]=temp;
// 		}
// 		if(b[i] >= c[i])
// 		{
// 			temp=b[i];
// 			b[i]=c[i];
// 			c[i]=temp;
// 		}
//         cout << c[i] << b[i] << a[i] << endl;
//     }

//     return 0;
// }
