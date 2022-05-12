#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXCHARS 40
#define TRUE 1
#define FALSE 0
int isvalidInt(char val[])
{
	int start=0,i,valid=TRUE,sign=FALSE;
	
	if(val[0]=='-'||val[0]=='+')
	{
		sign=TRUE;
		start=1;
	}
	if(sign==TRUE&&val[1]=='\0')	valid=FALSE;
	i=start;
	while(valid==TRUE&&val[i]!='\0')
	{
		if(val[i]<'0'||val[i]>'9')	valid=FALSE;
		i++;
	}
	return valid;
}
int main()
{
	char value[MAXCHARS];
	int number;
	
	printf("Enter an integer:\n");
	gets(value);
	
	if(isvalidInt(value)==TRUE)
	{
		number=atoi(value);
		printf("The number you entered is %d\n",number);
	}
	else	printf("The number you entered is not a valid integer.\n");
	
	return 0;
}




//int main()
//{
//	#define MAXELS 20
//	char test[MAXELS]="1234";
//	int num;
//	double dnum;
//	
//	num=atoi(test);
//	printf("The string %s as an integer number is %d\n",test,num);
//	printf("This number divided by 3 is: %d\n",num/3);
//	
//	strcat(test,".96");
//	
//	dnum=atof(test);
//	printf("\nThe string %s as a double number is: %f\n",test,dnum);
//	printf("This number divided by 3 is: %f\n",dnum/3);
//	
//	return 0;
//}

//void convertToUpper(char message[])
//	{
//		int i;
//		for(i=0;message[i]!='\0';i++)	message[i]=toupper(message[i]);
//	}
//int main()
//{
//	#define MAXCHARS 100
//	char message[MAXCHARS];
//	
//	printf("\nType in any sequence of characters:\n");
//	gets(message);
//	
//	convertToUpper(message);
//	
//	printf("The characters just entered, in uppercase are:\n%s\n",message);
//	return 0;
//}

//int main()
//{
//	#define MAXELS 50
//	char string1[MAXELS]="Hello",string2[MAXELS]="Hello there";
//	int n;
//	
//	n=strcmp(string1,string2);
//	
//	if(n<0)	printf("%s is less than %s\n\n",string1, string2);
//	else if(n==0)	printf("%s is equal to %s\n\n",string1,string2);
//	else	printf("%s is greater than %s\n\n",string1,string2);
//	
//	printf("The length of string1 is %d characters\n",strlen(string1));
//	printf("The length of string2 is %d characters\n",strlen(string2));
//	
//	strcat(string1," there World");
//	
//	printf("After concatenation, string1 contains the string value\n%s\n",string1);
//	printf("The length of this string is %d characters\n\n",strlen(string1));
//	printf("Type in a sequence of characters for string2:\n");
//	gets(string2);
//	
//	strcpy(string1,string2);
//	
//	printf("After copying string2 to string1 the string value in string1 is:\n%s\n",string1);
//	printf("The length of this string is %d characters\n\n",strlen(string1));
//	printf("\nThe starting address of the string1 string is:%d\n",(void *) string1);
//	
//	return 0;
//}

//int main()
//{
//	#define LSIZE 81
//	char message[LSIZE];
//	char c;
//	int i;
//	printf("Enter a string:\n");
//	i=0;
//	while(i<(LSIZE-1)&&(c=getchar())!='\n')
//	{
//		message[i]=c;
//		i++;
//	}
//	message[i]='\0';
//	printf("The string just entered is:\n");
//	puts(message);
//	
//	return 0;
//}

//void strcopy(char string1[],char string2[])
//{
//	int i=0;
//	while(string2[i]!='\0')
//	{
//		string1[i]=string2[i];
//		i++;
//	}
//	string1[i]='\0';
//	return;
//}
//
//int main()
//{
//	#define LSIZE 81
//	char message[LSIZE],newMessage[LSIZE];
//	
//	printf("Enter a sentence:");
//	gets(message);
//	puts(message);
//	puts(newMessage);
//	strcopy(newMessage,message);
//	puts(message);
//	puts(newMessage);
//	
//	return 0;
//}
//

//int main()
//{
//	#define MSIZE 81
//	char message[MSIZE];
//	
//	printf("Enter a string:\n");
//	gets(message);
//	printf("The string just entered is:\n");
//	puts(message);
//	
//	return 0;
//}
