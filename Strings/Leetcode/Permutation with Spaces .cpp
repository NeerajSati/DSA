/*
Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. The output should be printed in sorted increasing order of strings

Example 1:

Input:
S = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Explanation:
ABC
AB C
A BC
A B C
These are the possible combination of "ABC".
 

Example 2:

Input:
S = "AB"
Output: (A B)(AB)

Your Task:  
You don't need to read input or print anything. Your task is to complete the function permutation() which takes the string S as input parameters and returns the sorted array of the string denoting the different permutation (DON'T ADD '(' and ')' it will be handled by the driver code only).

Expected Time Complexity: O(2^n)
Expected Auxiliary Space: O(1)

 

CONSTRAINTS:
1 < |S| < 10
*/

class Solution{
private:
    vector<string> ans;
    void helper(string S,int i,int n,string temp){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        helper(S,i+1,n,(temp + " " + S[i]));
        helper(S,i+1,n,(temp + S[i]));
    }
public:

    vector<string> permutation(string S){
        string temp = "";
        temp.push_back(S[0]);
        helper(S,1,S.length(),temp);
        return ans;
    }
};
