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
    void flatten(TreeNode* root) {

        if(!root || (!root->right && !root->left))
            return;
        
        TreeNode *cur = root;
        while(cur){
            if(!cur->left)
                cur = cur->right;
            else{
                TreeNode *pred = getInorderPredecessor(cur);
                if( pred && (!pred->right) )
                    pred->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
        }

    }

    TreeNode* getInorderPredecessor( TreeNode *node){
        if(!node)
            return nullptr;
        TreeNode *temp = node->left;

        while( temp && temp->right){
            temp = temp->right;
        }
        return temp;
    }

};

