#include<stdio.h>
int main()
{
	int j=0;
	int choices[20];
	int i=0;
	do
	{
		scanf("%f",&choices[i]);
		i++;
	}while(getchar() !='\n');
	printf("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n");
	for(j=0;j<5;j++)
	{
		if(choices[j]==0)
			break;
		else
		{
			switch(choices[j])
			{
				case 1:printf("price=3.00\n");break;
				case 2:printf("price = 2.50\n"); break;
				case 3:printf("price = 4.10\n"); break;
				case 4:printf("price = 10.20\n"); break;
				default:printf("price = 0.00\n");break;
			}
		} 
	}
	return 0;
}
