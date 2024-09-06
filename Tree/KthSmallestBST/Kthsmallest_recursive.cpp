
/*
    Approach is to do inorder traversal as it sort
    the array in ascending order.
    Complexity.
    Time :O(n): worst case
    Space: O(n): worst case

    For average case space complxity would be O(logn) (height of tree)
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
    int kthSmallest(TreeNode* root, int k) {
        int result =0;
        if( !root )
        {
            return result;
        }
        int count =0;
        inorder(root,k,result);
        return result;
    }
    void inorder( TreeNode *root,int &k,int &result)
    {
        
        if( !root )
            return ;
        inorder(root->left,k,result);
        if(k<=0)
            return;
        //count += 1;
        if( --k == 0 )
        {
            result = root->val;
            return ;
        }
        inorder(root->right,k,result);
    }
        
};