#include<stdio.h>
#include<stdlib.h>
struct stu
{
    int stuID;
    char stuName[50];
    char stuGender[50];
    int stuPhone;
    char stuAddress[50];
};
int main()
{
    struct stu *next;
    // struct stu a;
    next = (struct stu *)malloc(sizeof(struct stu));
    // next = &a;
    free(next);
    return 0;
}