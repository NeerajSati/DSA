// You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

// Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
// Return the maximum number of points you can earn by applying the above operation some number of times.

 

// Example 1:

// Input: nums = [3,4,2]
// Output: 6
// Explanation: You can perform the following operations:
// - Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
// - Delete 2 to earn 2 points. nums = [].
// You earn a total of 6 points.
// Example 2:

// Input: nums = [2,2,3,3,3,4]
// Output: 9
// Explanation: You can perform the following operations:
// - Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
// - Delete a 3 again to earn 3 points. nums = [3].
// - Delete a 3 once more to earn 3 points. nums = [].
// You earn a total of 9 points.
 

// Constraints:

// 1 <= nums.length <= 2 * 104
// 1 <= nums[i] <= 104


class Solution {
private:
    int solve(vector<int>& nums, vector<int> &dp, int pos, int n){
        if(pos == n){
            return 0;
        }
        
        if(dp[pos] != -1){
            return dp[pos];
        }
        
        int el = nums[pos];
        int next = upper_bound(nums.begin(),nums.end(),el) - nums.begin();
        int sum = el * (next - pos);
        int oldPos = next;
        if(next < n && nums[next] == el + 1){
            next = upper_bound(nums.begin(),nums.end(),el + 1) - nums.begin();
        }
        return dp[pos] = max(sum + solve(nums,dp,next,n) , solve(nums,dp,oldPos,n));
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size()+1, -1);
        return solve(nums,dp,0,n);
    }
};




class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(10001,0);
        vector<int> dp(10001,0);
        for(int i=0;i<n;i++){
            sum[nums[i]] += nums[i];
        }
        
        dp[1] = sum[1];
        for(int i = 2;i<10001;i++){
            dp[i] = max(dp[i-1],dp[i-2] + sum[i]);
        }
        return dp[10000];
    }
};


class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(10001,0);
        for(int i=0;i<n;i++){
            sum[nums[i]] += nums[i];
        }
        
        int prev = 0,curr = sum[1],temp;
        for(int i = 2;i<10001;i++){
            temp = max(curr,prev + sum[i]);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};
