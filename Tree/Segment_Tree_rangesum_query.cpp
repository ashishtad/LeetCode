////////////////////////////////////////////////////////////////////////
//  SEGMENT TREE
// 307. Range Sum Query - Mutable
////////////////////////////////////////////////////////////////////////////

struct Node
{
  int sum,start,end;
    Node *left;
    Node *right;
    Node(int a,int b)
    {
        start =a;
        end = b;
        left = NULL;
        right = NULL;
    }
};
class NumArray {
public:
    Node *root=NULL;
    NumArray(vector<int>& nums) {
        int numSize = nums.size();
        if( 0 <numSize )
        {
            root = buildSegmentTree(0,numSize-1,nums);
        }
    }
    Node* buildSegmentTree(int low,int high,const vector<int>& nums)
    {
        if( low> high ) return NULL;
        Node *newNode= new Node(low,high);
        //leaf node has been reached i.e[0-0] [1-1]
        if(low==high)
        {
            //Assign the leaf node with the index of original array
            newNode->sum = nums[low];
            return newNode;
        }
        int mid = low+(high-low)/2;
        newNode->left = buildSegmentTree(low,mid,nums);//left child/ subtree
        newNode->right = buildSegmentTree(mid+1,high,nums); //right child/subtree
        //Assign the intermediate parent node with sum of left an dright child node
        newNode->sum = newNode->left->sum+newNode->right->sum;
        return newNode;
    }
    void update(int i, int val) {
        
        updateSegmentTree(root,i,val);
    }
    int updateSegmentTree(Node *root,int index,int val)
    {
        if( !root ) return 0;
        //update the root with new val only if index matches
        if( (root->start) == (root->end) && index==root->start ) 
        {
            
            //calculate the diff between new val and the existing.so that all the prent nodes will be updated by diff
            int diff = val-root->sum;
            root->sum = val;
            return diff;
        }
        int mid = (root->start+root->end)/2;
        int diff = INT_MIN;
        if( index<=mid )
        {
            diff = updateSegmentTree(root->left,index,val);
        }
        else
            diff = updateSegmentTree(root->right,index,val);
        //Update the parent node by adding the diff
        root->sum +=diff;
        return diff;
    }
    
    int sumRange(int i, int j) {
        
        return query(root,i,j);
    }
    int query(Node *root,int l,int r)
    {
       
        //Case-1:Tree node range completely lies exactly at l and r
        if( root->start==l && root->end==r ) return root->sum;
        int mid = (root->start+root->end)/2; 
        //Case-2:Entire range lies one half of tree i.e left or right subtree
        // r<=mid i.e l-r lies in left subtree
        if( r<=mid ) return query(root->left,l,r);
        //l>mid i.e l-r lies in right subtree
        else if( l>mid ) return query(root->right,l,r);
        //Case-3 : node range overlaps l and r that is our result lies in sub part of left ree and right subtree. 
		//We have to move to left subtree and right subtree as well by dividing the input range
        else return query(root->left,l,mid)+query(root->right,mid+1,r);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */