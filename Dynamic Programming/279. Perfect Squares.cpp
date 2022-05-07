/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 

Constraints:

1 <= n <= 104
*/

class Solution {
public:
    int numSquares(int n) {
        int lis[n+1];
        lis[0] = 0;
        lis[1] = 1;
        for(int i=2;i<=n;i++){
            int min = INT_MAX;
            for(int j=1;j*j<=i;j++){
                if(lis[i - j * j] < min)
                    min = lis[i - j * j];
            }
            lis[i] = min + 1;
        }
        return lis[n];
    }
};
