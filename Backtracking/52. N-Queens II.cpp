// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 

// Example 1:


// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
// Example 2:

// Input: n = 1
// Output: 1
 

// Constraints:

// 1 <= n <= 9



class Solution {
private:
    bool isSafe(vector<vector<bool>> &check, int i, int j, int n){
        //checking top till that row
        for(int x = 0;x < i;x++){
            if(check[x][j] == true)
                return false;
        }
        
        //checking top left
        int maxLeft = min(i,j);
        for(int x = 1;x<=maxLeft;x++){
            if(check[i-x][j-x] == true)
                return false;
        }
            
        //checking top left
        int maxRight = min(i,n-j-1);
        for(int x = 1;x<=maxRight;x++){
            if(check[i-x][j+x] == true)
                return false;
        }
        
        return true;
    }
    int solve(int i, int n, vector<vector<bool>> &check){
        if(i == n){
            return 1;
        }
        int ans = 0;
        for(int j = 0; j<n; j++){
            if(isSafe(check,i,j,n)){
                check[i][j] = true;
                ans += solve(i+1,n,check);
                check[i][j] = false;
            }
        }
        return ans;
    }
public:
    int totalNQueens(int n) {
        vector<vector<bool>> check(n,vector<bool>(n,false));
        return solve(0,n,check);
    }
};
