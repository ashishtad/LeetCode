///////////////////////////////////////////////
//	103. Binary Tree Zigzag Level Order Traversal
//
//
/////////////////////////////////////////////////////

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> vResult;
        if( !root )
            return vResult;
        
        Traverse(root,0,vResult);
        int size=vResult.size(); 
       //reverse the alternate level nodes
        for(int row=1; row<size;row+=2) 
            std::reverse(vResult[row].begin(),vResult[row].end());
        
        return vResult;
    }
    void Traverse(TreeNode *root, int level,vector<vector<int>> &vResult )
    {
        if(!root)
            return;
        if( level == vResult.size())
        {
            vResult.push_back(vector<int>());
        }
        vResult[level].push_back(root->val);
        Traverse(root->left,level+1,vResult);
        Traverse(root->right,level+1,vResult);
    }
};


//Solution-2

lass Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> vResult;
        if( !root )
            return vResult;
        
        Traverse(root,0,vResult);

        return vResult;
    }
    void Traverse(TreeNode *root, int level,vector<vector<int>> &vResult )
    {
        if(!root)
            return;
        if( level == vResult.size())
        {
            vResult.push_back(vector<int>());
        }
        if( level%2 ==0)
            vResult[level].push_back(root->val);
        //For the odd levels insert the elements at begin of vector.So that it will be in reverse order.
        else
            vResult[level].insert(vResult[level].begin(),root->val);

        Traverse(root->left,level+1,vResult);
        Traverse(root->right,level+1,vResult);
        
        
    }
};