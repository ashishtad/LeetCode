/////////////////////////////////////////////////////////
//
// LEVEL ORDER TRAVERSAL 
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