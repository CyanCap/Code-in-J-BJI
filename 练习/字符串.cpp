#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,l,r;
	char s[n];
	char c1,c2;
	scanf("%d %d",&n,&m);
	getchar();
	scanf("%s",s);
	while(m--)
	{
		scanf("%d %d",&l,&r);
		cin>>c1>>c2;
		for(i=l-1;i<=r-1;i++)
		{
			if(s[i]==c1)	
			{
				s[i]=c2;
			}
		}
    }
	printf("%s",s);
	return 0;
}
