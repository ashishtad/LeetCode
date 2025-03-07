/*
    convert Sorted Array to Binary Search Tree.
    The approach is to find the mid of array and use it as root node.
    Recursively do this for left subbarray which goes for root->left and
    root->right goes for right subarray.

    Time complexity: O(N)
    Space complexity : O(logn) + O(N) = O(N)
                     : Recursive stack space + Tree allocation
*/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBst(nums,0,nums.size()-1);
    }

    TreeNode* constructBst(const vector<int> &nums, int low, int high) {
        if(low>high)
            return nullptr;
        
        int mid = low+(high-low)/2;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = constructBst(nums, low, mid-1);
        root->right = constructBst(nums, mid+1,high);
        return root;
    }
 
};