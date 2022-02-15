/*
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

 

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
 

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100
*/


class Solution {
private:
    class helper{
    public:
    int operator()(pair<int,int>& p1, pair<int,int>& p2){

        if(p1.first>p2.first)
            return true;
        else if(p1.first<p2.first)
            return false;
        else{
            if(p1.second<p2.second)
                return true;
            else 
                return false;
        }

    }
    };
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> hm;
        for(auto i:nums){
            hm[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,helper> maxh;
        for(auto it:hm){
            maxh.push({it.second,it.first});
        }
        vector<int> ans;
        while(!maxh.empty()){
            int freq = maxh.top().first;
            int element = maxh.top().second;
            for(int i=0;i<freq;i++)
            ans.push_back(element);
            maxh.pop();
        }
        return ans;
    }
};
