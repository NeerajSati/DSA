class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(),n=text2.length();
        int mat[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0)
                    mat[i][j] = 0;
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                    if(text1[i-1]==text2[j-1])
                        mat[i][j] = 1 + mat[i-1][j-1];
                    else{
                        mat[i][j] = 0;
                    }      
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                    if(mat[i][j]>ans)
                        ans = mat[i][j];
            }
        }
        return ans;
    }
};
