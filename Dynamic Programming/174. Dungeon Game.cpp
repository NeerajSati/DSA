// The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.

// The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

// Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).

// To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

// Return the knight's minimum initial health so that he can rescue the princess.

// Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

 

// Example 1:


// Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
// Output: 7
// Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
// Example 2:

// Input: dungeon = [[0]]
// Output: 1
 

// Constraints:

// m == dungeon.length
// n == dungeon[i].length
// 1 <= m, n <= 200
// -1000 <= dungeon[i][j] <= 1000



class Solution {
private:
    int helper(vector<vector<int>>& dungeon, int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i == m || j == n)
            return INT_MAX;
        
        if(dp[i][j] != INT_MAX)
            return dp[i][j];    
            
        if(i == m-1 && j == n-1){
            //if last cell is negative we need atleast negative +1 health
            if(dungeon[i][j] < 0){
                return dp[i][j] = -dungeon[i][j] + 1;
            }
            else
                return dp[i][j] = 1;
        }
        
        int goRight = helper(dungeon,i,j+1,m,n,dp);
        int goDown = helper(dungeon,i+1,j,m,n,dp);
        
        int health = min(goRight,goDown) - dungeon[i][j];
        
        if(health <= 0){
                return dp[i][j] = 1;
        }
                
        return dp[i][j] = health;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n, INT_MAX));
        return helper(dungeon,0,0,m,n,dp);
    }
};






class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
        
        dp[m-1][n] = 1;
        dp[m][n-1] = 1;
        
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                
                int temp = min(dp[i+1][j] , dp[i][j+1]) - dungeon[i][j];
                
                if(temp <= 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = temp;
                
            } 
        }
        
        return dp[0][0];
    }
};
