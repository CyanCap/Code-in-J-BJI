#include<bits/stdc++.h>
using namespace std;


struct tt
{
	char name[20];
	char phone[20];
	struct tt *next;
};
int main()
{
	struct tt t1;
	struct tt t2;
	struct tt t3;
	struct tt *first;

	first = &t1;
	t1.next = &t2;
	t2.next = &t3;
}


// #include<string>    //使用C++分格的字符串需要使用这个头文件
// int main()
// {
// 	//1.创建 bool 数据类型
// 	bool flag = true; //true 代表真
// 	cout << flag << endl;
// 	bool flag1 = false;
// 	cout << flag1 << endl;
// 	//本质上 1 代表真； 0 代表假

// 	//2.查看 bool 数据类型所占空间
// 	cout << "bool类型所占用的内存空间： " << flag << " 字节" << endl;
// 	cout << sizeof(bool) << endl;

// 	return 0;
// }


// struct NR
// {
// 	char name[30];
// 	struct NR *nA;
// };
// struct NR *fr;

// int main()
// {
// 	void ri(),display();
// 	fr=NULL;
// 	ri();
// 	display();
// 	return 0;
// }

// void ri()
// {
// 	char name[30];
// 	void insert(char *name);
// 	while(1)
// 	{
// 		cin>>name;
// 		if(strcmp(name,"x")==0)	break;
// 		insert(name);
// 	}
// }

// void insert(char *name)
// {
// 	struct NR *lL(char *);
// 	struct NR *na,*here;
	
// 	na=(struct NR *)malloc (sizeof(struct NR));
// 	if(na==(struct NR *)NULL)
// 	{
// 		cout<<"Could not allocate the requested space"<<endl;
// 		exit(1);
// 	}
// 	if(fr==NULL)
// 	{
// 		na->nA=NULL;
// 		fr=na;
// 	}
// 	else if(strcmp(name,fr->name)<0)
// 	{
// 		na->nA=fr;
// 		fr=na;
// 	}
// 	else
// 	{
// 		here=lL(name);
// 		na->nA=here->nA;
// 		here->nA=na;
// 	}
// 	strcpy(na->name,name);
// }
// struct NR *lL(char *name)
// {
// 	struct NR *one,*two;
// 	one=fr;
// 	two=one->nA;
// 	if(two==NULL)	return(one);
// 	while(1)
// 	{
// 		if(strcmp(name,two->name)<0)	break;
// 		else if(two->nA==NULL)
// 		{
// 			one=two;
// 			break;
// 		}
// 		else
// 		{
// 			one=two;
// 			two=one->nA; 
// 		}
// 	 }
// 	return(one);
// }
// void display(){
// 	struct NR *c;
	
// 	c=fr;
// 	cout<<"The names currently in the list, in alphabetical"<<endl<<"norder, are:"<<endl;
// 	while(c!=NULL)
// 	{
// 		cout<<c->name;
// 		c=c->nA;
// 	}
// }

// #define MAXCHARS 30
// #define DEBUG 0

// struct NameRec
// {
// 	char name[MAXCHARS];
// 	struct NamRec *priorAddr;
// };
// struct NameRec *tosp;

// int main()
// {
// 	void readPush()
// 	{
// 		char name[MAXCHARS];
// 		void push(char *);
		
// 		printf("Enter as many names as you wish, one per line\nTo stop entering names, enter a single x\n");
// 		while(1)
// 		{
// 			printf("Enter a name:	");
// 			gets(name);
// 			if(strcmp(name,"x")==0)	break;
			
// 			push(name);
// 		}
// 	}
	
// 	void popShow()
// 	{
// 		char name[MAXCHARS];
// 		void pop(char *);
		
// 		printf("\nThe names popped from the stack are:\n");
// 		while(tosp!=NULL)
// 		{
// 			pop(name);
// 			printf("%s\n",name);
// 		}
// 	}
	
// 	void push(char *name)
// 	{
// 		struct NameRec *newaddr;
		
// 		if(DEBUG)	printf("Before the push the address in tosp is %p",tosp);
		
// 		newaddr=(struct NameRec *)malloc(sizeof(struct NameRec));
// 		if(newaddr==(struct NameRec *)NULL)
// 		{
// 			printf("\nFailed to allocate memory for theis structure\n");
// 			exit(1);
// 		}
		
// 		strcpy(newaddr->name,name);
// 		newaddr->priorAddr=tosp;
// 		tosp=newaddr;
		
// 		if(DEBUG)	printf("\n	After the push the address in tosp is %p\n",tosp);
// 	}
	
// 	void pop(char *name)
// 	{
// 		struct NameRec *tempAddr;
		
// 		if(DEBUG)	printf("Before the pop the address in tosp is %p\n",tosp);
		
// 		strcpy(name,tosp->name);
// 		tempAddr=tosp->priorAddr;
// 		free(tosp);
// 		tosp=tempAddr;
		
// 		if(DEBUG)	printf("	After the pop the address in tosp is %p\n",tosp);
// 	}
	
	
// 	tosp=NULL;
// 	readPush();
// 	popShow();
	
// 	return 0;
// }


// int main()
// {
// 	int numgrades,i;
// 	int *grades;
	
// 	printf("\nEnter the number of grades to be processed:	");
// 	scanf("%d",&numgrades);
	
// 	grades=(int *) malloc(numgrades * sizeof(int));
	
// 	if(grades==(int *)NULL)
// 	{
// 		printf("\nFailed to allocate grades array\n");
// 		exit(1);
// 	}
	
// 	for(i=0;i<numgrades;i++)
// 	{
// 		printf("	Enter a grade:	");
// 		scanf("%d",&grades[i]);
// 	}
	
// 	printf("\nAn array was created for %d integers",numgrades);
// 	printf("\nThe values stored in the array are:\n");
	
// 	for(i=0;i<numgrades;i++)	printf(" %d\n",grades[i]);
	
// 	return 0;
// }
