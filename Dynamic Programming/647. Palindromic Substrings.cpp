// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

 

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

// Constraints:

// 1 <= s.length <= 1000
// s consists of lowercase English letters.


//We fill the upper right triangular matrix in this question
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
             if(i==j)
                 dp[i][j] = 1;
             else if(i+1 == j)
                 dp[i][j] = (s[i] == s[j]) ? 1 : 0;
             else
                 dp[i][j] = (s[i] == s[j]) ? dp[i+1][j-1] : 0;
                count += dp[i][j];
            }
        }
        return count;
    }
};
