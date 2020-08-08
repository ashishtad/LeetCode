///////////////////////////////////////////////////////////////////////////////////
//
//  MORRIS INORDER TRAVERSAL
//  Time complexity O(n)
//  Space complexity O(1)
//////////////////////////////////////////////////////////////////////////




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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if( !root )
            return result;
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
                    predecessor->right=cur;//Link to cur so as to traverse back
                    cur=cur->left;
                }
                //Already traversed the left subtree
                else
                {
                     predecessor->right=NULL;
                     result.push_back(cur->val);
                     cur=cur->right; //Go back to root
                }
            }
        }//while end
        return result;
    }
    //Inorder predecessor is the right most child of left subtree of the corresponding node.
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