// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

 

// Example 1:


// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]
// Example 2:


// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// mat[i][j] is either 0 or 1.
// There is at least one 0 in mat.


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(),n = mat[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0)
                    q.push({i,j});
                else
                    mat[i][j] = -1;
            }
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int rowArr[4] = {0,1,0,-1};
            int colArr[4] = {1,0,-1,0};
            for(int i=0;i<4;i++){
                int rowHere = r + rowArr[i];
                int colHere = c + colArr[i];
                if(rowHere < 0 || colHere < 0 || rowHere >= m || colHere >= n || mat[rowHere][colHere] != -1)
                    continue;
                mat[rowHere][colHere] = mat[r][c] + 1;
                q.push({rowHere,colHere});
            }
        }
        return mat;
    }
};
