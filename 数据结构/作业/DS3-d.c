#include<stdio.h>
#include<stdlib.h>

#define INCSIZE 10
#define MAXSIZE 100
// SeqList_d L;

typedef struct stu
{
    char name[50] = "0";
    char phone[50] = "0";
    char id[50] = "0";
} ElemType;

typedef struct
{
    ElemType *data;
    int len;
    int listsize;
} SeqList_d;

int ListEmpty_sq_d(SeqList_d L)
{
    if(L.len == 0)
        return 0;

    return 1;
}

int ListFull_sq_d(SeqList_d L)
{
    if(L.len == MAXSIZE-1)
        return 1;

    return 0;
}

int InitList_sq_d(SeqList_d *L)
{
    (*L).data = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    (*L).len = 0;
    if(NULL==(*L).data)
        return -1;
    (*L).listsize = MAXSIZE;
    (*L).len = 0;
    return 0; // Success 
}

int ListInsert_sq_d(SeqList_d *L, int i, ElemType e)
{
    int j, tempsize;
    ElemType *p = NULL;
    if(i < 1 || i > (*L).len + 1)
        return -1; 
    if(1 == ListFull_sq_d(*L))
    {
        tempsize = (*L).listsize + INCSIZE;
        p = (ElemType *)realloc((*L).data, tempsize * sizeof(ElemType));
        if(NULL==p)
            return -2;
        (*L).data = p;
        (*L).listsize = tempsize;
    } 
    for(j = (*L).len; j >= i; j--)
        (*L).data[j] = (*L).data[j-1];
    (*L).data[i - 1] = e;
    (*L).len++; 
    return 0; 
}

int ListDelete_sq_d(SeqList_d *L, int i, ElemType *e)
{
    int j;
    if(i < 1 || i > (*L).len)
        return -1; 
    if(1 == ListEmpty_sq_d(*L))
        return -2; 
    *e = (*L).data[i - 1]; 
    for(j = i + 1; j <= (*L).len; j++)
        (*L).data[j - 2] = (*L).data[j - 1]; 
    (*L).len--; 
    return 0; 
}

int ListDestroy_d(SeqList_d *L)
{
    free((*L).data);
    return 1;
}

void ListPrint_d(SeqList_d L)
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
    SeqList_d list;
    InitList_sq_d(&list);
    ElemType student;

    ListDestroy_d(&list);
    return 0;
}