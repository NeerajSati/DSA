/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?
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

//Recursive
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preorder(root,v);
        return v;
    }
    void preorder(TreeNode* root, vector<int> &v){
        if(root==NULL)
            return;
        v.push_back(root->val);
        preorder(root->left, v);
        preorder(root->right, v);
    }
};


//iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==NULL)
            return v;
        stack<TreeNode *> s;
        TreeNode *curr = root;
        while(curr!=NULL || s.empty()==false){
            while(curr!=NULL){
                v.push_back(curr->val);
                if(curr->right!=NULL)
                    s.push(curr->right);
                curr = curr->left;
            }
             if(s.empty()==false){
                 curr = s.top();
                 s.pop();
             }   
        }
        return v;
    }
};
