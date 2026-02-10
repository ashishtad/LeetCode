class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;

        TreeNode* xParent = nullptr;
        TreeNode* yParent = nullptr;

        int xdepth = getDepth(root, x, 0, xParent);
        int ydepth = getDepth(root, y, 0, yParent);
        if (xdepth == ydepth && xParent != yParent) return true;

        return false;
    }
    /* This function gets the depth of val and the parent of it */
    int getDepth(TreeNode* root, int val, int depth, TreeNode* &parent) {
        if (!root) return -1;

        if (root->val == val) return depth;

        int leftDepth = getDepth(root->left, val, depth+1, parent);
        /* Early exit if found on left subtree - no right tree traversal.
           Note: Parent must populated once, it should not unwind until root.
         */
        if (leftDepth != -1) {
            if (!parent) parent = root;
            return leftDepth;
        }
        int rightDepth = getDepth(root->right, val, depth+1, parent);
        if (rightDepth != -1 && !parent) parent = root;

        return rightDepth;
    }
};