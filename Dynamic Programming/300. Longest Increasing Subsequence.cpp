// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104
 
 
 class Solution {
    int dp[2501];
    int solve(vector<int>& nums, int n){
        int ans = 0;
        for(int i=0;i<n;i++){
        int max = 0;
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    if(dp[j] > max)
                        max = dp[j];
                }
            }
            dp[i] = max + 1;
            if(dp[i] > ans)
                ans = dp[i];
        }
        return ans;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums,nums.size());
    }
};

// Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

class Solution {
    int solve(vector<int>& nums, int n){
        if(n==1)
            return 1;
        int dp[n+1];
        dp[0] = INT_MIN;
        for(int i=1;i<=n;i++)
            dp[i] = INT_MAX;
        for(int i=0;i<n;i++){
            int temp = upper_bound(dp,dp+n+1,nums[i]) - dp;
            if(nums[i] > dp[temp-1])
                dp[temp] = nums[i];
        }
        int ans =0;
        for(int i=n;i>=0;i--){
            if(dp[i]!=INT_MAX){
                ans = i;
                break;
            }
        }
        return ans;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums,nums.size());
    }
};



class Solution {
    int solve(vector<int>& nums, int n){
        vector<int> dp;
        for(int i=0;i<n;i++){
            if(dp.empty() || dp[dp.size()-1] < nums[i])
                dp.push_back(nums[i]);
            else{
                auto idx = lower_bound(dp.begin(),dp.end(),nums[i]) - dp.begin();
                dp[idx] = nums[i];
            }
        }
        return dp.size();
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums,nums.size());
    }
};
