/*
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

Example 1:


Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:


Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
 

Constraints:

1 <= n <= 105
1 <= connections.length <= min(n * (n - 1) / 2, 105)
connections[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated connections.
No two computers are connected by more than one cable.*/




class Solution {
private:
    void dfs(int s, vector<vector<int>> &adj, vector<int>& visited){
        visited[s] = true;
        for(auto it: adj[s]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(edges < n-1)
            return -1;
        vector<int> visited(n,false);
        vector<vector<int>> adj(n);
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,adj, visited);
            }
        }
        return cnt - 1;
    }
};