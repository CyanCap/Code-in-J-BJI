#include<stdio.h>
int t1(void);
int t2(void);
int t3(void);
int main()
{
	int s;
	printf("What task do you want to finish?");
	printf("\n    1 for task1\n    2 for task2\n    3 for task3\n");
	scanf("%d", &s);
	switch(s)
	{
		case 1:
			t1();
			printf("Finished.\n");
			break;
		case 2:
			t2();
			printf("Finished.\n");
			break;
		case 3:
			t3();
			break;
		default:printf("Error\n");

	}
    return 0;
}

int t1(void)
{
	double n1, n2, n3;
	printf("Please input 3 values:\n");
	scanf("%lf%lf%lf", &n1, &n2, &n3);
	printf("The values are %f, %f, %f.\n", n1, n2, n3);
}

int t2(void)
{
	double m1, m2, m3, t;
	printf("Please input 3 values to compare them:\n");
	scanf("%lf%lf%lf", &m1, &m2, &m3);
	if(m1 >= m2)
	{
		t=m1;
		m1=m2;
		m2=t;
	}
	if(m1 >= m3)
	{
		t=m1;
		m1=m3;
		m3=t;
	}
	if(m2 >= m3)
	{
		t=m2;
		m2=m3;
		m3=t;
	}
	printf("The ascending order is %f, %f, %f.\n", m1, m2, m3);
	printf("The descending order is %f, %f, %f.\n", m3, m2, m1);
}

int t3(void)
{
	char letter;
	int a, p, c, sum;
	printf("Please select a fruit:\n(A for Apple, B for Banana, O for Orange)\n");
	scanf("%c", &letter);
	letter=getchar();
	switch(letter)
	{
	case 'A':
		printf("Input 3 values for the amount of selected fruit, price of each fruit, and customer's money amount for shopping.\n");
		scanf("%d%d%d", &a, &p, &c);
		sum = a*p;
		if(sum > c)
		{
		    printf("You choose %d'Apple', RMB %d per apple, and you have RMB %d which is not enough for shopping.\n", a, p, c);
		}
		else
		{
			printf("You choose %d'Apple', RMB %d per apple, and you have RMB %d which is enough for shopping.\n", a, p, c);
		}
		printf("Finished.\n");
		break;
	case 'B':
		printf("Input 3 values for the amount of selected fruit, price of each fruit, and customer's money amount for shopping.\n");
		scanf("%d%d%d", &a, &p, &c);
		sum = a*p;
		if(sum > c)
		{
		    printf("You choose %d'Banana', RMB %d per banana, and you have RMB %d which is not enough for shopping.\n", a, p, c);
		}
		else
		{
			printf("You choose %d'Banana', RMB %d per banana, and you have RMB %d which is enough for shopping.\n", a, p, c);
		}
		printf("Finished.\n");
		break;
	case 'O':
		printf("Input 3 values for the amount of selected fruit, price of each fruit, and customer's money amount for shopping.\n");
		scanf("%d%d%d", &a, &p, &c);
		sum = a*p;
		if(sum > c)
		{
		    printf("You choose %d'Orange', RMB %d per orange, and you have RMB %d which is not enough for shopping.\n", a, p, c);
		}
		else
		{
			printf("You choose %d'Orange', RMB %d per orange, and you have RMB %d which is enough for shopping.\n", a, p, c);
		}
		printf("Finished.\n");
		break;
	default:printf("Error\n");
    }
}
