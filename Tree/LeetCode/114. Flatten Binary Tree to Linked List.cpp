/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
 

Follow up: Can you flatten the tree in-place (with O(1) extra space)?
*/





//Approach 1: Stack O(n) memory

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
private: stack<TreeNode*> s;
    void helper(TreeNode* root){
        if(root == NULL)
            return;
        helper(root->right);
        helper(root->left);
        s.push(root);
    }
    TreeNode *createTree(){
        if(s.empty())
            return NULL;
        TreeNode* temp = s.top();
        s.pop();
        temp->left = NULL;
        temp->right = createTree();
        return temp;
    }
public:
    void flatten(TreeNode* root) {
        helper(root);
        createTree();
    }
};
    


//Approach 2: O(1)
//https://www.youtube.com/watch?v=sWf7k1x9XR4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=39

class Solution {

public:
    void flatten(TreeNode* root) {
        TreeNode  *curr = root, *prev;
        while(curr!=NULL){
            if(curr->left != NULL){
                prev = curr->left;
                while(prev->right)
                    prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
            
        }
    }
};
    

