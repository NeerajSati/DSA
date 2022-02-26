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

bool equalSum(int val[], int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=val[i];
    }
    if(sum%2!=0){
        return false;
    }
    else if(sum%2 == 0){
        subsetSum(sum/2,val,n);
    }
}

int main()
{
    int val[] = { 1,5,11,5 };
    int n = sizeof(val) / sizeof(val[0]);
     
    cout << equalSum(val, n);
     
    return 0;
}
 
