// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return the minimum cuts needed for a palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
// Example 2:

// Input: s = "a"
// Output: 0
// Example 3:

// Input: s = "ab"
// Output: 1
 

// Constraints:

// 1 <= s.length <= 2000
// s consists of lowercase English letters only.


class Solution {
private:
    int mat[2001][2001];
    bool isPalindrome(string &s,int i,int j){
        if(i>=j)
            return true;
        while(i<j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string &s,int i,int j){
        if(i>=j)
            return 0;
        if(mat[i][j]!=-1)
            return mat[i][j];
        if(isPalindrome(s,i,j))
            return 0;
        int ans = INT_MAX;
        for(int k=i;k<j;k++){
            if(isPalindrome(s, i, k)){                         
                int temp = solve (s, k+1, j) + 1;
                ans = min (ans, temp);
            }
        }
        return mat[i][j] = ans;
    }
public:
    int minCut(string s) {
        memset(mat,-1,sizeof(mat));
        return solve(s,0,s.length()-1);
    }
};
