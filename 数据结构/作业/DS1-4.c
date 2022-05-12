#include<stdio.h>
#define MAX 1010
struct stu
{
    int stuID;
    char stuName[50];
    char stuGender[50];
    int stuPhone;
    char stuAddress[50];
}s[MAX];
int main()
{
    int snum = 0, i = 0, j = 0;
    // scanf("%d", &snum);
    // printf("%d", snum);
    while(i!=3)
    {
        printf("\n1 for input.\n2 for output.\n3 to exit.\nPlease enter:\n");
        scanf("%d", &i);
        switch(i)
        {
            case 3:
                break;
            default:
                break;
            case 1:
            {
                printf("Which student:");
                scanf("%d", &j);
                printf("\nEnter seperately:(ID,NAME,GENDER,PHONE,ADDRESS)\n");
                scanf("%d %s %s %d %s", &s[j].stuID, &s[j].stuName, &s[j].stuGender, &s[j].stuPhone, &s[j].stuAddress);
                // printf("%d\n%s\n%s\n%d\n%s\n", s[j].stuID, s[j].stuName, s[j].stuGender, s[j].stuPhone, s[j].stuAddress);
                continue;
            }
            case 2:
            {
                printf("Which student:");
                scanf("%d", &j);
                printf("\n%d\n%s\n%s\n%d\n%s\n", s[j].stuID, s[j].stuName, s[j].stuGender, s[j].stuPhone, s[j].stuAddress);
                continue;
            }
        }
    }
    return 0;
}