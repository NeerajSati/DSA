// You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

// Return the minimum number of cameras needed to monitor all nodes of the tree.

 

// Example 1:


// Input: root = [0,0,null,0,0]
// Output: 1
// Explanation: One camera is enough to monitor all nodes if placed as shown.
// Example 2:


// Input: root = [0,0,null,0,null,0,null,null,0]
// Output: 2
// Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// Node.val == 0

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
    // return 0 = node has no camera and not monitored
    // return 1 = node has no camera but is monitored 
    // return 2 = node has a camera is obviously monitored
private:
    int helper(TreeNode* root, int &ans){
        if(!root){
            return 1;
        }
        int left = helper(root->left,ans);
        int right = helper(root->right,ans);
        //if left has no camera and not monitored or right is same
        if(left == 0 || right == 0){
            ans++;
            return 2;
        }
        // if left has camera or right has camera
        if(left == 2 || right == 2){
            return 1;
        }
        
        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        //if root has no camera and not monitored then we need camera at root
        int ans = 0;
        if(helper(root,ans) == 0)
            ans++;
        
        return ans;
    }
};
