#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
long long dp[51][51] = {};
int n, m, x, y, i, j;
int main()
{
    dp[0][0] = 1;
    dp[1][1] = 1;
    for (i = 2; i <= 50;i++)
        for (j = 1; j <= i;j++)
            for (x = 0; x <= i - 1;x++)
                for (y = 0; y <= j;y++)
                    dp[i][j] = (dp[i][j] + dp[x][y] * dp[i - x - 1][j - y]) % mod;
    while(cin>>n>>m)
    {
        cout << dp[n][m] << endl;
    }
    return 0;
}



// #define PrintExpr(x) (printf("%s = %d\n", #x, (x)))
// int main(int argc, char **argv)
// {
//     PrintExpr(2-3+2);
//     return 0;
// }

// main() 
// {
//  unsigned int a = 60; /* 60 = 0011 1100 */
//  unsigned int b = 13; /* 13 = 0000 1101 */
//  int c = 0;
//  c = a & b; /* 12 = 0000 1100 */
//  printf("Line 1 - Value of c is %d\n", c );
//  c = a | b; /* 61 = 0011 1101 */
//  printf("Line 2 - Value of c is %d\n", c );
//  c = a ^ b; /* 49 = 0011 0001 */
//  printf("Line 3 - Value of c is %d\n", c );
//  c = ~a; /*-61 = 1100 0011 */
//  printf("Line 4 - Value of c is %d\n", c );
//  c = a << 2; /* 240 = 1111 0000 */
//  printf("Line 5 - Value of c is %d\n", c );
//  c = a >> 2; /* 15 = 0000 1111 */
//  printf("Line 6 - Value of c is %d\n", c );
// }