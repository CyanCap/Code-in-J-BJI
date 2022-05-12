#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#define ll long long 
using namespace std;
// ll exgcd(ll a,ll b,ll &x,ll &y)
// {
// 	if(!b)
// 	{
// 		x=1;y=0;
// 		return a;
// 	}
// 	else
// 	{
// 		ll tx,ty;
// 		ll d=exgcd(b,a%b,tx,ty);
// 		x=ty;y=tx-(a/b)*ty;
// 		return d;
// 	}
// }

ll exgcd(ll &x,ll &y,ll a,ll b)
{
    if(!b)
    {
        x=1;
        y=0;
        return a;
    }
    ll d=exgcd(x,y,b,a%b);
    int t=x;
    x=y;
    y=t-a/b*y;
    return d;
}

int main()
{
	ll a,b,k,x,y;scanf("%lld%lld%lld",&a,&b,&k);
	ll d=exgcd(x,y,a,b);
	printf("%lld %lld\n",x,y);
	return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// int cal(int x)
// {
//     int c = 21*x-8;
//     return c;
// }

// int main()
// {
//     int x;
//     while(cin>>x)
//     {
//         cout << cal(x) << endl;
//     }
//     return 0;
// }