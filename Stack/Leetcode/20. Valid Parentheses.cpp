/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;
        unordered_map<char,char> mp{{']','['},{')','('},{'}','{'}};
        for (int i = 0; i < s.size(); i++) {
            if (!temp.empty() && temp.top() == mp[s[i]])
            {
                temp.pop();
            }
            else
                temp.push(s[i]);
        }
        return temp.empty();
    }
};
