/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/


class Solution {
private:
    bool isPossible(vector<vector<int>>& grid, int x, int y, int m, int n){
        if(x<m && y<n && x>=0 && y>=0 && grid[x][y] == 1){
            return true;
        }
        return false;
    }
    int dfs(vector<vector<int>>& grid, int x,int y,int m ,int n){
        grid[x][y] = 0;
        int ans = 0;
        if(isPossible(grid,x,y+1,m,n))
            ans += dfs(grid,x,y+1,m,n);
        if(isPossible(grid,x,y-1,m,n))
            ans += dfs(grid,x,y-1,m,n);
        if(isPossible(grid,x+1,y,m,n))
            ans += dfs(grid,x+1,y,m,n);
        if(isPossible(grid,x-1,y,m,n))
            ans += dfs(grid,x-1,y,m,n);
        return ans + 1;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    mx = max(mx,dfs(grid,i,j,m,n));
                }
            }
        }
        return mx;
    }
};

