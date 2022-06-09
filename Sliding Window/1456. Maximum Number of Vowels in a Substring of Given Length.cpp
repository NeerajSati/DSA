// Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

// Example 1:

// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.
// Example 2:

// Input: s = "aeiou", k = 2
// Output: 2
// Explanation: Any substring of length 2 contains 2 vowels.
// Example 3:

// Input: s = "leetcode", k = 3
// Output: 2
// Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.
// 1 <= k <= s.length

class Solution {
private:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' ||c == 'i' ||c == 'o' ||c == 'u')
            return true;
        
        return false;
    }
    
public:
    int maxVowels(string s, int k) {
        int start = 0,n = s.length(),cnt = 0,ans = 0;
        for(int i=0;i<n;i++){
            
            if(i - start >= k){
                if(isVowel(s[start]))
                    cnt--;
                start++;
            }
            
            if(isVowel(s[i])){
                cnt++;
            }
            if(i >= k-1)
                ans = max(ans,cnt);
        }
        
        return ans;
    }
};

// "aeiou", k = 2
// 
