/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m];
        int ans = INT_MIN;
        for(int i = n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i == n-1){
                    dp[i][j] = matrix[i][j] - '0';
                }
                else if(j==m-1){
                    dp[i][j] = matrix[i][j] - '0';
                }
                else if((matrix[i][j] - '0') == 0){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = 1 + min(min(dp[i+1][j],dp[i][j+1]),dp[i+1][j+1]);
                }
                
                if(dp[i][j] > ans)
                    ans = dp[i][j];
            }
        }
        return ans * ans;
    }
};


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n,0),curr(n,0);
        int ans = INT_MIN;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i == m-1 || j== n-1){
                    curr[j] = matrix[i][j] - '0';
                }
                else if(matrix[i][j] - '0' == 0){
                    curr[j] = 0;
                }
                else{
                    curr[j] = 1 + min(curr[j+1], min(prev[j+1],prev[j]));
                }
                
                ans = max(ans,curr[j]);
            }
                fill(prev.begin(), prev.end(), 0);
                swap(prev,curr);
        }
        return ans * ans;
    }
};



class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> curr(n,0);
        int ans = INT_MIN,temp,old;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                temp = curr[j];
                if(i == m-1 || j== n-1){
                    curr[j] = matrix[i][j] - '0';
                }
                else if(matrix[i][j] - '0' == 0){
                    curr[j] = 0;
                }
                else{
                    curr[j] = 1 + min(old, min(curr[j+1],curr[j]));
                }
                ans = max(ans,curr[j]);
                old = temp;
            }
        }
        return ans * ans;
    }
};
