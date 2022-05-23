// Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

 

// Example 1:

// Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
// Output: 3
// Explanation: The repeated subarray with maximum length is [3,2,1].
// Example 2:

// Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
// Output: 5
 

// Constraints:

// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 100


//m * n space
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        int ans = 0;
        for(int i=0;i<=m;i++){
            for(int j = 0;j<=n;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                    continue;
                }
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans,dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return ans;
    }
};


//O(n) space
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);
        int ans = 0;
        for(int i=1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                if(nums1[i-1] == nums2[j-1]){
                    curr[j] = prev[j-1] + 1;
                    ans = max(ans,curr[j]);
                }
            }
            swap(prev,curr);
            fill(curr.begin(),curr.end(),0);
        }
        return ans;
    }
};
