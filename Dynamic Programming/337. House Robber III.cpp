// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

// Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

// Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

 

// Example 1:


// Input: root = [3,2,3,null,3,null,1]
// Output: 7
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// Example 2:


// Input: root = [3,4,5,1,3,null,1]
// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// 0 <= Node.val <= 104


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

//
class Solution {
private:
    int helper(TreeNode* root, bool cando, map<pair<TreeNode *,bool>,int> &mpp){
        if(root == NULL)
            return 0;
        if(mpp.find({root,cando}) != mpp.end())
            return mpp[{root,cando}];
        
        int ltt = helper(root->left,true,mpp);
        int rtt = helper(root->right,true,mpp);
        if(!cando){
            return ltt + rtt;
        }
        int ltf = helper(root->left,false,mpp);
        int rtf = helper(root->right,false,mpp);
        
        int ifdo = root->val + ltf + rtf;
        int ifnotdo = ltt + rtt;
        return mpp[{root,cando}] = max(ifdo,ifnotdo);
    }
public:
    int rob(TreeNode* root) {
        map<pair<TreeNode *,bool>,int> mpp;
        return helper(root,true,mpp);
    }
};



class Solution {
private:
    //pair<int,int> stores <ifRobbed, ifNotRobbed>
    
    pair<int,int> helper(TreeNode* root){
        if(root == NULL)
            return {0,0};
        
        pair<int,int> lt = helper(root->left);
        pair<int,int> rt = helper(root->right);

        int ifRobbed = lt.second + rt.second + root->val;
                    //notRobbedLeft + notRobbedRight + currNode
        int ifNotRobbed = max(lt.first,lt.second) + max(rt.first,rt.second);
        
        return {ifRobbed,ifNotRobbed};
    }
public:
    int rob(TreeNode* root) {
        pair<int,int> ans = helper(root);
        return max(ans.first,ans.second);
    }
};
