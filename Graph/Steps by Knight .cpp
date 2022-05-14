/*
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position coordinates of Knight have been given according to 1-base indexing.

 

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
Explanation:

Knight takes 3 step to reach from 
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
 

 

Your Task:
You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the initial position of Knight (KnightPos), the target position of Knight (TargetPos), and the size of the chessboard (N) as input parameters and returns the minimum number of steps required by the knight to reach from its current position to the given target position.

 

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).

 

Constraints:
1 <= N <= 1000
1 <= Knight_pos(X, Y), Targer_pos(X, Y) <= N
*/


class Solution 
{
    private:
    bool isPossible(int x, int y, int N,vector<vector<bool>> &visited){
        if(x<N && y<N && x>=0 && y>=0 && !visited[x][y]){
            return true;
        }
        return false;
    }
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int kx = KnightPos[0] - 1, ky = KnightPos[1] - 1;
	    int tx = TargetPos[0] - 1, ty = TargetPos[1] - 1;
	    
	    if(kx == tx && ky == ty)
	        return 0;
	    
	    vector<vector<bool>> visited(N,vector<bool>(N,false));
	    queue<pair<int,int>> q;
	    q.push({kx,ky});
	    int ans = 0;
	    while(!q.empty()){
	        ans++;
	        int size = q.size();
	        while(size != 0){
	            pair<int,int> front = q.front();
	            q.pop();
	            size--;
	            int x = front.first,y = front.second;
	            int xpos[8] = {1,1,-1,-1,2,2,-2,-2};
	            int ypos[8] = {2,-2,2,-2,1,-1,1,-1};
	            for(int i = 0;i<8;i++){
	                int xx = x+xpos[i];
	                int yy = y+ypos[i];
	                if(xx == tx && yy == ty)
	                return ans;
	                if(isPossible(xx,yy,N,visited)){
	                    visited[xx][yy] = true;
	                    q.push({xx, yy});
	                }
	            }
	        }
	    }
	    return -1;
	}
};
