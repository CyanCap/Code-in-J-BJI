#include<stdio.h>
#include<stdlib.h>

// #define MAXSIZE 100

typedef struct stu
{
    int id;
    char name[50];
    int phone;
} ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;
} NODE;
// struct node *header;

NODE *CreateLL(int n)
{
    int i;
    NODE *header;
    header = (NODE *)malloc(sizeof(NODE));
    header->next = NULL;
    NODE *rec, *temp = NULL;
    temp = header;
    for (i = 0; i < n;i++)
    {
        rec = (NODE *)malloc(sizeof(NODE));
        scanf("%d %s %d", &rec->data.id,&rec->data.name,&rec->data.phone);
        temp->next = rec;
        temp = rec;
    }
    temp->next = NULL;
    return header;
}

void DisplayLL(NODE *header)
{
    NODE *ptr = header->next;
    while(ptr)
    {
        printf("id:%d\nname:%s\nphone:%d\n\n", ptr->data.id, ptr->data.name, ptr->data.phone);
        ptr = ptr->next;
    }
    printf("\n");
}

int InsertFirst(NODE *header)
{
    NODE *newrec;
    newrec = (NODE *)malloc(sizeof(NODE));
    scanf("%d %s %d", &newrec->data.id,&newrec->data.name,&newrec->data.phone);
    newrec->next = header->next;
    header->next = newrec;
    return 0;
}

int InsertLast(NODE *header)
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    if(newnode==NULL)
        return -1;
    scanf("%d %s %d", &newnode->data.id,&newnode->data.name,&newnode->data.phone);
    newnode->next = NULL;
    if(header->next==NULL)
        return -2;
    else{
        NODE *ptr = header;
        while(ptr->next!=NULL)
            ptr = ptr->next;
        ptr->next = newnode;
        return 0;
    }
    return 1;
}

int InsertMiddle(NODE *header,int i)
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    if(newnode==NULL)
        return -1;
    else
    {
        NODE *ptr = header->next;
        for (int j = 1; j < i-1;j++)
            ptr = ptr->next;
        scanf("%d %s %d", &newnode->data.id,&newnode->data.name,&newnode->data.phone);
        newnode->next = ptr->next;
        ptr->next = newnode;
        return 0;
    }
    return 1;
}

NODE *DeletebyValue(NODE *header,int x)
{
    NODE *ptr1 = header;
    NODE *ptr = ptr1->next;
    if(header->next==NULL)
        return NULL;
    while(ptr!=NULL)
    {
        if(ptr->data.id!=x)
        {    
            ptr1 = ptr;
            ptr = ptr->next;
        }
        else
        {
            ptr1->next = ptr->next;
            free(ptr);
            ptr = ptr1->next;
        }
    }
    return header;
}

NODE *SearchByValue(NODE *header,int x)
{
    NODE *ptr = header->next;
    while(ptr!=NULL)
    {
        if(ptr->data.id==x)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

int main()
{  
    NODE *list;
    list = CreateLL(2);
    DisplayLL(list);
    InsertMiddle(list, 2);
    DisplayLL(list);
    DeletebyValue(list, 3);
    DisplayLL(list);
    return 0;
}