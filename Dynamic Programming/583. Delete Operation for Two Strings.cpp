/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
 

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.
*/
class Solution {
public:
    int minDistance(string text1, string text2) {
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
        return m + n - 2 * mat[m][n];
    }
};
