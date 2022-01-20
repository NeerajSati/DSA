#include <bits/stdc++.h>
using namespace std;

int knapSack(int cap, int wt[], int val[], int n)
{
    int i, j;
    int mat[n+1][cap+1];
    
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= cap; j++)
        {
            if (i == 0 || j == 0)
                mat[i][j] = 0;
            else if (wt[i - 1] <= j)
                mat[i][j] = max(val[i - 1] + mat[i - 1][j - wt[i - 1]], mat[i - 1][j]);
            else
                mat[i][j] = mat[i - 1][j];
        }
    }
    return mat[n][cap];
}
 
int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int cap = 50;
    int n = sizeof(val) / sizeof(val[0]);
     
    cout << knapSack(cap, wt, val, n);
     
    return 0;
}
 