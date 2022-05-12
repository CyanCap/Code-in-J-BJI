#include<stdio.h>
int sum(int n)
{
//	if(n==1) 
//		return 1;
//	else
//		return (n+sum(n-1));
	return n==1?1:n+sum(n-1);
}
int main()
{
	int n=0;
	scanf("%d",&n);
	printf("%d",sum(n));
 } 

