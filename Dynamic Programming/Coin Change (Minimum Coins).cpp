// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

 

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0
 

// Constraints:

// 1 <= coins.length <= 12
// 1 <= coins[i] <= 231 - 1
// 0 <= amount <= 104
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int mat[n+1][amount+1];
        for(int i=1;i<=n;i++){
            mat[i][0] = 0;
        }
        for(int j=0;j<=amount;j++){
            mat[0][j] = INT_MAX - 1;
            if(j%coins[0] == 0)
                mat[1][j] = j/coins[0];
            else{
                mat[1][j] = INT_MAX-1;
            }
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    mat[i][j] = min( mat[i-1][j], 1 + mat[i][j-coins[i-1]]); 
                }
                else{
                    mat[i][j] = mat[i-1][j];
                }
            }
        }
        if(mat[n][amount] == INT_MAX-1)
            return -1;
        return mat[n][amount];
    }
};
