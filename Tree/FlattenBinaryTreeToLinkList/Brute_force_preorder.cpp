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
    void flatten(TreeNode* root) {

        if(root){
            /* Do a preorder traversal and store the nodes in a vector */
            vector<TreeNode*> nodes;
            preOrderTraverse(root,nodes);
            if(nodes.size()>0) 
                /* Traverse the nodes in list and connect them to form the linked list */
                flattenNodeList(nodes);
            
        }
        
    }
 void preOrderTraverse( TreeNode *root, vector<TreeNode*> &nodes){

    if(!root)
        return;
    nodes.push_back(root);
    preOrderTraverse(root->left,nodes);
    preOrderTraverse(root->right,nodes);
}
void flattenNodeList(vector<TreeNode*> nodes) {
  
    for( int itr = 0; itr < nodes.size()-1; ++itr){
        TreeNode *cur_node = nodes[itr];
        TreeNode *next_node = nodes[itr+1];

        cur_node->left = nullptr;
        cur_node->right = next_node;

    }
}
};

