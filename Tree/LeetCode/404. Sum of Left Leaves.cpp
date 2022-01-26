// Given the root of a binary tree, return the sum of all left leaves.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
// Example 2:

// Input: root = [1]
// Output: 0

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
    int sum=0;
    void sumLeft(TreeNode* root, bool isLeft){
        if(root->left == NULL && root->right == NULL && isLeft)
            sum+=root->val;
        if(root->left)
            sumLeft(root->left,true);
        if(root->right)
            sumLeft(root->right,false);
        return;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
            return 0;
        sumLeft(root,false);
        return sum;
    }
    
};
