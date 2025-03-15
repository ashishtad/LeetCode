/*
   199. Binary Tree Right Side View
   Given the root of a binary tree, imagine yourself standing on the right side of it, 
   return the values of the nodes you can see ordered from top to bottom.
   Approach
   ========

   1. Traverse the tree via level order.
   2. At each level we know that the last element needs to be processed.
   3. Maintain queue to store the nodes of a current level so that the right most or last element 
      is at the last of queue.
   Complexity
   ==========
   Time: O(n)
   Space: O(n) +O(n)=O(n) For traversal and extra space for storage
*/

 std::vector<int> rightSideView(TreeNode* root){

    if(!root)  return {};
    std::vector<int> res;
    std::queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        int n = q.size();
        while(n--) {

            TreeNode *front = q.front();
            q.pop();
            /* Process the last node of the level */
            if(0 == n)
                res.push_back(front->val);
            /* Push left first and then right */
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);

        }
    }
    return res;
 }
