// Given an array arr[] of n integers. Count the total number of sub-array having total distinct elements same as that of total distinct elements of the original array.

 

// Example 1:

// Input:
// N=5
// arr[] = {2, 1, 3, 2, 3} 
// Output: 5
// Explanation:
// Total distinct elements in array is 3
// Total sub-arrays that satisfy the condition
// are:
// Subarray from index 0 to 2
// Subarray from index 0 to 3
// Subarray from index 0 to 4
// Subarray from index 1 to 3
// Subarray from index 1 to 4

// Example 2:

// Input:
// N=5
// arr[] = {2, 4, 4, 2, 4} 
// Output: 9

// Your Task:
// Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function countDistinctSubarray() that takes array arr and integer n  as parameters and returns the desired result.

 

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

 

// Constraints:
// 1 ≤ N ≤ 104



class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        unordered_map<int,int> mpp,check;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        // mpp.erase(mpp.find(2));
        int cnt = mpp.size(),ans = 0;
        int j = 0, i = 0;
        while(j<n){
            check[arr[j]]++;
            while(check.size() == cnt){
                ans += n - j;
                check[arr[i]]--;
                if(check[arr[i]] == 0){
                    check.erase(check.find(arr[i]));
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
