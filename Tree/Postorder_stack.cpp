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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if( !root)
            return result;
        TreeNode *last = NULL;
        stack<TreeNode*> s;
        TreeNode *cur = root;
        while( cur || !s.empty() )
        {
            if( cur )
            {
                s.push(cur);
                cur=cur->left;
            }
            else
            {
                TreeNode *temp = s.top();
                if( NULL == temp->right )
                {
                    last = temp;
                    result.push_back(temp->val);
                    s.pop();
                }
                else
                {
                    if( last == temp->right)
                    {
                        last = temp;
                        result.push_back(temp->val);
                        s.pop();
                    }
                    else
                        cur = temp->right;
                }
            }
        }//end of while
        return result;
        
    }
  
};