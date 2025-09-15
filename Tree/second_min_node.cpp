/*
	Second Minimum Node in Binary Tree.
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
    int findSecondMinimumValue(TreeNode* root) {

        if (!root) return -1;
        long minVal = root->val, secondMinVal = LONG_MAX;
        dfs(root, minVal, secondMinVal);
        return secondMinVal == LONG_MAX ? -1 : (int)secondMinVal;
        
    }
    void dfs(TreeNode *root, long minVal, long &secondMinVal) {
        if (!root) return;

        if (root->val > minVal && root->val < secondMinVal) secondMinVal = root->val;

        dfs(root->left, minVal, secondMinVal);
        dfs(root->right, minVal, secondMinVal);
    }
};