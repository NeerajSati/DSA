// Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0
 

// Constraints:

// 1 <= target <= 109
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105
 

// Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        queue<int> q;
        int i = 0,sum = 0,n = nums.size(),ans = INT_MAX;
        while(i<n){
            sum += nums[i];
            q.push(nums[i]);
            while(sum > target){
                int x = q.size();
                ans = min(ans,x);
                sum -= q.front();
                q.pop();
            }
            if(sum == target){
                int x = q.size();
                ans = min(ans,x);
            }
            i++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};


//O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j = 0,i=0,sum = 0,n = nums.size(),ans = INT_MAX;
        while(j<n){
            sum += nums[j];
            while(sum >= target){
                int x = j - i + 1;
                ans = min(ans,x);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
