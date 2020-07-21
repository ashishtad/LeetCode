///////////////////////////////////////////////////////////////////////////
//  98. Validate Binary Search Tree
// RECURSIVE SOLUTION
// Time complexity: O(n) : Visit each node exactly once
// Space Complexity: O(n) : Stack grows n times for each recursive call
// Solved : 21/7/2020
// Author: Ashish Tad
///////////////////////////////////////////////////////////////////////


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
    bool isValidBST(TreeNode* root) {
        
            if(!root)
                return true;
        
        return Validate(root,NULL,NULL);
        
    }
    bool Validate( TreeNode *node, TreeNode* upper,TreeNode* lower)
    {
        if(!node)
            return true;
        int val = node->val;
        
        if( upper &&(val>=upper->val) )
            return false;
        if( lower && (val<=lower->val))
            return false;
        //In BST, right node should be greater than node
        //So lower should be node->val
        if( !Validate(node->right,upper,node))
            return false;
        //Similarly left node should be less than node
        //so upper should be node->val
        if( !Validate(node->left,node,lower))
            return false;
        
        return true;
    }
};