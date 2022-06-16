// Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
// Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
 

// Example 1:

// Input: 
// N = 5, K = 4
// dict = {"baa","abcd","abca","cab","cad"}
// Output:
// 1
// Explanation:
// Here order of characters is 
// 'b', 'd', 'a', 'c' Note that words are sorted 
// and in the given language "baa" comes before 
// "abcd", therefore 'b' is before 'a' in output.
// Similarly we can find other orders.
// Example 2:

// Input: 
// N = 3, K = 3
// dict = {"caa","aaa","aab"}
// Output:
// 1
// Explanation:
// Here order of characters is
// 'c', 'a', 'b' Note that words are sorted
// and in the given language "caa" comes before
// "aaa", therefore 'c' is before 'a' in output.
// Similarly we can find other orders.
 

// Your Task:
// You don't need to read or print anything. Your task is to complete the function findOrder() which takes  the string array dict[], its size N and the integer K as input parameter and returns a string denoting the order of characters in the alien language.


// Expected Time Complexity: O(N * |S| + K) , where |S| denotes maximum length.
// Expected Space Compelxity: O(K)


// Constraints:
// 1 ≤ N, M ≤ 300
// 1 ≤ K ≤ 26
// 1 ≤ Length of words ≤ 50


class Solution{
    private:
    void topoSort(vector<vector<int>> &adj, int K, string &ans,vector<int> &inDeg){
        queue<int> q;
        for(int i=0;i<K;i++){
            if(inDeg[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int temp = q.front();
            ans += temp + 'a';
            q.pop();
            for(auto it: adj[temp]){
                inDeg[it]--;
                if(inDeg[it] == 0)
                    q.push(it);
            }
        }
    }
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);
        vector<int> inDeg(K,0);
        for(int i=0;i<N-1;i++){
            string first = dict[i];
            string second = dict[i+1];
            for(int x=0;x<min(first.length(),second.length());x++){
                if(first[x] != second[x]){
                    adj[first[x]-'a'].push_back(second[x]-'a');
                    inDeg[second[x]-'a']++;
                    break;
                }
            }
        }
        string ans = "";
        topoSort(adj,K,ans,inDeg);
        return ans;
    }
};
