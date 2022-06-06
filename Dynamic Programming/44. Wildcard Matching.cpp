// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

 

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.
// Example 3:

// Input: s = "cb", p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

// Constraints:

// 0 <= s.length, p.length <= 2000
// s contains only lowercase English letters.
// p contains only lowercase English letters, '?' or '*'.

class Solution {
private:
    bool helper(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(i == s.length() && j == p.length())
            return true;
        else if(j == p.length())
            return false;
        else if(i == s.length()){
            return p[j] == '*' ? helper(s,p,i,j+1,dp) : false;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(p[j] == '*'){
            return dp[i][j] = helper(s,p,i,j+1,dp) || helper(s,p,i+1,j+1,dp) || helper(s,p,i+1,j,dp);
        }
        else if(p[j] == '?' || s[i] == p[j])
            return dp[i][j] = helper(s,p,i+1,j+1,dp);

        return dp[i][j] = false;        
    }
    
public:
    bool isMatch(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        vector<vector<int>> dp(s_len,vector<int>(p_len,-1));
        return helper(s,p,0,0,dp);
    }
};
