// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// Return any possible rearrangement of s or return "" if not possible.

 

// Example 1:

// Input: s = "aab"
// Output: "aba"
// Example 2:

// Input: s = "aaab"
// Output: ""
 

// Constraints:

// 1 <= s.length <= 500
// s consists of lowercase English letters.


class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> hm;
        float n = s.length();
        for(auto it:s){
            hm[it]++;
            if(hm[it] > ceil(n/2.0))
                return "";
        }
        priority_queue<pair<int,char>> maxh;
        for(auto it:hm){
            maxh.push({it.second,it.first});
        }
        pair<int,char> top1,top2;
        string ans = "";
        while(!maxh.empty()){
            top1 = maxh.top();
            maxh.pop();
            ans += top1.second;
                if(!maxh.empty()){
                    top2 = maxh.top();
                    maxh.pop();
                    ans += top2.second;
                    if(--top2.first > 0)
                        maxh.push(top2);
                }
            if(--top1.first > 0)
                maxh.push(top1);
        }
        return ans;
    }
};

// 11115555
// 15151515

// 1515151
