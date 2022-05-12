#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, a[20];
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> a[i];
    }
}



// int i, j;
// int main()
// {
//     int value[105];
//     int n;
//     double sum;
//     while(cin>>n)
//     {
//         for (i = 0; i < n;i++)
//         {
//             cin >> value[i];
//             sum += value[i];
//         }
//         for (j = 0; j < n;j++)
//         {
//             if(value[j]<sum/n)
//             {
//                 cout << value[j];
//                 cout << " ";
//             }
//         }
//         cout << endl;
//         sum = 0;
//     }
//     return 0;
// }

// int main()
// {
//     int a, b, c;
//     int i, j;
//     cin >> a >> b >> c;
//     for (i = 0; i <= c / a;i++)
//     {
//         if((c-i*a)%b==0)
//         {
//             cout << "Yes";
//             return 0;
//         }
//     }
//     cout << "No";
//     return 0;
// }

// char a;
// int main()
// {
//     int Letters = 0, Digits = 0, Others = 0;
//     while(getchar()!='?')
//     {
//         if((a>='0')&&(a<='9'))
//             Digits++;
//         else if((a>='a')&&(a<='z'))
//             Letters++;
//         else if((a>='A')&&(a<='Z'))
//             Letters++;
//         else
//             Others++;
//     }
//     cout << "Letters=" << Letters << endl;
//     cout << "Digits=" << Digits << endl;
//     cout << "Others=" << Others << endl;
//     return 0;
// }

// int main()
// {
//     cout << "1*1= 1" << endl;
//     cout << "1*2= 2 2*2= 4"<< endl;
//     cout << "1*3= 3 2*3= 6 3*3= 9"<< endl;
//     cout << "1*4= 4 2*4= 8 3*4=12 4*4=16"<< endl;
//     cout << "1*5= 5 2*5=10 3*5=15 4*5=20 5*5=25"<< endl;
//     cout << "1*6= 6 2*6=12 3*6=18 4*6=24 5*6=30 6*6=36"<< endl;
//     cout << "1*7= 7 2*7=14 3*7=21 4*7=28 5*7=35 6*7=42 7*7=49"<< endl;
//     cout << "1*8= 8 2*8=16 3*8=24 4*8=32 5*8=40 6*8=48 7*8=56 8*8=64"<< endl;
//     cout << "1*9= 9 2*9=18 3*9=27 4*9=36 5*9=45 6*9=54 7*9=63 8*9=72 9*9=81"<< endl;
//     return 0;
// }