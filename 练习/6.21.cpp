#include<bits/stdc++.h>
using namespace std;

// int main()
// {
//      int a = 10;
//      int *p = &a;
//      int *b = p;
//      int *&c = p;
//      cout << *p << endl;
//      cout << *b << endl;
//      cout << *c << endl;
//      cout << &p << endl;
//      cout << &b << endl;
//      cout << &c << endl;
// }

// void change01(int *q){
// 	int b = 2;
// 	q = &b;
// }
// void change02(int *&q){
// 	int b = 2;
// 	q = &b;
// }
// int main()
// {
// 	printf("change01\n");
// 	int *p,a=1;
// 	p = &a;
// 	printf("%p %d\n", p,*p);
// 	change01(p);
// 	printf("%p %d\n\n\n", p,*p);
//      cout << &p << endl;

//      printf("change02\n");
// 	printf("%p %d\n", p,*p);
// 	change02(p);
// 	printf("%p %d\n", p,*p);
//      cout << &p << endl;
//      return 0;
// }





// int main()
// {
//     int a = 1;
//     int *q;
//     q = &a;
//     cout << *q << endl
//          << q << endl;
//     int *&pt = q;
//     cout << *pt << endl
//          << pt << endl;
//     *pt = 2;
//     cout << *pt << endl
//          << pt << endl;
//     return 0;
// }

// int b = 2;
// void fun(int *&pt)
// {
//      pt = &b;
// }

// int main()
// {
//     int a = 1, *p;
    
//     p = &a;
//     cout << *p << endl
//          << p << endl
//          << &a << endl
//          << &b << endl
//          << &p << endl;
//     fun(p);
//     cout << *p << endl
//          << p << endl
//          << &a << endl       
//          << &b << endl
//          << &p << endl;
//     return 0;
// }



// int i = 0, j = 0;
// bool find(int a[], int m)
// {
//     if(a[i]==m)
//         return false;
//     else
//         return true;
// }
// int main()
// {
//     int n, a[25], m;
//     int num = 0;
//     cin >> n;
//     for (i = 0; i < n;i++)
//     {
//         cin >> a[i];
//     }
//     cin >> m;
//     for (i = 0; i < n;i++)
//     {
//         if(find(a[i], m))
//             cout << a[i];
//     }

//         return 0;
// }