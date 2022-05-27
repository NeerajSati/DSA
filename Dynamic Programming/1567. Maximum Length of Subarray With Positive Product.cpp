// Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.

// A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

// Return the maximum length of a subarray with positive product.

 

// Example 1:

// Input: nums = [1,-2,-3,4]
// Output: 4
// Explanation: The array nums already has a positive product of 24.
// Example 2:

// Input: nums = [0,1,-2,-3,-4]
// Output: 3
// Explanation: The longest subarray with positive product is [1,-2,-3] which has a product of 6.
// Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.
// Example 3:

// Input: nums = [-1,-2,-3,0,1]
// Output: 2
// Explanation: The longest subarray with positive product is [-1,-2] or [-2,-3].
 

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        // elements       :   9 5 8 2 -6 4 -3 0 2 -5 15 10 -7 9 -2
        // positive_len   :   1 2 3 4  0 1  7 0 1  0  1  2  5 6  5
        // negative_len   :   0 0 0 0  5 6  2 0 0  2  3  4  3 4  7
        
        int posLen = 0,negLen = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                posLen = 0;
                negLen = 0;
            }
            else if(nums[i] > 0){
                posLen++;
                if(negLen != 0)
                    negLen++;
            }
            else{
                int temp = posLen;
                if(negLen != 0)
                    posLen = negLen + 1;
                else
                    posLen = 0;
                negLen = temp + 1;
            }
            ans = max(ans,posLen);
        }
        return ans;
    }
};
