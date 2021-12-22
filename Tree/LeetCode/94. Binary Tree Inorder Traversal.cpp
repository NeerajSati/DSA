/*
Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
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

//Wild Guess
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        if(root == NULL)
            return arr;
        vector<int> v2 = inorderTraversal(root->left);
        arr.insert(arr.end(), v2.begin(), v2.end());
        arr.push_back(root->val);
        v2 = inorderTraversal(root->right);
        arr.insert(arr.end(), v2.begin(), v2.end());
        return arr;
    }
};

//Using Stack
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode *> st;
        TreeNode *curr = root;
        while(curr!=NULL || st.empty()==false){
            while(curr!=NULL){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            v.push_back(curr->val);
            curr = curr->right;
        }
        return v;
    }

//Recursive
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        return v;
    }
private: 
    void inorder(TreeNode *root, vector<int> &v){
        if(root){
            inorder(root->left,v);
            v.push_back(root->val);
            inorder(root->right,v);
        }
    }
