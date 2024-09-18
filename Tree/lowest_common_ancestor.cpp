/*
     Lowest Common Ancestor of a Binary Search Tree
     18/09/2024

     BST has following traits:

    Both root's subtrees also are binary (it is not important for solution, but just FYI);
    All LEFT child nodes of LEFT subtree have values less or equal the value of the current node.
    All RIGHT child nodes of RIGHT subtree have values greater the value of the current node.
    Keeping in mind these traits we can start traverse tree in depth (DFS).

    Main idea:

    If current node value > p.value and q.value, hence according to trait №2 above, 
    it's useless search common node for p and q in the right subtree -> continue traverse next node in left subtree.
    If current node value < p.value and q.value, hence according to trait №3 above,
    it's useless search common node for p and q in the left subtree -> continue traverse next node in right subtree
    If according to statements above it's useless search common node in both left and right subtree, 
    it means that you are in a right place, you have found Lowest Common Ancestor.
    Using this idea we can solve problem both iteratively and recursively.
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root)
            return nullptr;

        /* P and q are in left subtree */
        if( (root->val > p->val) && (root->val > q->val) )
           return lowestCommonAncestor(root->left, p, q);
        else if ((root->val < p->val) && (root->val < q->val) )
           return lowestCommonAncestor(root->right, p, q);

        /* Found the LCA */ 
            return root;
    }
};