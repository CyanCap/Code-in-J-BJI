#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 100
#define INCREMENT 10

typedef int ElemType;
typedef int Status;

typedef struct
{
    ElemType *base;
    ElemType *top;
    int size;
} STACK;

Status InitStack(STACK &);
Status DestroyStack(STACK &);
Status ClearStack(STACK &);
Status StackEmpty(STACK);
int StackLength(STACK);
Status GetTop(STACK, ElemType &);
Status Push(STACK &, ElemType);
Status Pop(STACK &, ElemType &);

int main()
{
    return 0;
}

Status InitStack(STACK &S)
{
    S.base = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    if(!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.size = MAXSIZE;
    return OK;
}

Status DestroyStack(STACK &S)
{
    ClearStack(S);
    free(&S);
    return OK;
}

Status ClearStack(STACK &S)
{
    *S.top = -1;
    return OK;
}

Status StackEmpty(STACK S)
{
    if(S.top!=0)
        return TRUE;

    return FALSE;
}

int StackLength(STACK S)
{
    return S.size;
}

Status GetTop(STACK S, ElemType &e)
{
    if(S.top==S.base)
        return ERROR;

    e = *(S.top) - 1;
    return OK;
}

Status Push(STACK &S, ElemType e)
{
    if(S.top-S.base>=S.size)
    {
        S.base = (ElemType *)realloc(S.base, (S.size + INCREMENT) + sizeof(ElemType));
        if(!S.base)
            exit(OVERFLOW);

        S.top = S.base + S.size;
        S.size += INCREMENT;
    }
    *S.top++ = e;
    return OK;
}

Status Pop(STACK &S, ElemType &e)
{
    if(S.top==S.base)
        return ERROR;

    e = *--S.top;
    return OK;
}
