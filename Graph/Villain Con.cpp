// The minions are very elitist in nature. If minion x admires minion y, then y thinks too highly of himself and does not admire x back. Also, if x admires y, x also admires everyone that y admires.
// All the minions are going to be present at the Villain Con. They want to make sure that they do not dress in the same color as someone who admires them. 
// There are N minions and M relations between them. The relations are given in a 2D array mat. Each relation is given in xi , yi format where yi admires xi. Find the minimum number of different colours that the minions will be dressing in. 

 

// Example 1:

// Input: 
// N = 5, M = 6
// mat = {{1, 3}, 
//        {2, 3}, 
//        {3, 4}, 
//        {1, 4}, 
//        {2, 5}, 
//        {3, 5}}
// Output: 3
// Explaination:
// If we assign red colour to 1 and 2,
// green colour to 3, and blue colour to 4 and 5, then
// every minion will have different coloured dresses
// from the one who admires them.
// Example 2:

// Input:
// N = 3, M = 2
// mat = {{1,3},{2,3}}
// Output:
// 2
// Explanation:
// If we assign red colour to 1 and 2, and green colour to 3, then the condition is satisfied.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function minColour() which takes N, M and mat[][] as input parameters and returns the minimum number of colours required.

 

// Expected Time Complexity: O(N+M)
// Expected Auxiliary Space: O(N+M)

 

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ M ≤ 2*105  
// 1 ≤ xi , yi ≤ N



// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minColour(int N, int M, vector<int> mat[]) {
        vector<int> inDeg(N+1,0);
        vector<vector<int>> adj(N+1);
        for(int i=0;i<M;i++){
            adj[mat[i][0]].push_back(mat[i][1]);
            inDeg[mat[i][1]]++;
        }
        
        queue<int> q;
        for(int i=1;i<=N;i++){
            if(inDeg[i]==0)
                q.push(i);
        }
        
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int temp = q.front();
                q.pop();
                for(auto it:adj[temp]){
                    inDeg[it]--;
                    if(inDeg[it] == 0)
                        q.push(it);
                }
            }
            level++;
        }
        return level;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
