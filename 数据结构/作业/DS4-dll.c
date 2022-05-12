#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef char ElemType;

typedef struct node
{
    ElemType data;
    struct node *llink;
    struct node *rlink;
} NODE;
NODE *S, *P;

NODE *Doubly-LL()
{
    NODE *S = (NODE *)malloc(sizeof(NODE));
    scanf("%s", &S->data);
    S->llink = P->llink;
    S->rlink = P;
    P->llink->rlink = S;
    P->llink=S;
    return header;
}

P = (NODE *)malloc(sizeof(NODE));
P->llink->rlink = P->rlink;
P->rlink->llink = P->llink;
free(P);
