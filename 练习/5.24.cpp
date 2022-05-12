#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


int finddif(int [], int [], int );
int n, m,differ;
int i, j;
int m = 100000000;
int a[1009], b[1009];
int main()
{
    cin >> n;
    for (i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for (i = 0; i < m;i++)
    {
        cin >> b[i];
    }
    if(n<m)
    {
        cout << finddif(a, b, n) << endl;
    }
    else
    {
        cout << finddif(a, b, m) << endl;
    }
    return 0;
}

// int finddif(int n[],int m[], int t)
// {
//     int i, j;
//     int d = 0, s;
//     for (i = 0; i < ((n<m) ? (m-n) : (n-m));i++)
//     {
//         d = 0;
//         // d = (n[i] - m[i]) ^ 2;
//         for (j = 0; j < t;j++)
//         {
//             d = d + (n[i] - m[i]) ^ 2;
//         }
//         s = min(m, d);
//     }
//     return s;
// }


// int a, b;
// int main()
// {
//     while(cin>>a>>b)
//     {
//         cout << a + b << endl;
//     }
//     return 0;
// }

// int i, j, n;
// int main()
// {
//     while(cin>>n)
//     {
//         for (i = 0; i < n;i++)
//             {
//                 for (j = 0; j < n- i - 1;j++)
//                     cout << " ";
//                 for (j = 0; j < 2 * i + 1;j++)
//                     cout << "*";
//                 cout << endl;
//             }
//     }
//     return 0;
// }

//  int isPrime_sieve(int n){
// 	int* isPrimes = (int*)malloc(sizeof(int)*(n+1));
// 	int i,j;
// 	int sqrtn = sqrt(n);
 
// 	if(n<=1)
// 		return 0;
 
// 	for(i=2;i<=n;i++){		//初始化都为素数
// 		isPrimes[i] = 1;
// 	}
 
// 	//从2开始，将素数的倍数标记为非素数
// 	//从i的平方开始标记即可，不需要从i*j(且j<i)开始，因为i*j至少在遇到j时已经被标记过了
// 	for(i=2;i<=sqrtn;i+=1){	
		
// 		if(isPrimes[i]==0)	//不是素数，说明i可以分解为两个因子相乘，那么在遇到这两个因子的较小者时，i的倍数已经被标记过
// 			continue;
 
// 		for(j=i*i;j<=n;j+=i){	//j是i的倍数
// 			isPrimes[j] = 0;
// 		}
// 	}
 
// 	return isPrimes[n];
// }

// int main()
// {
//     int n;
//     cin >> n;
//     isPrime_sieve(n);
//     cout << isPrimes << endl;
//     return 0;
// }

// int main()
// {
//     int i=0, j=0, l;
//     int m=0, a[10009];
//     cin >> l;
    
//     for (i = 0; i < l; i++)
//     {
//         scanf("%d", &a[i]);
//     }
    
//     for (i = 0; i < l; i++)
//     {
//         for (j = 0; j < l;j++)
//         {
//             if(a[i]==a[j])
//             {
//                 m++;
//                 a[j] = 0;
//             }
//             else
//                 continue;
//         }
//     }
//     cout << m << endl;

//     return 0;
// }




// string x;
// int main()
// {
//     cin >> x;
//     cout << x;

//     return 0;
// }