
/*
2415. Reverse Odd Levels of Binary Tree

*/

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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return nullptr;

        reverse(root->left, root->right, 1);
        return root;
    }

    void reverse(TreeNode *leftNode, TreeNode *rightNode, int level) {

        if(!leftNode || !rightNode) return;

        if(level%2 == 1) {
            int temp = leftNode->val;
            leftNode->val = rightNode->val;
            rightNode->val = temp;
        } 
        reverse(leftNode->left, rightNode->right, level+1);
        reverse(leftNode->right, rightNode->left, level+1);
    }
};