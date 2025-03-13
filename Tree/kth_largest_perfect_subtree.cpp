

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
 * 1.For a perfect subtree of a node, all the left subtree and the right subtree must be perfect subtrees.

2. How to figure out perfect subtree?

  - A leaf node is a perfect subtree.
  - Node with a single child is not a perfect subtree.
  - Left subtree size(count of nodes) and right subtree size must be same.
3. If a subtree is not perfect then all the ancestor nodes can not form a perfect subtree.

Approach:
Check if tree is perfect if it is so then return the size of subtree.
If not return -1
In end sort in non increasing order and return k-1 element

Time complexity:
O(n) + O(nlogn) : For tree taversal + sorting
Space complexity: O(n)+O(n) : Traversal and storage of size
 * 
 */
class Solution {
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        if(!root)
            return -1;
        vector<int> res;
        checkPerfectSubtree(root, res);
        if(res.size() >= k) {
            std::sort(res.begin(), res.end(), std::greater<int>());
            return res[k-1];
        }
        return -1;
    }
    /* Returns -1 for non-perfect subtrees or the size (number of nodes) for perfect subtrees */
    int checkPerfectSubtree(TreeNode *root, vector<int> &res) {

        if(!root)
            return 0;
        /* Leaf node */
        if( !root->left && !root->right){
            res.push_back(1);
            return 1;
        }
            
        int lsize = checkPerfectSubtree(root->left,res);
        int rsize = checkPerfectSubtree(root->right,res);

      /* If both subtrees are perfect and have the same size */
        if (lsize != -1 && rsize != -1 && lsize == rsize) {
            int current_size = lsize + rsize + 1;
            res.push_back(current_size);
            return current_size;
        }
       return -1;
    }
};