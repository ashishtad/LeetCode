/*
   199. Binary Tree Right Side View
   Given the root of a binary tree, imagine yourself standing on the right side of it, 
   return the values of the nodes you can see ordered from top to bottom.
   Approach
   ========

   1. Traverse the right subtree first as we need to print the right view.
   2. Maintain a level pointer to know which level we are traversing currently.
   3. If level is greater than max level reached at the point then process it.

   Complexity
   ==========
   Time: O(n)
   Space: O(n) +O(n)=O(n) For traversal and extra space for storage
*/

 vector<int> rightSideView(TreeNode* root){

    if(!root)  return {};
    vector<int> res;
    int maxlevel = 0;
    
    traverseTree(root, 1, maxlevel, res);
    return res;
 }

 void traverseTree( TreeNode *root, int level,
                     int &maxlevel, vector<int> &res) {


      if(!root) return;
      if(level>maxlevel) {
         res.push_back(root->val);
         maxlevel = level;
      }
      /* Note : traverse right subtree first */

      traverseTree(root->right, level+1, maxlevel, res);
      traverseTree(root->left, level+1, maxlevel, res);
}