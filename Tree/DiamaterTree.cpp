///////////////////////////////////////////////////////////
// 543. Diameter of Binary Tree
// Iterative approach
///////////////////////////////////////////////////////////


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
/* Iterative approach
* Maintain two data structure
* 1. Stack : To keep track of elements to process
* 2. Map <node,height> : To keep node and height value 
* push node in stack and make corresponding map entry as 0 indicating childs re not  processed
* In first iteration mark map entry 1 and push childs to stack and map
* In second iteration now map value is 1 so pop it as childs are processed and corresponding height are updated in map.
* so that parent now can retrieve their heights and calculate diamter
*/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(!root)
            return 0;
        int diameter =0;
        stack<TreeNode*> stack;
        map<TreeNode*,int> sMap;
        //Push the root and make the corresponding map entry val as zero i.e child are not processed yet
        stack.push(root);
        sMap.insert(make_pair(root,0));
        while( !stack.empty() )
        {
            TreeNode *temp = stack.top();
            //if temp NULL and temp child node not processed
            if( temp && ( sMap[temp]==0) )
            {   //Do not pop element here as we need this element while traversing back after processing child nodes
                //Make the corresponding map val as 1 as we are going to process child nodes
                sMap[temp] = 1;
                if( temp->left)
                {
                    //Push temp child and corresponding map entry
                    stack.push(temp->left);
                    sMap.insert(make_pair(temp->left,0));
                }
                if( temp->right)
                {
                    //Push temp child and corresponding map entry
                    stack.push(temp->right);
                    sMap.insert(make_pair(temp->right,0));
                }
            }
            //case: temp not NULL and map value is not zero i.e childs are processed and in stack
            else
            {
                //Remove temp since childs are processed
                stack.pop();
                //get left subtree height from map 
                int lheight = temp->left ? sMap[temp->left]:0;
                int rheight = temp->right ? sMap[temp->right]:0;
                //calculate height and update in map so that its parent can retrieve it
                int height = max( lheight,rheight)+1;
                sMap[temp] = height;
                diameter= max(diameter, (lheight+rheight));
            }
        }
        return diameter;    
    }
};



////////////////////////////////////////////////////////////////////////////////////////
//  RECURSIVE APPROACH
//////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        int diameter =0;
         findDiameter(root,diameter);
       return diameter; 
    }
    int findDiameter( TreeNode *root, int &diameter)
    {
        if(!root)
            return 0;
        int left = findDiameter(root->left,diameter);
        int right = findDiameter(root->right,diameter);
        
        int height = max(left,right)+1;
        //At current node diameter is leftheight + right height.
         diameter = max( left+right,diameter);
        return height;
    }
};