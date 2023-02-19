////////////////////////////////
//	110. Balanced Binary Tree
///////////////////////////////

/*
STEP - 1 : Get the Middle of the sorted array and make it root node.

STEP - 2 : Recursively do same for left half and right half of the array.

Get the middle of left half array and make it left child of the root created in step 1.
Get the middle of right half and make it right child of the root created in step 1
*/
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