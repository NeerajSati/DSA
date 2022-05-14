// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:


// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.




class Solution {
    bool isPossible(vector<vector<int>>& grid, int x, int y, int m, int n){
        if(x<m && y<n && x>=0 && y>=0 && grid[x][y] == 1){
            return true;
        }
        return false;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        //Count fresh oranges as well as push the rotted oranges in queue for bfs
        int fresh = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
      //if there are no fresh oranges, i.e, all oranges are already rotted or not there thus return time 0
        if(fresh == 0)
            return 0;
        //Implement BFS
        int time = 0;
        while(!q.empty()){
            int size = q.size();
          //Temp will store if some oranges are being rotted in this iteration
            int temp = 0;
                while(size != 0){
                    pair<int,int> x = q.front();
                    q.pop();
                    int i = x.first,j = x.second;
                    if(isPossible(grid,i+1,j,m,n)){
                      //Increase temp, i.e, one orange rotted, push the rotted orange in queue, and set grid to rotted
                        temp++;
                        grid[i+1][j] = 2;
                        q.push({i+1,j});
                    }
                    if(isPossible(grid,i-1,j,m,n)){
                        temp++;
                        grid[i-1][j] = 2;
                        q.push({i-1,j});
                    }
                    if(isPossible(grid,i,j+1,m,n)){
                        temp++;
                        grid[i][j+1] = 2;
                        q.push({i,j+1});
                    }
                    if(isPossible(grid,i,j-1,m,n)){
                        temp++;
                        grid[i][j-1] = 2;
                        q.push({i,j-1});
                    }
                    size--;
                }
            if(temp!=0)
                time++;
            
        }
        
      //again count fresh, i.e, not possible to rot all the oranges, thus returning -1
        fresh = 0;    
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)
                    fresh++;
            }
        }
        if(fresh != 0)
            return -1;
        
        return time;
    }
};
