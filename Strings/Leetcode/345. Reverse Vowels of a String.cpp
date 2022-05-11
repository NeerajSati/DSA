/*
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/

class Solution {
private:
    bool isVowel(char x){
        x = tolower(x);
        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
            return true;
        return false;
    }
public:
    string reverseVowels(string s) {
        int start = 0;
        int end = s.length()-1;
        while(start<end){
            while(start < end && !isVowel(s[start])){
                start++;
            }
            while(start < end && !isVowel(s[end])){
                end--;
            }
            char temp = s[end];
            s[end] = s[start];
            s[start] = temp;
            start++;
            end--;
        }
        return s;
    }
};
