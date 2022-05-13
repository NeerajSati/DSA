// Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

// Example 1:

// Input:   

// Output: 1
// Explanation: 1->2->3->4->1 is a cycle.
// Example 2:

// Input: 

// Output: 0
// Explanation: No cycle in the graph.
 

// Your Task:
// You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not, return 1 if a cycle is present else return 0.

// NOTE: The adjacency list denotes the edges of the graph where edges[i][0] and edges[i][1] represent an edge.

 

// Expected Time Complexity: O(V + E)
// Expected Space Complexity: O(V)

class Solution {
  private:
    bool dfs(vector<int> adj[], vector<int> &visited, int parent, int s){
        visited[s] = true;
        for(auto it:adj[s]){
            if(!visited[it]){
                if(dfs(adj,visited,s,it))
                    return true;
            }
            else{
                if(parent != it)
                    return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(adj,visited,-1,i))
                    return true;
            }
        }
        return false;
    }
};
