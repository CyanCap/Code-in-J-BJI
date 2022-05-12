#include<bits/stdc++.h>
using namespace std;

int main()
{
	char *message2="this is a string";
	printf("\n%s",message2);
	printf("\nbase address is %p\n",message2);
	
	message2="A new message";
	printf("\n%s",message2);
	printf("\nbase address is %p\n",message2);
	
	return 0;
}


//int main()
//{
//	int i;
//	int grade[]={98,87,92,79,85};
//	for(i=0;i<5;i++)	printf("Element %d is %d\n",i, *(grade + i+1));
//	return 0;
//}
