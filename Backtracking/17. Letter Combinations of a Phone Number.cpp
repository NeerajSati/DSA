// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].


class Solution {
private:
    void solve(string done, string up, vector<string> &ans, map<char,string> &hm){
        if(up.length() == 0){
            if(done.length() != 0)
                ans.push_back(done);
            return;
        }
        char digit = up[0];
        for(char x:hm[digit]){
            solve(done + x , up.substr(1,up.length()-1), ans, hm);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        
        map<char,string> hm;
        hm['2'] = "abc";
        hm['3'] = "def";
        hm['4'] = "ghi";
        hm['5'] = "jkl";
        hm['6'] = "mno";
        hm['7'] = "pqrs";
        hm['8'] = "tuv";
        hm['9'] = "wxyz";
        
        vector<string> ans;
        solve("",digits,ans,hm);
        return ans;
    }
};
