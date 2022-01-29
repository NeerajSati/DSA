// Given the root of a binary tree, return the maximum width of the given tree.

// The maximum width of a tree is the maximum width among all levels.

// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.

// It is guaranteed that the answer will in the range of 32-bit signed integer.

 

// Example 1:


// Input: root = [1,3,2,5,3,null,9]
// Output: 4
// Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
// Example 2:


// Input: root = [1,3,null,5,3]
// Output: 2
// Explanation: The maximum width existing in the third level with the length 2 (5,3).
// Example 3:


// Input: root = [1,3,2,5]
// Output: 2
// Explanation: The maximum width existing in the second level with the length 2 (3,2).
 

// Constraints:

// The number of nodes in the tree is in the range [1, 3000].
// -100 <= Node.val <= 100

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        int ans = 0;
        while(!q.empty()){
            int n = q.size();
            int min = q.front().second;
            int first,last;
            for(int i=0;i<n;i++){
                int curr = q.front().second - min;
                TreeNode *node = q.front().first;
                q.pop();
                if(i==0)
                    first = curr;
                if(i==n-1)
                    last = curr;
                if(node->left)
                    q.push({node->left,curr *2 +1});
                if(node->right)
                    q.push({node->right,curr *2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};
