#include <bits/stdc++.h>
using namespace std;

bool mat[100][2000];
void minSubsetSum (int range, int val[], int n)
{
    int i, j;
    for(int i=0;i<=n;i++)
                mat[i][0] = 1;
                
                
    for(int j=1;j<=range;j++)
                mat[0][j] = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=range;j++){
            if(val[i-1] <= j){
                mat[i][j] = mat[i-1][j] || mat[i-1][j - val[i-1]];
            }
            else{
                mat[i][j] = mat[i-1][j];
            }
        }
    }
}

int main()
{
    int val[] = { 4,3,8,7,10 };
    int n = sizeof(val) / sizeof(val[0]);
    int range=0;
    for(int i=0;i<n;i++)
        range+=val[i];
    minSubsetSum(range, val, n);
    cout<<endl<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=range;j++){
            cout<<mat[i][j]<<"  ";
        }
        cout<<endl;
    }
    int ans = INT_MAX;
    vector<int> minA;
    for(int i=0;i<range/2;i++){
        if(mat[n][i]==true){
            minA.push_back(i);
        }
    }
    for(int i=0;i<minA.size();i++){
        ans = min(ans,range - 2 * minA[i]);
    }
    cout<<endl<<ans<<endl;
    return 0;
}
