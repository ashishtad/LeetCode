/////////////////////////////////////////////////////////
//
// LEVEL ORDER TRAVERSAL
// Time complexity: O(n)
//The algorithm performs a level order traversal of the binary tree. This means it visits each node once, starting from the root and going level by level.
//In the worst case, it visits all "n" nodes of the tree 
// Space complexity: O(h) h: height of tree
// The space complexity is O(h), where "h" is the height of the tree.
//This is because the recursive calls create a call stack. In the worst case, when the tree is highly unbalanced (skewed), the height of the call stack can be equal to the height of the tree.
// DATE:7/08/2020
/////////////////////////////////////////////////////////




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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        if(!root)
            return result;
        //TreeNode *temp = root;
        traverse(root,0,result);
        return result;
    }
    void traverse( TreeNode *root,int level,vector<vector<int>> &result)
    {
        if( !root )
            return;
        //Add an vector to result if the level is same as size of vector.
        //To accomodate current level elements
        if( result.size()==level )
        {
            result.push_back(vector<int>());
        }
            
        result[level].push_back(root->val);  
        traverse(root->left,level+1,result);
        traverse(root->right,level+1,result);
    }
};