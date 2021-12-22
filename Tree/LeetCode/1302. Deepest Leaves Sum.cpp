/*
Given the root of a binary tree, return the sum of values of its deepest leaves.
 

Example 1:


Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 100
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

//Queue Method
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (root == NULL)
    {
        return 0;
    }
    queue<TreeNode *> qu;
    qu.push(root);
    int sumOfCurrLevel = 0;
    while (!qu.empty())
    {
        int size = qu.size();
        sumOfCurrLevel = 0;
        while (size--)
        {
            TreeNode *head = qu.front();
            qu.pop();
            sumOfCurrLevel += head->val;
            if (head->left != NULL)
            {
                qu.push(head->left);
            }
            if (head->right != NULL)
            {
                qu.push(head->right);
            }
        }
    }
    return sumOfCurrLevel;
    }
};

// Recursive method

class Solution {
public:
    int maxLevel = INT_MIN,sum=0;
    void deepestLeaves(TreeNode* root, int level) {
        if (root == NULL)
        {
        return ;
        }
        if(level>maxLevel){
            maxLevel=level;
            sum=root->val;
        }
        else if(level==maxLevel){
            sum+=root->val;
        }
        deepestLeaves(root->left,level+1);
        deepestLeaves(root->right,level+1);
    }
    int deepestLeavesSum(TreeNode* root) {
    deepestLeaves(root,0);
    return sum;
    }
};
