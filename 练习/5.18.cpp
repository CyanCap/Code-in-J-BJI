#include<bits/stdc++.h>
using namespace std;
#define MAX 30
int size[MAX]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
int a[MAX],b[MAX];
int i,j,t;
int main()
{
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(i=0;i<t;i++)
	{
		for(j=0;j<30;j++)
		{	
			if(b[i]==size[j]&&a[i]<b[i])
			{
				cout<<size[j+1]<<endl;
				break;
			 } 
			else if(b[i]==size[j]&&a[i]>b[i])
			{
				cout<<size[31-j]<<endl;
				break;
			}
//			else if()
		} 
	}
	
	return 0;
}


//#define MAX 8
//int i,j,m,n;
//int num[MAX];
//
//int main()
//{
//	for(i=1;i<=9;i++)
//	{
//		for(j=0;j<=9;j++)
//		{
//			for(m=0;m<=9;m++)
//			{
//				for(n=0;n<=9;n++)
//				{
//					cout<<i<<j<<m<<n<<n<<m<<j<<i<<endl;
//				}
//			}
//		}
//	}
//	return 0;
//}
