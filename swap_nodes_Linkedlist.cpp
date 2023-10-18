/**
 * 1721. Swapping Nodes in a Linked List
 * You are given the head of a linked list, and an integer k.
 *  Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        if(!head || !head->next)
            return head;
        
        ListNode *temp =head;
        ListNode *kthfromStart = nullptr;
        for(int i=0; i<k ;++i) {
            kthfromStart = temp;
            temp = temp->next;
        }

        ListNode *kthfromEnd = head;
        while(temp) {

            kthfromEnd = kthfromEnd->next;
            temp = temp->next;
        }
        
        if(kthfromStart && kthfromEnd ){
            int val = kthfromEnd->val;
            kthfromEnd->val = kthfromStart->val;
            kthfromStart->val = val;
        }

        return head;
    }
};