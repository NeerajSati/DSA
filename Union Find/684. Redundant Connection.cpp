// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

// Example 1:


// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]
// Example 2:


// Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
// Output: [1,4]
 

// Constraints:

// n == edges.length
// 3 <= n <= 1000
// edges[i].length == 2
// 1 <= ai < bi <= edges.length
// ai != bi
// There are no repeated edges.
// The given graph is connected.

class Solution {
private:
    struct UF{
        int parent,rank;
    };
    int findpar(int num, vector<UF> &disj){
        if(disj[num].parent == -1){
            return num;
        }
        return disj[num].parent = findpar(disj[num].parent,disj);
    }
    void unionf(int temp1, int temp2, vector<UF> &disj){
        if(disj[temp1].rank > disj[temp2].rank){
            disj[temp2].parent = temp1;
        }
        else if(disj[temp1].rank < disj[temp2].rank){
            disj[temp1].parent = temp2;
        }
        else{
            disj[temp2].parent = temp1;
            disj[temp1].rank = disj[temp2].rank + 1;
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<UF> disj(n+1);
        for(int i=0;i<n;i++){
            disj[i].parent = -1;
            disj[i].rank = 0;
        }
        int ansx = -1,ansy = -1;
        for(auto it: edges){
            int temp1 = findpar(it[0],disj);
            int temp2 = findpar(it[1],disj);
            if(temp1 == temp2){
                ansx = it[0];
                ansy = it[1];
            }
            else{
                unionf(temp1,temp2,disj);
            }
        }
        if(ansx == -1)
            return {};
        
        return {ansx,ansy};
    }
};
