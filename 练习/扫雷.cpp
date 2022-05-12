#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,j;
	char bomb;
	scanf("%d %d",&n,&m);
	int a[n][m];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			a[i][j]=0;
			
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>bomb;
			if(bomb=='*')
			{
				a[i][j]=10;
				a[i-1][j-1]++;
				a[i-1][j]++;
				a[i-1][j+1]++;
				a[i][j-1]++;
				a[i][j+1]++;
				a[i+1][j-1]++;
				a[i+1][j]++;
				a[i+1][j+1]++;
			}
		}
	}	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
		if(a[i][j]>8) 
			printf("*");
		else 
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
} 

