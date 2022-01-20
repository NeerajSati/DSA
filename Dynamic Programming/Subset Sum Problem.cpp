#include <bits/stdc++.h>
using namespace std;

bool subsetSum (int sum, int val[], int n)
{
    int i, j;
    bool mat[n+1][sum+1];
    
    for (int i = 0; i <= n; i++)
        mat[i][0] = true;
        
    for (int i = 1; i <= sum; i++)
        mat[0][i] = false;
        
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= sum; j++)
        {
            if (val[i - 1] <= j)
                mat[i][j] = mat[i - 1][j - val[i - 1]] || mat[i - 1][j];
            else
                mat[i][j] = mat[i - 1][j];
        }
    }
    return mat[n][sum];
}

int main()
{
    int val[] = { 2,3,7,8,10 };
    int sum = 6;
    int n = sizeof(val) / sizeof(val[0]);
     
    cout << subsetSum(sum, val, n);
     
    return 0;
}
 