#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct stu
{
    char name[50] = "0";
    char phone[50] = "0";
    char id[50] = "0";
} ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int len;
} SeqList;

int ListEmpty_sq(SeqList L)
{
    if(L.len == 0)
        return 0;

    return 1;
}

int ListFull_sq(SeqList L)
{
    if(L.len == MAXSIZE-1)
        return 1;

    return 0;
}

int InitList_sq(SeqList *L)
{
    (*L).len = 0;
    return 0; // Success 
}

int ListInsert_sq(SeqList *L, int i, ElemType e)
{
    int j;
    if(i < 1 || i > (*L).len + 1)
        return -1; 
    if(1 == ListFull_sq(*L))
        return -2; 
    for(j = (*L).len; j >= i; j--)
        (*L).data[j] = (*L).data[j - 1];
    (*L).data[i - 1] = e;
    (*L).len++; 
    return 0; 
}

int ListDelete_sq(SeqList *L, int i, ElemType *e)
{
    int j;
    if(i < 1 || i > (*L).len)
        return -1; 
    if(1 == ListEmpty_sq(*L))
        return -2; 
    *e = (*L).data[i - 1]; 
    for(j = i + 1; j <= (*L).len; j++)
        (*L).data[j - 2] = (*L).data[j - 1]; 
    (*L).len--; 
    return 0; 
}

void ListPrint(SeqList L)
{
    int i;
    for (i = 0; i < L.len; i++)
        // printf("%d", L.data);
    {
        printf("\n\nStudent %d name is: %s\n", i + 1, L.data[i].name);
        printf("Student %d phone is: %s\n", i + 1, L.data[i].phone);
        printf("Student %d id is: %s\n", i + 1, L.data[i].id);
    }
}

int main()
{
    SeqList list;
    InitList_sq(&list);
    ElemType student;
    int num = 0, i = 0;

    printf("How many students do you want to store:");
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        printf("\nName of student %d:", i + 1);
        scanf("%s", &student.name);
        printf("\nPhone of student %d:", i + 1);
        scanf("%s", &student.phone);
        printf("\nId of student %d:", i + 1);
        scanf("%s", &student.id);
        ListDelete_sq(&list, i + 1, &student);
        ListInsert_sq(&list, i + 1, student);
        ListPrint(list);
    }
    ListPrint(list);
    return 0;
}