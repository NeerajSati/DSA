/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:

1 <= n <= 1690
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)
            return 1;
        int dp[n];
        dp[0] = 1;
        int if2=0,if3=0,if5=0;
        for(int i=1;i<n;i++){
            dp[i] = min(dp[if2]*2,min(dp[if3]*3 , dp[if5]*5));
            if(dp[i] == dp[if2]*2)
                if2++;
            if(dp[i] == dp[if3]*3)
                if3++;
            if(dp[i] == dp[if5]*5)
                if5++;
        }
        return dp[n-1];
    }
};
