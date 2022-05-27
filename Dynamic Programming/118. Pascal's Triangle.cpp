// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// Example 2:

// Input: numRows = 1
// Output: [[1]]
 

// Constraints:

// 1 <= numRows <= 30

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> dp;
        dp.push_back({1});
        for(int i=1;i<n;i++){
            vector<int> x;
            
            x.push_back(1);
            for(int j=1;j<i;j++){
                x.push_back(dp[i-1][j-1] + dp[i-1][j]);
            }
            x.push_back(1);
            
            dp.push_back(x);
        }
        return dp;
    }
};
