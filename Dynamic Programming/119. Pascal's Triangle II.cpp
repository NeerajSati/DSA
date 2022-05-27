// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

// Example 1:

// Input: rowIndex = 3
// Output: [1,3,3,1]
// Example 2:

// Input: rowIndex = 0
// Output: [1]
// Example 3:

// Input: rowIndex = 1
// Output: [1,1]
 

// Constraints:

// 0 <= rowIndex <= 33
 

// Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?


class Solution {
public:
    vector<int> getRow(int n) {
        if(n==0)
            return {1};
        if(n==1)
            return {1,1};
        vector<int> prev;
        prev.push_back(1);
        prev.push_back(1);
        
        vector<int> x;
        for(int i=1;i<=n;i++){
            x.clear();
            x.push_back(1);
            for(int j=1;j<i;j++){
                x.push_back(prev[j-1] + prev[j]);
            }
            x.push_back(1);
            
            prev = x;
        }
        return x;
    }
};
