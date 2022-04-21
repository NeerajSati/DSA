class Solution {
public:
    string printlongestCommonSubsequence(string text1, string text2) {
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
                        mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
                    }      
            }
        }
        int i=m,j=n;
        string ans="";
        while(i>0&&j>0){
            if(text1[i-1]==text2[j-1]){
                ans.push_back(text1[i-1]);
                i--;
                j--;
            }
            else{
                if(mat[i][j-1] > mat[i-1][j])
                    j--;
                else
                    i--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
