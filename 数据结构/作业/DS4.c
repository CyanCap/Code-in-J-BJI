#include<stdio.h>
#include<stdlib.h>

// #define MAXSIZE 100

typedef int ElemType;

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
        scanf("%d", &rec->data);
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
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int InsertFirst(NODE *header,ElemType newdata)
{
    NODE *newrec;
    newrec = (NODE *)malloc(sizeof(NODE));
    newrec->data = newdata;
    newrec->next = header->next;
    header->next = newrec;
    return 0;
}

int InsertLast(NODE *header, ElemType newdata)
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    if(newnode==NULL)
        return -1;
    newnode->data = newdata;
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

int InsertMiddle(NODE *header,int i,ElemType newdata)
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    if(newnode==NULL)
        return -1;
    else
    {
        NODE *ptr = header->next;
        for (int j = 1; j < i-1;j++)
            ptr = ptr->next;
        newnode->data = newdata;
        newnode->next = ptr->next;
        ptr->next = newnode;
        return 0;
    }
    return 1;
}

NODE *DeletebyValue(NODE *header,ElemType x)
{
    NODE *ptr1 = header;
    NODE *ptr = ptr1->next;
    if(header->next==NULL)
        return NULL;
    while(ptr!=NULL)
    {
        if(ptr->data!=x)
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

NODE *SearchByValue(NODE *header,ElemType x)
{
    NODE *ptr = header->next;
    while(ptr!=NULL)
    {
        if(ptr->data==x)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

NODE *CopyLL(NODE *header)
{
    NODE *ptr = header, *newheader, *ptr1;
    NODE *newnode;
    newheader = (NODE *)malloc(sizeof(NODE));
    ptr1 = newheader;
    ptr1->data = NULL;
    while(ptr!=NULL)
    {
        newnode = (NODE *)malloc(sizeof(NODE));
        newnode->data = ptr->data;
        ptr1->next = newnode;
        newnode->next = NULL;
        ptr1 = newnode;
        ptr = ptr->next;
    }
    newheader->data = NULL;

    return newheader;
}

void ReverseList(NODE *head) 
{
    NODE* pre = NULL;
    NODE* curr = head->next;
    NODE* next;
    if (head == NULL || head->next == NULL) 
        return;
    while(curr)
    {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    head->next = pre;
}

int main()
{
    NODE *list;
    list = CreateLL(3);
    DisplayLL(list);
    // printf("%d", list->data);
    ReverseList(list);
    DisplayLL(list);

    return 0;
}