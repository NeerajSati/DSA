/*
Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105
*/

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
    vector<int> v;
    void inorder(TreeNode *root) {
        if(root==NULL)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    bool twoSum(int k, int min, int max){
        if(min>=max)
            return false;
        int ans = v[min]+v[max];
        if(ans == k)
            return true;
        else if(ans < k)
            return twoSum(k,min+1,max);
        else if(ans > k)
            return twoSum(k,min,max-1);
        return false;
            
    }
public:
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        return twoSum(k,0,v.size()-1);
    }
};
