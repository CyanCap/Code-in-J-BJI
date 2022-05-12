#include<stdio.h>
#define C 10
int main()
{
	int A[10],B[10][2];
	int i,j,t;
	for(i=0;i<10;i++)
		scanf("%d",&A[i]);
		
	for(i=0;i<10;i++)
	{
		B[i][0]=A[i];
	}

	for(i=0;i<(C/2);i++)
	{
		t=A[i];
		A[i]=A[C-1-i];
		A[C-1-i]=t;
	}

		for(i=0;i<10;i++)
	{
		B[i][1]=A[i];
	}

	for(i=0;i<10;i++)
		{
			for(j=0;j<2;j++)
			{
				printf("%d",B[i][j]);
			}
		printf("\n");
		}

	return 0;
}
