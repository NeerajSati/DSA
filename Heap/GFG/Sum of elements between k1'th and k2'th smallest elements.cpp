/*
Given an array A[] of N positive integers and two positive integers K1 and K2. Find the sum of all elements between K1th and K2th smallest elements of the array. It may be assumed that (1 <= k1 < k2 <= n).

 

Example 1:

Input:
N  = 7
A[] = {20, 8, 22, 4, 12, 10, 14}
K1 = 3, K2 = 6
Output:
26
Explanation:
3rd smallest element is 10
6th smallest element is 20
Sum of all element between
K1 & K2 is 12 + 14 = 26
 

Example 2:

Input
N = 6
A[] = {10, 2, 50, 12, 48, 13}
K1= 2, K2 = 6
Output:
73
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function sumBetweenTwoKth() which takes the array A[], its size N and two integers K1 and K2 as inputs and returns the sum of all the elements between K1th and K2th smallest elements.
 

Expected Time Complexity: O(N. log(N))
Expected Auxiliary Space: O(N)

 

Constraints:
1 ≤ N ≤ 105
1 ≤ K1, K2 ≤ 109
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    private:
    long long kthSmallest(long long A[], long long N, long long K){
        priority_queue<long long> maxh;
        for(long long i=0;i<N;i++){
        maxh.push(A[i]);
        if(maxh.size()>K)
            maxh.pop();
        }
        return maxh.top();
    }
    
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        long long k1th = kthSmallest(A, N, K1);
        long long k2th = kthSmallest(A, N, K2);
        long long ans = 0;
        for(long long i=0;i<N;i++){
        if(A[i]>k1th && A[i]<k2th)
        ans += A[i];
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends
