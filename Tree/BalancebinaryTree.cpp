////////////////////////////////////////
//
//110. Balanced Binary Tree
///////////////////////////////////////


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        
        if( !root )
            return true;
        //single node
        if( !root->left && !root->right )
            return true;
        if( abs( getHeight(root->left,0) - getHeight(root->right,0) )<=1 )
            return isBalanced( root->left) && isBalanced(root->right);
        
        return false;
    }
    int getHeight(TreeNode *node,int height)
    {
         if( !node)
            return height;
        int leftHeight = getHeight(node->left,height+1);
        int rightHeight = getHeight(node->right,height+1);
        
        return max(leftHeight,rightHeight);
    }

};