#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
void find(int[], int[]);
int q, r;
int a[MAX], b[MAX];
int n = 1;
int main()
{
    cin >> a[1] >> b[1];
    if(a[1]>=b[1])
    {
        for (n = 1; n < MAX; n++)
        {
            find(a, b);
            if(r==0)
            {   
                cout << b[n] << endl;
                break;
            }
            else
            {
                a[n + 1] = b[n];
                b[n + 1] = r;
                // n++;
            }
        }
    }
    else
    {
        int temp;
        temp = a[1];
        a[1] = b[1];
        b[1] = temp;
        for (n = 1; n < MAX;n++)
        {
            find(a, b);
            if(r==0)
            {   
                cout << b[n] << endl;
                break;
            }
            else
            {
                a[n + 1] = b[n];
                b[n + 1] = r;
                // n++;
            }
        }
    }


    return 0;
}

void find(int x[MAX],int y[MAX])
{
    // int q[MAX], r[MAX];
    for (q = 1; q <= MAX;q++)
        for (r = 1; r <= MAX;r++)
        {
            for (n = 1; n <= MAX;n++)
            {
                if(x[n]==q * y[n] +r)
                    break;
                else
                    continue;
            }
        }
}