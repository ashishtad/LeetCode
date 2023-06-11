///////////////////////////////////////////////////////////
//	112. Path Sum
// Complexity
// Time: O(logn) Worst case :O(n)
// Space : O(logn) worst case : O(n)
//
////////////////////////////////////////////////////////////




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
    bool hasPathSum(TreeNode* root, int sum) {
        return FindPath(root,sum);
    }
    bool FindPath(TreeNode *root,int sum)
    {
        if(!root)
            return false;
        sum-=root->val;
        //check for sum only if leaf node has been reached
        if((!root->left) && (!root->right)) 
        {
            if(sum==0 )
                return true;
            else
                return false;
        }
        if(FindPath(root->left,sum))
            return true;
        if( FindPath(root->right,sum) )
            return true;
        return false;
    }
};