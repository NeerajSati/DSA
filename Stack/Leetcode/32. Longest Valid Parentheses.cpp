// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 

// Example 1:

// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
// Example 2:

// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
// Example 3:

// Input: s = ""
// Output: 0
 

// Constraints:

// 0 <= s.length <= 3 * 104
// s[i] is '(', or ')'.



//We get the indexes of all the brackets which are invalid.
//And thus all the valid subsets lie between these two invalid indexes.
//We calculate the maximum differece between those indexes to get the solution.

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(!stk.empty() && s[i] == ')' && s[stk.top()] == '('){
                stk.pop();
            }
            else{
                stk.push(i);
            }
        }
        
        if(stk.empty())
            return n;
        
        int ans = 0;
        int prev = n,curr = 0;
        while(!stk.empty()){
            curr = stk.top();
            stk.pop();
            ans = max(ans,prev - curr - 1);
            prev = curr;
        }
        ans = max(ans,prev);
        return ans;
    }
};
