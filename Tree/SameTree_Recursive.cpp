////////////////////////////////////////
// 100. Same Tree
// Recursive Approach
/////////////////////////////////////////

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //if both are NULL
        if( !p && !q)
            return true;
        //if one of them are NULL
        if( !p || !q)
            return false;
        //If values are not equal
        if( p->val != q->val )
            return false;
        
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};