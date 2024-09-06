

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
        stack<TreeNode*> s;
        s.push(root);
        root=root->left;
        
        while( !s.empty() ||root  ) 
        {
            while(root)
            {
                s.push(root);
                root=root->left;
            }
            TreeNode *top = s.top();
            s.pop();
            
            if( --k ==0 )
            {
                result=top->val;
                break;
            }
            root = top->right;
        }
        return result;
    }
};