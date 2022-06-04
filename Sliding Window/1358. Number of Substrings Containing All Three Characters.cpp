// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

// Example 1:

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
// Example 2:

// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
// Example 3:

// Input: s = "abc"
// Output: 1
 

// Constraints:

// 3 <= s.length <= 5 x 10^4
// s only consists of a, b or c characters.

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int i=0,j=0,ans=0;
        unordered_map<char,int> mp;
        while(j<n){
            mp[s[j]]++;
            
            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                //adding current string
                ans++;
                //adding all the strings possible by taking the current string as a prefix
                ans += n-j-1;
                //shifting left pointer 1 ahead
                mp[s[i]]--;
                i++;
            }
            
            j++;
        }
        
        return ans;
    }
};
