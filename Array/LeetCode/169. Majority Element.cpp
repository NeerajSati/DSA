/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-231 <= nums[i] <= 231 - 1
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

//Hashmap
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> hm;
        int sz = nums.size()/2;
        for(auto it:nums){
            hm[it]++;
            if(hm[it] > sz){
                return it;
            }
        }
        return -1;
    }
};

//Sorting
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sz = nums.size()/2;
        return nums[sz];
    }
};


//Moore Voting Algorithms
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int max;
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if (count == 0) {
                max = nums[i];
                count = 1;
                continue;
            }
            if (max != nums[i]) {
                count--;
            } else {
                count++;
            }
        }
        return max;
    }
};
