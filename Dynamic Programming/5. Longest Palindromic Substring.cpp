// Given a string s, return the longest palindromic substring in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.


//Gap Strategy

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int maxi = 0, maxj = 0,maxgap = -1;
        for(int g = 0; g < n; g++){
            for(int i = 0,j = g; j < n; i++,j++){
                if(g == 0){
                    dp[i][j] = true;
                }
                else if(g == 1){
                    dp[i][j] = (s[i] == s[j]);
                }
                else{
                    dp[i][j] = (s[i] == s[j]) && (dp[i+1][j-1]);
                }
                
                if(dp[i][j]){
                    if(g > maxgap){
                        maxgap = g;
                        maxi = i;
                        maxj = j;
                    }
                }
            }
        }
        
        string ans = s.substr(maxi,maxj - maxi + 1);
        
        return ans;
    }
};
