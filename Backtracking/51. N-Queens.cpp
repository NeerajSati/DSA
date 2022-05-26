// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

// Example 1:


// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]
 

// Constraints:

// 1 <= n <= 9


class Solution {
private:
    bool isSafe(vector<string> &strArr, int i, int j, int n){
        //checking top till that row
        for(int x = 0;x < i;x++){
            if(strArr[x][j] == 'Q')
                return false;
        }
        
        //checking top left
        int maxLeft = min(i,j);
        for(int x = 1;x<=maxLeft;x++){
            if(strArr[i-x][j-x] == 'Q')
                return false;
        }
            
        //checking top left
        int maxRight = min(i,n-j-1);
        for(int x = 1;x<=maxRight;x++){
            if(strArr[i-x][j+x] == 'Q')
                return false;
        }
        
        return true;
    }
    void solve(vector<string> &strArr, int i, int n, vector<vector<string>> &check){
        if(i == n){
            check.push_back(strArr);
            return;
        }
        for(int j = 0; j<n; j++){
            if(isSafe(strArr,i,j,n)){
                strArr[i][j] = 'Q';
                solve(strArr,i+1,n,check);
                strArr[i][j] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> check;
        vector<string> strArr(n,string(n,'.'));
        solve(strArr,0,n,check);
        return check;
    }
};
