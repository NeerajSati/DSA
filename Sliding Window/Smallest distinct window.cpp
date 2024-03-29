// Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
// For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

// Example 1:

// Input : "AABBBCBBAC"
// Output : 3
// Explanation : Sub-string -> "BAC"
// Example 2:
// Input : "aaab"
// Output : 2
// Explanation : Sub-string -> "ab"
 
// Example 3:
// Input : "GEEKSGEEKSFOR"
// Output : 8
// Explanation : Sub-string -> "GEEKSFOR"
 


// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function findSubString() which takes the string  S as input and returns the length of the smallest such window of the string.


// Expected Time Complexity: O(256.N)
// Expected Auxiliary Space: O(256)

 

// Constraints:
// 1 ≤ |S| ≤ 105
// String may contain both type of English Alphabets.



class Solution{
    public:
    int findSubString(string str)
    {
        int i = 0,j = 0;
        unordered_map<char,int> originalhm,patternhm;
        for(auto x:str)
            originalhm[x]++;
        
        int ans = INT_MAX;
        for(;j<str.length();j++){
            patternhm[str[j]]++;
            while(patternhm.size() == originalhm.size()){
                ans = min(ans,j-i+1);
                patternhm[str[i]]--;
                if(patternhm[str[i]] == 0){
                    patternhm.erase(str[i]);
                }
                i++;
            }
        }
        return ans;
    }
};
