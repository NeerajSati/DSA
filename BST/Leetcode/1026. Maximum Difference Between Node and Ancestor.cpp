/*
Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

 

Example 1:


Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
Example 2:


Input: root = [1,null,2,null,0,3]
Output: 3
 

Constraints:

The number of nodes in the tree is in the range [2, 5000].
0 <= Node.val <= 105
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
public:
    int maxAncestorDiff(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return helper(root, root->val, root->val);
    }
    int helper(TreeNode* node, int currMax, int currMin){
        if(node == NULL){
            return currMax - currMin;
        }
         currMax = max(currMax, node->val);
         currMin = min(currMin, node->val);
         int left = helper(node->left,currMax,currMin);
         int right = helper(node->right,currMax,currMin);
         return max(left, right);
    }
};


//old approach
typedef tuple<TreeNode*, int, int> tup;

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) 
            return 0;

        stack <tup> s;
        int max_val = root->val, min_val = root->val, max_diff = 0;
        s.push(make_tuple(root, root->val, root->val));
        while(!s.empty()){
            tup cur_tup = s.top();
            s.pop();

            auto node = get<0>(cur_tup);
            int cur_max = get<1>(cur_tup), cur_min = get<2>(cur_tup);
            if(node->right){
                s.push(make_tuple(node->right, max(node->right->val, cur_max), min(node->right->val, cur_min)));
            }

            if(node->left){
                s.push(make_tuple(node->left, max(node->left->val, cur_max), min(node->left->val, cur_min)));
            }

            if(node->left==nullptr && node->right== nullptr){
                if (cur_max - cur_min > max_diff) 
                    max_diff = cur_max - cur_min;
            }

        }   

        return max_diff;
    }
    
};
