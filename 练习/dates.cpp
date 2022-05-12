#include<stdio.h>
void yrCalc(int,int *,int *,int *);
int main()
{
	int ys=0,ms=0,ds=0,n=0;
	scanf("%d",&n);
	yrCalc(n,&ys,&ms,&ds);
	printf("\n%d\n%d\n%d",ys,ms,ds);
	return 0;
}
void yrCalc(int n,int *years,int *months,int *days)
{
	*years=n/360;
	*months=((n- *years * 360)/30);
	*days=n-*years * 360-*months * 30;
	*years=1900+*years;
	*months=1+*months;
	*days=1+*days;
	return;
}
