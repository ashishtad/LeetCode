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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
       if( !root )
            return result;
       
        stack<TreeNode*> s;
        TreeNode* cur = root;
        
        while( cur )
        {
           
           //If no left , then traverse the curret and move to right subtree
            if( NULL == cur->left )
            {
                result.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                TreeNode *predecessor = FindInorderPredecessor(cur);
                if( NULL == predecessor->right )
                {
                    predecessor->right = cur;
                    result.push_back(cur->val);
                    cur = cur->left;
                }
                else //Left subtree already traversed
                {
                    predecessor->right = NULL;
                    cur = cur->right;
                }
            }
        }
        
        return result;
    }
    TreeNode* FindInorderPredecessor(TreeNode *cur)
    {
       
       if( !cur )
            return NULL;
        
        TreeNode *temp = cur->left;
        while( (temp->right) && (temp->right!=cur) )
            temp=temp->right;
        
        return temp;
    }
  
};