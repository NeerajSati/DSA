/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/
class Solution {
private:
    int lcs(string text1,string text2){
        int m = text1.length(),n = text2.length();
        int mat[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    mat[i][j]=0;
                }
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1] == text2[j-1])
                    mat[i][j] = mat[i-1][j-1] + 1;
                else{
                    mat[i][j] = max(mat[i-1][j] , mat[i][j-1]);
                }
            }
        }
        return mat[m][n];
    }
    int lps(string s){
        string srev = s;
        reverse(srev.begin(),srev.end());
        return lcs(s,srev);
    }
public:
    int minInsertions(string s) {
        return s.length() - lps(s);
    }
};
