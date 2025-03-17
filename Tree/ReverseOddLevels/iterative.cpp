
/**
 * 2415 Reverse Odd Levels of Binary Tree
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
        std::queue<TreeNode*> q;
        q.push(root);
        /* Traverse each level and identify the odd levels */
        int curLevel = 0;
        vector<TreeNode*> rev;
        while(!q.empty()) {
            int levelSize = q.size();
            for(int i=0; i<levelSize; ++i) {
                 TreeNode *front = q.front();
                 q.pop();
               
                if(curLevel %2 == 1) {
                    rev.push_back(front);
                }
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            if(rev.size()) {
                reverseNodes(rev);
                rev.clear();
            }
            curLevel +=1;
                
        }
        return root;
    }
    void reverseNodes(vector<TreeNode*> &rev) {
        int n = rev.size();
        for(int i=0,j=n-1; i<j; ++i,--j) {
            int temp = rev[i]->val;
            rev[i]->val = rev[j]->val;
            rev[j]->val = temp;
        }
    }

};