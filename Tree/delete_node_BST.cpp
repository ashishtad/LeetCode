class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if (!root) return nullptr;
        if (root->val == key) return deleteAndReframeBst(root);

        TreeNode *cur = root;
        while (root) {
            /* Key is in left subtree */
            if (root->val > key) {
                if (root->left && root->left->val == key) {
                    root->left = deleteAndReframeBst(root->left);
                    break;
                 } else {
                    root = root->left;
                }
            } else if (root->val < key) {
                if (root->right && root->right->val == key) {
                    root->right = deleteAndReframeBst(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return cur;
    }

    TreeNode* deleteAndReframeBst(TreeNode *root) {
        if (!root->left) return root->right;
        else if (!root->right) return root->left;

        TreeNode *rightChild = root->right;
        TreeNode *pred = getInorderPred(root->left);
        pred->right = rightChild;

        return root->left;
    }

    TreeNode* getInorderPred(TreeNode *root) {
        if (!root->right) return root;
        TreeNode *temp = root->right;
        while (temp && temp->right) temp = temp->right;

        return temp;
    }
};