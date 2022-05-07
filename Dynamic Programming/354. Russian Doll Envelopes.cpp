/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

 

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
 

Constraints:

1 <= envelopes.length <= 105
envelopes[i].length == 2
1 <= wi, hi <= 105
*/

// O(n^2) approach DP
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        int lis[n];
        int ans = INT_MIN;
        sort(envelopes.begin(),envelopes.end());
        for(int i=0;i<n;i++){
            int max = 0;
            for(int j=0;j<i;j++){
                if(envelopes[j][1] < envelopes[i][1] && envelopes[j][0] < envelopes[i][0]){
                    if(lis[j] > max)
                        max = lis[j];
                }
            }
            lis[i] = max+1;
            if(lis[i] > ans)
                ans = lis[i];
        }
        return ans;
    }
};
