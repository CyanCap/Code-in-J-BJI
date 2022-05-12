#include<bits/stdc++.h>
using namespace std;

struct student
{
	char name[50];
	int age;
};

void display(struct student temp,struct student *pt)
{
	pt=&temp;
	cout<<pt->age<<endl<<pt->name<<endl;
}

int main()
{
	struct student s1={"Cyan",19};
	struct student *pt;
	pt=&s1;
	display(s1,pt);
	return 0;
}
//struct person
//{
// int age;
// float weight;
//};
//int main()
//{
// struct person *personPtr, person1;
// personPtr = &person1;
// printf("Enter age: ");
// scanf("%d", &personPtr->age);
// printf("Enter weight: ");
// scanf("%f", &personPtr->weight);
// printf("Displaying:\n");
// printf("Age: %d\n", personPtr->age);
// printf("weight: %f", personPtr->weight);
// return 0;
//}

//struct StudentData
//{
// char *stu_name;
// int stu_id;
// int stu_age;
//};
//int main()
//{
// /* student is the variable of structure StudentData*/
// struct StudentData student;
// /*Assigning the values of each struct member here*/
// student.stu_name = "Steve";
// student.stu_id = 1234;
// student.stu_age = 30;
// /* Displaying the values of struct members */
// printf("Student Name is: %s", student.stu_name);
// printf("\nStudent Id is: %d", student.stu_id);
// printf("\nStudent Age is: %d", student.stu_age);
// return 0;
//}
