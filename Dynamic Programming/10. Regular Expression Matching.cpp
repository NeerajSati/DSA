// Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

// '.' Matches any single character.​​​​
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).

 

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input: s = "aa", p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
// Example 3:

// Input: s = "ab", p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
 

// Constraints:

// 1 <= s.length <= 20
// 1 <= p.length <= 30
// s contains only lowercase English letters.
// p contains only lowercase English letters, '.', and '*'.
// It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

class Solution {
private:
    bool helper(string s, int i, int m, string p, int j, int n, vector<vector<int>> &dp){
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(j == n)
            return dp[i][j] = i==m;
        
        if(p[j+1] == '*'){
            //no occurence or one occurence
            if(helper(s, i, m, p, j+2, n, dp) || i<m && (p[j] == '.' || (p[j] == s[i])) && helper(s, i+1, m, p, j, n, dp))
                return dp[i][j] = true;
        }
        else if(i<m && p[j] == '.' || (p[j] == s[i])){
            if(helper(s, i+1, m, p, j+1, n, dp))
                return dp[i][j] = true;
        }
        
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return helper(s,0,m,p,0,n,dp);
    }
};
