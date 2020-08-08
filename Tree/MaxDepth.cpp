///////////////////////////////////////////////////////////////////////////////////
//  Maximum Depth of Binary Tree
//  Top Down Approach solution
// Solved: 8/8/2020
// 
////////////////////////////////////////////////////////////////////////////////





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
    int maxDepth(TreeNode* root) {
        
        if(!root)
            return 0;
        //single node in a tree
        if( !(root->left) && !(root->right) )
            return 1;
      
      int depth =  FindDepth(root,0);
        return depth;
        
    }
    int FindDepth( TreeNode *root, int curDepth )
    {
        if(!root)
            return curDepth;
        int left = FindDepth(root->left,curDepth+1);
        int right = FindDepth(root->right,curDepth+1);
        return (max(left,right));
    }
};