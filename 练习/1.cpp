#include<bits/stdc++.h>
using namespace std;

// bool check(int x)
// {
// 	if(x%4==0)
// 	{
// 		return false;
// 	}
// 	while(x)
// 	{
// 		if(x%10==0)
// 		{
// 			return false;
// 		}
// 		x /= 10;
// 	}
// 	return true;
// }

// int main()
// {
// 	int n, i;
// 	cin >> n;
// 	for (i = 1; i <= n;i++)
// 	{
// 		if(check(i))
// 		{
// 			cout << i << endl;
// 		}
// 	}
// 	return 0;
// }



// bool check(int x){
//     if(x%4==0)    return false;
//     while(x){
//         if(x%10==4)    return false;
//         x/=10;
//     }
//     return true;
// }
// int main(){
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++){
//         if(check(i))    printf("%d\n",i);
//     }
// }

// int main()
// {
//     int a, b, c;
//     cin >> a >> b;
//     cout << "a  b" << endl;
//     cout << "----" << endl;
//     cout << a << "  " << b << endl;
//     a = a ^ b;
//     cout << a << "  " << b << endl;
//     b = b ^ a;
//     cout << a << "  " << b << endl;
//     a = a ^ b;
//     cout << a << "  " << b << endl;

//     return 0;
// }

// int main()
// {
//     int i = 1;
//     cout << "i--" << i << endl;
//     cout << "++i--" << ++i << endl;
//     cout << "i--" << i << endl;
//     cout << "i++--" << i++ << endl;
//     cout << "i--" << i << endl;
//     return 0;
// }

// int main()
// {
// 	string num;    //高精度数num用string类型表示
// 	int num2,i;    // 单精度数num2用整形表示 
// 	cin>>num>>num2;
// 	int len = num.length();
// 	int ans = 0;
// 	for(i = 0;i < len;i++)
// 	{
//         ans = (ans * 10 + num[i] - '0') % num2;
//     }
// 	cout<<ans<<endl;
// 	return 0;
// }

// int main()
// {
//     int num = 0;
//     cin >> num;
//     cout << '0'-num;
//     return 0;
// }


// int main()
// {
//  string a="abcd";
//  cout<<" 强制转换前测试 -1  和  a.length()  的大小比较"<<endl;
//  cout<<" a :   "<<a<<endl;
//  cout<<" a.length()    :   "<<a.length()<<endl;
//  cout<<" int(  a.length() )   :    "<<int ( a.length() )<<endl;
//  if(-1>= a.length() )
//   cout<<"yyyyyyyyyyyyyyyyyyyyy"<<endl;
//  else
//   cout<<"nnnnnnnnnnnnnnnnnnnnn"<<endl;
//  cout<<" 强制转换前测试 -1 和 a.length() 的大小比较"<<endl;
//  if(-1>=int(a.length() ) )
//   cout<<"yyyyyyyyyyyyyyyyyyyyy"<<endl;
//  else
//   cout<<"nnnnnnnnnnnnnnnnnnnnn"<<endl; 
// }
