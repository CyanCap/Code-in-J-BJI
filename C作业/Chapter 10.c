#include<stdio.h>
#include<stdlib.h>
#define MAXN 100010
int records;
char id[MAXN],name[MAXN];
double mark[MAXN];
int main()
{
	int i;
	FILE *fp;
	fp=fopen("test.txt","wt+");
	
//	if(fp==NULL)
//	{
//		printf("ERROR!");
//		exit(1);
//	}

	printf("Enter number of records:\n");
	scanf("%d",&records);
	for(i=1;i<=records;i++)
	{
		printf("\nEnter record %d:\n",i);
		getchar();
		printf("Enter student ID: ");
		scanf("%s",id);
		printf("Enter student name: ");
		scanf("%s",name);
		printf("Enter mark: ");
		scanf("%lf",&mark[i]);
		fprintf(fp,"ID: %s Name: %s Mark: %f\n",id,name,((mark[i]+40)*3.14));  //Output = (mark+40)*3.14
	}
	fclose(fp);
	return 0;
} 
