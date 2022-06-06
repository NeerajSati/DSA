// Given a list of words, list of  single letters (might be repeating) and score of every character.

// Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).

// It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.

 

// Example 1:

// Input: words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
// Output: 23
// Explanation:
// Score  a=1, c=9, d=5, g=3, o=2
// Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
// Words "dad" and "dog" only get a score of 21.
// Example 2:

// Input: words = ["xxxz","ax","bx","cx"], letters = ["z","a","b","c","x","x","x"], score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
// Output: 27
// Explanation:
// Score  a=4, b=4, c=4, x=5, z=10
// Given letters, we can form the words "ax" (4+5), "bx" (4+5) and "cx" (4+5) with a score of 27.
// Word "xxxz" only get a score of 25.
// Example 3:

// Input: words = ["leetcode"], letters = ["l","e","t","c","o","d"], score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
// Output: 0
// Explanation:
// Letter "e" can only be used once.
 

// Constraints:

// 1 <= words.length <= 14
// 1 <= words[i].length <= 15
// 1 <= letters.length <= 100
// letters[i].length == 1
// score.length == 26
// 0 <= score[i] <= 10
// words[i], letters[i] contains only lower case English letters.

class Solution {
private:
    int helper(vector<string>& words, vector<int>& score, unordered_map<char,int> &hm, int pos){
        if(pos == words.size())
            return 0;
        
        unordered_map<char,int> oldhm(hm.begin(),hm.end());
        int sum = 0;
        int take = 0,nottake = 0,i;
        
        string curr = words[pos];
        for(i=0;i<curr.length();i++){
            if(oldhm.find(curr[i]) == oldhm.end() || oldhm[curr[i]]==0){
                break;
            }
            else{
                sum += score[curr[i] - 'a'];
                oldhm[curr[i]]--;
            }
        }
            
        //if word is possible
            if(i == curr.length()){
                take = helper(words,score,oldhm,pos+1);
            }
            else{
                sum = 0;
            }
        //if not possible, move on to next word
            nottake = helper(words,score,hm,pos+1);
        
        return max(take + sum,nottake);
    }
    
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int> hm;
        for(auto it:letters){
            hm[it]++;
        }
        
        int ans = helper(words,score,hm,0);
        
        return ans;
    }
};
