// Given an integer array arr and an integer k, modify the array by repeating it k times.

// For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].

// Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.

// As the answer can be very large, return the answer modulo 109 + 7.

 

// Example 1:

// Input: arr = [1,2], k = 3
// Output: 9
// Example 2:

// Input: arr = [1,-2,1], k = 5
// Output: 2
// Example 3:

// Input: arr = [-1,-2], k = 7
// Output: 0
 

// Constraints:

// 1 <= arr.length <= 105
// 1 <= k <= 105
// -104 <= arr[i] <= 104

class Solution {
private:
    int getKadane(vector<int>& arr, int n){
        long long ans = 0;
        long long max = 0;
            for(int i=0;i<n;i++){
                if(arr[i]+ans >= arr[i]){
                    ans = arr[i] + ans;
                    if(ans > max)
                        max = ans;
                }
                else{
                    ans = arr[i];
                    if(ans > max)
                        max = ans;
                }
            }
        return max % 1000000007;
    }
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        if(k==1){
            return getKadane(arr,n);
        }
        vector<int> newArr(arr.begin(),arr.end());
        newArr.insert(newArr.end(),arr.begin(),arr.end());
        int res = getKadane(newArr,n*2);
        long long sum = accumulate(arr.begin(),arr.end(),0);
        if(sum > 0){
            return (res + sum * (k-2)) % 1000000007;
        }
        
        return res;
    }
};



//O(1)
  class Solution {
public:
int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        long long ans = 0;
        long long max = 0;
        for(int x=0;x<2 && x<k;x++){
            for(int i=0;i<n;i++){
                if(arr[i]+ans >= arr[i]){
                    ans = arr[i] + ans;
                    if(ans > max)
                        max = ans;
                }
                else{
                    ans = arr[i];
                    if(ans > max)
                        max = ans;
                }
            }
        }
        long long sum = accumulate(arr.begin(),arr.end(),0);
        
        int res = max % 1000000007;
        
        if(sum > 0 && k>1){
            return (res + sum * (k-2)) % 1000000007;
        }
        
        return res;
    }
};
  
