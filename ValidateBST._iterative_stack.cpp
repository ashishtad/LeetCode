//////////////////////////////////////////////////////////////////////////////////
//  Valiate BST iterative using stack
//
//   Time : O(n)
//   Space : O(n)
//
//////////////////////////////////////////////////////////////////////////////////




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
        
        if( !root )
        {
            return true;
        }
        stack<TreeNode*> s;
        TreeNode *pre = NULL;
        TreeNode *cur = root;
    
        while( !s.empty() || cur )
        {
            if(cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = s.top();
                if( pre && (cur->val <= pre->val) )
                    return false;
                
                s.pop();
                pre= cur;
                cur=cur->right;
            }
        }
        return true;
        
    }
};