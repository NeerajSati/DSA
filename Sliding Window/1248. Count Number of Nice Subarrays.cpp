// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

 

// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
// Example 2:

// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There is no odd numbers in the array.
// Example 3:

// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// Output: 16
 

// Constraints:

// 1 <= nums.length <= 50000
// 1 <= nums[i] <= 10^5
// 1 <= k <= nums.length



class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0,odds=0,count=0,ans=0;
        while(j<n){
            //if odd
            if(nums[j] % 2 == 1){
                odds++;
                if(odds >= k){
                    count=1;
                    while(nums[i] % 2 == 0){
                        count++;
                        i++;
                    }
                    i++;
                    ans += count;
                }
            }
            //if even
            else{
                if(odds >= k)
                    ans += count;
            }
            j++;
        }
        return ans;
    }
};
