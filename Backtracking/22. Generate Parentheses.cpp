// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

// Constraints:

// 1 <= n <= 8
class Solution {
private:
    void helper(string curr, int openadd, int closeleft, vector<string> &ans){
        if(openadd == 0 && closeleft == 0)
            ans.push_back(curr);
        if(openadd){
            helper(curr + '(',openadd-1,closeleft + 1,ans);
        }
        if(closeleft){
            helper(curr + ')',openadd,closeleft - 1,ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper("",n,0,ans);
        return ans;
    }
};
