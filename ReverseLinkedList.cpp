/////////////////////////////////////////////////////////////////////////////////////////
// 206. Reverse Linked List
// Approach: Iterative and Recursive
////////////////////////////////////////////////////////////////////////////////////////////

//Iterative

   ListNode* reverseList(ListNode* head) {
        if( NULL == head)
            return NULL;
        
        if( NULL == head->next )
            return head;
        
        ListNode* prev=NULL;
        ListNode* cur = head;
        while( cur )
        {
            cur = head->next;
            head->next = prev;
            prev=head;
            head = cur;
        }
        return prev;
        
    }
  //  Time complexity: O(n)
	//Space complexity: O(1)
	
	//Recursive
	
	public ListNode reverseList(ListNode head) {
    if (head == null || head.next == null) return head;
    ListNode p = reverseList(head.next);
    head.next.next = head;
    head.next = null;
    return p;
}
// Time complexity: O(n)
// Space complexity: O(n) Because of n receursive calls