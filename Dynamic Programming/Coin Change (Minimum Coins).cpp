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
