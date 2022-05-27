// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
// Example 2:

// Input: triangle = [[-10]]
// Output: -10
 

// Constraints:

// 1 <= triangle.length <= 200
// triangle[0].length == 1
// triangle[i].length == triangle[i - 1].length + 1
// -104 <= triangle[i][j] <= 104
 

// Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?


//n^2
class Solution {
private:
    bool isSafe(vector<vector<int>>& triangle, int i, int j){
        if(i>=triangle.size())
            return false;
        if(j >= triangle[i].size())
            return false;
        
        return true;
    }
    int solve(vector<vector<int>>& triangle, int i, int j,vector<vector<int>> &dp){
        if(dp[i][j] != INT_MIN)
            return dp[i][j];
        int left = 0;
        if(isSafe(triangle,i+1,j)){
            left = solve(triangle,i+1,j,dp);
        }
        int right = 0;
        if(isSafe(triangle,i+1,j+1)){
            right = solve(triangle,i+1,j+1,dp);
        }
        
        return dp[i][j] = triangle[i][j] + min(left,right);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        return solve(triangle,0,0,dp);
    }
};


//Inplace
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i=n-2;i>=0;i--){
            for(int j = i;j>=0;j--){
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};

//Bottom up
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev = triangle[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j = 0;j<=i;j++){
                prev[j] = triangle[i][j] + min(prev[j],prev[j+1]);
            }
        }
        return prev[0];
    }
};
