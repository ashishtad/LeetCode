
/*
Lowest Common Ancestor of a Binary Tree

21/09/2024
Approach :

Do a post order traversal. Why Post order?
Beacuse here we need to find the root node which is common ancesstor of given nodes.
So first we have to visit left and right node and check if those are given input nodes.
Then we have to come back to root node. This is satisfied by post order traversal.


*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if( !root || (root==p) || (root == q) )
            return root;
        
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);
        /* LCA Found */
        if( left && right)
            return root;
		/* return non null one if any to carry forward */
        return left != nullptr ? left : right;
    }
};