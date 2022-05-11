/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/



class Solution {
private:
    void dfs(vector<vector<char>> &grid, int x, int y){

 
        grid[x][y] = '0';
        if(((x+1)<grid.size()) && grid[x+1][y] == '1')
            dfs(grid,x+1,y);
        if(((x-1)>=0) && grid[x-1][y] == '1')
            dfs(grid,x-1,y);
        if(((y-1)>=0) && grid[x][y-1] == '1')

            dfs(grid,x,y-1);
        if(((y+1)<grid[0].size()) && grid[x][y+1] == '1')
            dfs(grid,x,y+1);
           
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid,i,j);
                }
        return ans;
    }
};





//or
class Solution {
private:
    bool isPossible(vector<vector<char>> &grid, int x, int y){
        int m = grid.size(),n = grid[0].size();
        if(x<m && x>=0 && y<n && y>=0 && grid[x][y] == '1')
            return true;
        return false;
    }
    void dfs(vector<vector<char>> &grid, int x, int y){
        if(isPossible(grid,x,y)){
            grid[x][y] = '0';
            dfs(grid,x+1,y);
            dfs(grid,x-1,y);
            dfs(grid,x,y-1);
            dfs(grid,x,y+1);
        }
           
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid,i,j);
                }
        return ans;
    }
};
