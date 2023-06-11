
//////////////////////////////////////////////////////////////////////////////////////////////
//  100. Same Tree
//  Iterative Approach
//  Complexity:
//  Time:O(N) since each node is visited exactly once.
//  Space: O(log(N)) in the best case of completely balanced tree 
//      O(N) in the worst case of completely unbalanced tree, to keep a queue
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool retVal = true;
       if( !checkSame(p,q) )
            return false;
        queue<TreeNode*> pqu;
        queue<TreeNode*> qqu;
        
        pqu.push(p);
        qqu.push(q);
          
        while( !pqu.empty() && !qqu.empty() )
        {
            TreeNode *p = pqu.front();
            pqu.pop();
            TreeNode *q = qqu.front();
            qqu.pop();
            if( !checkSame(p,q) )
            {
                retVal = false;
                break;
            }
            if( p && q)
            {
                pqu.push(p->left);
                qqu.push(q->left);
                 pqu.push(p->right);
                qqu.push(q->right);
            } 
        }
        if( !pqu.empty() || !qqu.empty() )
            retVal = false;
        return retVal;
       
    }
    bool checkSame(TreeNode *p,TreeNode *q)
    {
        if( NULL==p && NULL==q)
            return true;
        if( NULL==p || NULL==q)
            return false;
        
        if( p->val !=q->val)
            return false;
        else
            return true;
    }
};