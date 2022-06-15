// You are given an array of words where each word consists of lowercase English letters.

// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

// Return the length of the longest possible word chain with words chosen from the given list of words.

 

// Example 1:

// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
// Example 2:

// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
// Example 3:

// Input: words = ["abcd","dbqca"]
// Output: 1
// Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
// ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 

// Constraints:

// 1 <= words.length <= 1000
// 1 <= words[i].length <= 16
// words[i] only consists of lowercase English letters.

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<vector<string>> len(17);
        unordered_map<string,int> hm;
        for(auto word: words){
            len[word.length()].push_back(word);
            hm[word] = 1;
        }
        int ans = 1;
        for(int x = 16; x >= 2; x--){
            for(auto word: len[x]){
                int n = word.length();
                for(int i=0;i<n;i++){
                    string temp = word.substr(0,i) + word.substr(i+1);
                    if(hm.find(temp) != hm.end()){
                        hm[temp] = max(hm[temp],1 + hm[word]);
                        ans = max(ans,hm[temp]);
                    }
                    
                }
                
            }
        }
        return ans;
    }
};
