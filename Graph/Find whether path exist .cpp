/*
Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.
 

Example 1:

Input: grid = {{3,0,3,0,0},{3,0,0,0,3}
,{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
Output: 0
Explanation: The grid is-
3 0 3 0 0 
3 0 0 0 3 
3 3 3 3 3 
0 2 3 0 0 
3 0 0 1 3 
There is no path to reach at (3,1) i,e at 
destination from (4,3) i,e source.
Example 2:

Input: grid = {{1,3},{3,2}}
Output: 1
Explanation: The grid is-
1 3
3 2
There is a path from (0,0) i,e source to (1,1) 
i,e destination.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function is_Possible() which takes the grid as input parameter and returns boolean value true if there is a path otherwise returns false.
 

Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)
 

Constraints:
1 ≤ n ≤ 500
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{   
    private:
        bool isThere(vector<vector<int>> &grid,int x,int y){
            if(x<grid.size() && y<grid[0].size() && x>=0 && y>=0 && grid[x][y] != 0)
                return true;
            else
                return false;
        }
        bool dfs(vector<vector<int>> &grid,int i,int j){
            if(isThere(grid,i,j)){
                if(grid[i][j] == 2)
                    return true;
                grid[i][j] = 0;
                return dfs(grid,i+1,j) || dfs(grid,i-1,j) || dfs(grid,i,j+1) || dfs(grid,i,j-1);
            }
            
            return false;
        }
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    if(dfs(grid,i,j))
                        return true;
                    else
                        return false;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends
