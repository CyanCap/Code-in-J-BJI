#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFASIBLE -1
#define OVERFLOW -2

#define MAXSIZE 100
#define INCREMENT 10
#define MAXBUFFER 10

typedef double ElemType;
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

Status CalPost(char *);

// Status CalPost(STACK, char[]);

int main()
{
    char postexp[] = "1 3 - 5 +";
    CalPost(postexp);
    // printf("%d", calpost(postexp));

    // STACK S;
    // InitStack(S);
    // char exp[] = "1 3+4-";
    // CalPost(S, exp);

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
    if(S.top==S.base)
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

// Status CalPost(STACK S,char str[])
// {
//     ElemType number, a, b, result;

//     char arr[MAXBUFFER];
//     int i=0,j=0;
  
//     InitStack(S);
  
//     while(str[i]!='\0')
//     {
//         while(isdigit(str[i])||str[i]=='.') //过滤数字
//         {
//             arr[j++]=str[i++];
//             arr[j]='\0';
  
//             if( j >= MAXBUFFER )
//                 {
//                     printf("TOO LARGE\n");
//                     return ERROR;
//                 }
//             if(str[i]==' ')
//             {
//                 number=atof(arr); //利用atof函数将数字字符转化为double型数据
//                 Push(S,number); //将转换的数进行压栈
//                 j=0;
//                 break;
//             }
//         }
  
//         switch(str[i])
//         {
//             case '+':
//                 Pop(S,a);
//                 Pop(S,b);
//                 Push(S,a+b);
//                 break;
//             case '-':
//                 Pop(S,a);
//                 Pop(S,b);
//                 Push(S,b-a);
//                 break;
//             case '*':
//                 Pop(S,a);
//                 Pop(S,b);
//                 Push(S,b*a);
//                 break;
//             case '/':
//                 Pop(S,a);
//                 Pop(S,b);
//                 if(a == 0)
//                 {
//                     printf("输入出错，分母为零！\n");
//                     return ERROR;
//                 }
//                 Push(S,b/a);
//                 break;
//         }
//         i++; 
//     }
//     Pop(S,result);
//     printf("%lf\n",result);
//     return OK;
// }


Status CalPost(char *exp)
{
    STACK n;
    int i = 1;
    double a, b, c, d, result;

    InitStack(n);

    while(*exp != '\0')
    {
        switch(*exp)
        {
            case '+':
            { 
                Pop(n, a);
                Pop(n, b);
                c = a + b;
                Push(n, c);
                printf("+");
                break;
            }
            case '-':
            {
                Pop(n, a);
                Pop(n, b);
                c = b - a;
                Push(n, c);
                printf("-");
                break;
            }
            case '*':
            { 
                Pop(n, a);
                Pop(n, b);
                c = b * a;
                Push(n, c);
                printf("*");
                break;
            }
            case '/':
            {    
                Pop(n, a);
                Pop(n, b);
                if(a!=0)
                {
                    c = b / a;
                    Push(n, c);
                }else{
                    printf("ERROR\n");
                    return ERROR;
                }
                printf("/");
                break;
            }
            case '^':
            {
                Pop(n, a);
                Pop(n, b);
                if(a!=0)
                {
                    i = 1;
                    c = 1;
                    while(i<=a)
                    {
                        c = c * b;
                        i++;
                    }
                }else if(b!=0)
                    c = 1;
                
                else
                    c = 0;
               
                Push(n, c);
                printf("^");
                break;
            }
            case '!':
            {
                Pop(n, a);
                c = 1;
                i = a;
                while(i!=0)
                {
                    c = c * i;
                    i--;
                }
                Push(n, c);
                printf("!");
                break;
            }
            default:
            {
                d = 0;
                while (*exp >= '0' && *exp <= '9')
                {
                    d = 10 * d + (*exp - '0');
                    exp++;
                }
                Push(n, d);
                printf("d");
            }
        }
        exp++;
    }
    Pop(n, result);
    printf("\n%lf\n", result);

    return OK;
}
