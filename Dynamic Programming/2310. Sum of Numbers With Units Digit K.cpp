// // Given two integers num and k, consider a set of positive integers with the following properties:

// The units digit of each integer is k.
// The sum of the integers is num.
// Return the minimum possible size of such a set, or -1 if no such set exists.

// Note:

// The set can contain multiple instances of the same integer, and the sum of an empty set is considered 0.
// The units digit of a number is the rightmost digit of the number.
 

// Example 1:

// Input: num = 58, k = 9
// Output: 2
// Explanation:
// One valid set is [9,49], as the sum is 58 and each integer has a units digit of 9.
// Another valid set is [19,39].
// It can be shown that 2 is the minimum possible size of a valid set.
// Example 2:

// Input: num = 37, k = 2
// Output: -1
// Explanation: It is not possible to obtain a sum of 37 using only integers that have a units digit of 2.
// Example 3:

// Input: num = 0, k = 7
// Output: 0
// Explanation: The sum of an empty set is considered 0.
 

// Constraints:

// 0 <= num <= 3000
// 0 <= k <= 9

class Solution {
private:
    int dpfunc(vector<int> &arr, int m, int n)
    {
        vector<vector<int>> dp(m + 1,vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            dp[0][i] = INT_MAX - 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                
                if (arr[i - 1] <= j) {
                    dp[i][j] = min(dp[i][j - arr[i - 1]] + 1, dp[i - 1][j]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
public:
    int minimumNumbers(int num, int k) {
        if(num == 0)
            return 0;
        if(num < k)
            return -1;
        int goal = num;
        vector<int> arr;
        for(int i = k; i <= goal; i += 10){
            if(i != 0)
                arr.push_back(i);
        }
        
        int ans = dpfunc(arr,arr.size(),num);
        if(ans == INT_MAX-1)
            return -1;
        
        return ans;
    }
};
