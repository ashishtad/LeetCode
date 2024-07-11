/*
 *	109. Convert Sorted List to Binary Search Tree
 *  11/07/2024
 */




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {

        if(!head)
            return nullptr;
        return buildBST(head,nullptr);
    }

    TreeNode* buildBST( ListNode *head, ListNode *tail){

        /* When list is divided and reach to asingle node,
         head == tail */
        if( !head || (head==tail))
            return nullptr;
        /* Find middle of linked list */
        ListNode *mid = findMidNode(head,tail);

        TreeNode* new_node = new TreeNode(mid->val);
        new_node->left = buildBST(head,mid);
        new_node->right = buildBST(mid->next,tail);

        return new_node;
    }

    ListNode* findMidNode(ListNode* node, ListNode *tail){
        if(!node)
            return nullptr;
        /* Single node in list */
        if( !node->next)
            return node;

        ListNode* slow = node;
        ListNode* fast = node;

        while( (fast!=tail) && (fast->next != tail) ){

            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; 
    }
};