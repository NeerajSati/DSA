// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

// Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

// Example 1:

// Input: arr = [1,15,7,9,2,5,10], k = 3
// Output: 84
// Explanation: arr becomes [15,15,15,9,10,10,10]
// Example 2:

// Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
// Output: 83
// Example 3:

// Input: arr = [1], k = 1
// Output: 1
 

// Constraints:

// 1 <= arr.length <= 500
// 0 <= arr[i] <= 109
// 1 <= k <= arr.length


class Solution {
private:
    int solve(vector<int>& arr, int k, int i, int j, vector<vector<int>> &dp){
        if(i>j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MIN;
        int currMax = 0;
        int len = 1;
        for(int x=i;x<=j && len <= k;x++ , len++){
            currMax = max(currMax,arr[x]);
            int temp = (currMax * len) + solve(arr,k,x+1,j,dp);
            if(ans < temp)
                ans = temp;
        }
        return dp[i][j] = ans;
        
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(arr,k,0,n-1,dp);
    }
};
