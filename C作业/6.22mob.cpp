#include<stdio.h>
int main() 
{
	int i=0;
	int j=0;
	int k=0;
	int a=36;
	int b=0;
	for(i=1;i<=100;i++){
		a=a%67;
		if(a==1){
			break;
		} 
		a=a*36;
	} 
printf("%d",i);
	

	return 0;
} 

