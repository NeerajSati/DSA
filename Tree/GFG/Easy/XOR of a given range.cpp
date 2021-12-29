/*
You are given an array nums. Your task is to complete the function getXor to return the XOR of the given range a and b.
 

Example 1:

Input: nums = {1, 3, 5, 7, 9, 11}
,a = 1, b = 3
Output: 1
Explanation: 3^5^7 = 1
Example 2:

Input: nums = {1, 2, 3, 4, 5}
a = 0, b = 4
Output: 1
 

Your Task:
You don't need to read or print anyhting. Your task is to comlplete the function getXor() which takes nums, a and b as input parameter and returns the xor from a to b.
 

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)
 

Constraints:
1 ≤ n ≤ 105
0 ≤ a ≤ b ≤ n
1 ≤ nums[i] ≤ 100
*/



// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int getXor(vector<int>&nums, int a, int b){

        int x = nums[a];
        for(int i=a+1;i<=b;i++){
            x ^= nums[i];
        }

        return x;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--){
        int n, a, b;
        cin >> n >> a >> b;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)cin >> nums[i];
        if(a > b)swap(a, b);
        Solution obj;
        int ans = obj.getXor(nums, a, b);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
