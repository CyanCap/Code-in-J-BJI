#include<bits/stdc++.h>

using namespace std;

//#define MAX 109
//int i=0,t=1;
//int num[MAX];
//int t1=0,t5=0,t10=0;
//
//int main()
//{
//	cin>>t;
//	for(i=0;i<t;i++)
//	{
//		cin>>num[i];
//		if(num[i]==1)	t1++;
//		if(num[i]==5)	t5++;
//		if(num[i]==10)	t10++;
//	}
//	cout<<t1<<' '<<t5<<' '<<t10;
//	return 0;
//}

//union Node{
//    int a;
//    char c;
//}Obj;
// 
//int main(int argc, char *argv[])
//{
//    Obj.a = 1;
//    if(Obj.c == 1)
//        cout<<"Little"<<endl;
//    else cout<<"Big"<<endl;
//    return 0;
//}


#define MAX 1009
struct student
{
	string id, name, courses;
};

// int i, t;
// int main()
// {
// 	struct student imf[MAX];
// 	struct student *pt;
// 	pt = &imf[0];
// 	cout << "How many students do you want to enter?" << endl;
// 	cin >> t;

// 	for(i=0;i<t;i++)
// 	{
// 		cout << "Enter the id, name and course:" << endl;
// 		cin >> (pt + i)->id >> (pt + i)->name >> (pt + i)->courses;
// 	}
	
// 	for(i=0;i<t;i++)
// 	{
// 		cout << "The output are:" << endl;
// 		cout << (pt + i)->id << endl
// 			 << (pt + i)->name << endl
// 			 << (pt + i)->courses << endl;
// 	}

int main()
{
	int i, t;
	struct student imf[MAX];
	struct student *pt;
	pt = &imf[0];
	printf("How many students do you want to enter?\n");
	scanf("%d", &t);
	for (i = 0; i < t;i++)
	{
		printf("Enter the id, name and course:\n");
		scanf("%s", &(pt + i)->id);
		scanf("%s", &(pt + i)->name);
		scanf("%s", &(pt + i)->courses);
	}
	for (i = 0; i < t;i++)
	{
		printf("The output are:\n%s\n%s\n%s\n", &(pt + i)->id, &(pt + i)->name, &(pt + i)->courses);
	}

	//	for(i=0;i<t;i++)
	//	{
	//		cin>>imf[i].id>>imf[i].name>>imf[i].courses;
	//	}
	//	for(i=0;i<t;i++)
	//	{
	//		cout<<imf[i].id<<imf[i].name<<imf[i].courses<<endl;
	//	}

	return 0;
}

//double calcNet(struct Employee *temp)
//{
//	return(temp->payRate * temp->hours);
//}
//
//int main()
//{
//	struct Employee emp={6787,8.93,40.5};
//	double netPay;
//	
//	netPay=calcNet(&emp);
//	printf("The net pay of employee %d is $%6.2f\n",emp.idNum,netPay);
//	
//	return 0;
//}

//#define NUMRECS 5 
//struct PayRecord
//{
//	int id;
//	char name[20];
//	double rate;
//};
//
//int main()
//{
//	struct PayRecord emp[10];
//	return 0;
//}

//int main ()
//{
//	int i=0;
//	employee[2].id=2;
////	employee[3].name='C';
//	employee[1].rate=.99;
//	
//	for(i=0;i<5;i++)
//	{
//		cout<<employee[i].id;a
//		cout<<employee[i].rate<<endl;
//	}
//	return 0;
//}

//int main()
//{
//	int i;
//	struct PayRecord employee[NUMRECS]={
//		{32479,"Abrams, B.",6.72},{33623,"Bohm, P.",7.54},
//		{34145,"Donaldson, S.",5.56},{35987,"Ernst, T.",5.43},{36203,"Gwodz, K.",8.72}
//	};	
//	
//	for(i=0;i<NUMRECS;i++)	printf("%d %-20s %4.2f\n",employee[i].id,employee[i].name,employee[i].rate);
//	return 0;
//}
