/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#define pii pair<int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hm;
        for(auto it:nums){
            hm[it]++;
        }
        priority_queue<pii,vector<pii>,greater<pii>> minh;
        for(auto it:hm){
            minh.push({it.second,it.first});
            if(minh.size()>k)
                minh.pop();
        }
        vector<int> v;
        while(!minh.empty()){
            v.push_back(minh.top().second);
            minh.pop();
        }
        return v;
    }
};
