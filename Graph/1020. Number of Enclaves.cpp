/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.
*/


class Solution {
private:
    bool isPossible(vector<vector<int>>& grid, int x, int y, int m, int n){
        if(x<m && y<n && x>=0 && y>=0 && grid[x][y]==1){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<int>>& grid, int x, int y, int m, int n){
        grid[x][y] = 0;
        if(isPossible(grid,x+1,y,m,n))
            dfs(grid,x+1,y,m,n);
        if(isPossible(grid,x-1,y,m,n))
            dfs(grid,x-1,y,m,n);
        if(isPossible(grid,x,y+1,m,n))
            dfs(grid,x,y+1,m,n);
        if(isPossible(grid,x,y-1,m,n))
            dfs(grid,x,y-1,m,n);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 || i==m-1 || j==0 || j==n-1)
                    if(grid[i][j] == 1)
                        dfs(grid,i,j,m,n);
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                    if(grid[i][j] == 1){
                        ans++;
                    }
            }
        }
        return ans;
    }
};
