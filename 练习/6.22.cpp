#include<bits/stdc++.h>
using namespace std;

int b = 6;
void fun1(int *pt)              //函数是fun1(int *)
{
    *pt = 2;
    pt = &b;
}
void fun2(int *&pt)             //函数是fun2(int *&)
{

    pt = &b;
    // *pt = 3;
}
int main()
{
    int a = 5;
    int *p = &a;

    fun1(&a);
    cout << a << endl           //调用时是fun(&a)   输入的是地址 &a
         << *p << endl;         //可以改变 p->a   也就是a也就是*p的值  无法改变指向

    fun2(p);                    //调用时是fun(p)    输入的是一个指针 p
    cout << *p << endl;         //可以改变*p的值    也可以改变p的指向   p->a变为p->b
    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// void fun(int *t1,int *t2,int *&rt)
// {
// 	*t1 += 5;
// 	*t2 += 5;       	
// 	rt = t1;
// 	*rt += 5;
// 	cout << *t1 << endl
// 		 << *t2 << endl
// 		 << *rt << endl;
// }
// int main()
// {
// 	int a = 10, b = 20;
// 	int *p = &a, *q = &b;
// 	fun(p, q, p);
// 	cout << *p << endl
// 		 << *q << endl;
// }