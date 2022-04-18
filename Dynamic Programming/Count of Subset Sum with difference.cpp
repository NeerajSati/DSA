#include <bits/stdc++.h>
using namespace std;

int subsetSum (int sum, int val[], int n)
{
    int i, j;
    int mat[n+1][sum+1];
    
    for (int i = 0; i <= n; i++)
        mat[i][0] = 1;
        
    for (int i = 1; i <= sum; i++)
        mat[0][i] = 0;
        
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= sum; j++)
        {
            if (val[i - 1] <= j)
                mat[i][j] = mat[i - 1][j - val[i - 1]] + mat[i - 1][j];
            else
                mat[i][j] = mat[i - 1][j];
        }
    }
    return mat[n][sum];
}

int main()
{
    int val[] = { 1,1,2,3 };
    int diff = 1;
    int n = sizeof(val) / sizeof(val[0]);
    //subset1 - subset2 = diff;
    //subset1 + subset2 = sum;
    //subset1 = (diff + sum)/2
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=val[i];
    cout << subsetSum((diff + sum)/2, val, n);
     
    return 0;
}
