// You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

// An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

// You may change 0's to 1's to connect the two islands to form one island.

// Return the smallest number of 0's you must flip to connect the two islands.

 

// Example 1:

// Input: grid = [[0,1],[1,0]]
// Output: 1
// Example 2:

// Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
// Output: 2
// Example 3:

// Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
// Output: 1
 

// Constraints:

// n == grid.length == grid[i].length
// 2 <= n <= 100
// grid[i][j] is either 0 or 1.
// There are exactly two islands in grid.

class Solution {
private:
    bool isPossible(int &n, int i, int j){
        if(i >= 0 && j >= 0 && j < n && i < n){
            return true;
        }
        return false;
    }
    void getAll(vector<vector<int>>& grid, int n, int i, int j){
        if(isPossible(n,i,j) && grid[i][j] == 1){
            grid[i][j] = -1;
            getAll(grid,n,i,j+1);
            getAll(grid,n,i,j-1);
            getAll(grid,n,i+1,j);
            getAll(grid,n,i-1,j);
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool second = false;
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!second && grid[i][j] == 1){
                    getAll(grid,n,i,j);
                    second = true;
                }
                if(second && grid[i][j] == 1){
                    q.push({i,j});
                }
            }
        }
        
        int adi[4] = { 0, 0, 1,-1};
        int adj[4] = { 1,-1, 0, 0};
        
        int ans = INT_MAX;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                
                int row = q.front().first;
                int col = q.front().second;
                
                for(int x = 0;x<4;x++){
                    if(isPossible(n,row + adi[x],col + adj[x])){
                        if(grid[row + adi[x]][col + adj[x]] == -1){
                            ans = min(ans, grid[row][col]);
                        }
                        else if(grid[row + adi[x]][col + adj[x]] == 0){
                            grid[row + adi[x]][col + adj[x]] = grid[row][col] + 1;
                            q.push({row + adi[x], col + adj[x]});
                        }
                    }
                }
                q.pop();
            }
        }
        return ans-1;
    }
};
