/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

Example 1:


Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
Example 2:

Input: board = [["X"]]
Output: [["X"]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
*/

class Solution {
private:
    bool isPossible(vector<vector<char>>& board, int x, int y, int m, int n){
        if(x<m && y<n && x>=0 && y>=0 && board[x][y]=='O'){
            return true;
        }
        return false;
    }
    void convert(vector<vector<char>>& board, int m, int n){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 't')
                    board[i][j] = 'O';
                
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    void dfs(vector<vector<char>>& board, int x, int y, int m, int n){
        board[x][y] = 't';
        if(isPossible(board,x,y+1,m,n))
            dfs(board,x,y+1,m,n);
        if(isPossible(board,x,y-1,m,n))
            dfs(board,x,y-1,m,n);
        if(isPossible(board,x+1,y,m,n))
            dfs(board,x+1,y,m,n);
        if(isPossible(board,x-1,y,m,n))
            dfs(board,x-1,y,m,n);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i= 0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==m-1 || j==n-1 || i==0 || j==0)
                    if(board[i][j] == 'O')
                    dfs(board,i,j,m,n);
            }
        }
        convert(board,m,n);
    }
};
