
#include "iostream"
using namespace std;
/*
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {


        if(!head)
            return nullptr;
        
        ListNode *temp = head;
        ListNode *kthNode = head;
        ListNode *nextNode = nullptr;
        ListNode *prev_group_tail = nullptr;

        while( temp){
            /*
               Traverse k nodes so that KthNode points to Kth Node 
            */
            int i = 1;
            while( (i++ < k) && kthNode)
                kthNode = kthNode->next;
            
            /* Point the nextNode to next kth group first node */
            if( kthNode )
                nextNode = kthNode->next;
            /* List ended or remaining nodes are not multiple of k */
            else{
                /* Remaining nodes from temp are not multiple of K.
                   Point prev_group_tail to temp to keep the nodes 
                   from temp till end of list as it is and join the 
                   previous reversed group tail node.
                   Else of this is list ended which is K > number of nodes
                   in the list.
                */
                if(prev_group_tail)
                    prev_group_tail -> next = temp;
                break;
            }
            /* Detach the current group and reverse the current kth group */
            kthNode->next = nullptr;
            reverseKNodes(&temp, &kthNode);
            /* After reverse temp points to actual tail node of group nodes,
               kthNode points to actual head of group nodes.
               For first k group, check after reverse if temp is head.
               This is to preserve the head for the final resultant list.
               For all other groups, point prev_group tail node to next group first node.
            */
            if( temp == head)
                head = kthNode;
            else
                prev_group_tail->next = kthNode;
            
            /* After reverse, we are ready to jump next k group nodes,
               Keep current k group last Node in prev_group_tail.
               This is to join back the current group once the
               next k group is reversed.
            */
            prev_group_tail = temp;
            /* Move to next k group */
            temp = nextNode;
            /* Update KthNode to next group first node */
            kthNode = nextNode;
        }
        return head;
        
    }

    /* Reverse the list */
    void reverseKNodes( ListNode **head, ListNode **tail) {
        
        ListNode *temp_head = (*head);
        if( !temp_head->next) {
            (*head) = temp_head;
            (*tail) = temp_head;
        }   

        ListNode *prev = nullptr, *cur = temp_head;

        while(cur){
           
            ListNode *nextNode = cur->next;
            cur->next = prev;
            prev= cur;
            cur = nextNode;
        }
        (*tail) = prev;
        (*head) = temp_head;
    }
};

int main(){
    cout<<"xecute reverse k node\n";
    // Create a sample linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    //head->next->next->next->next->next = new ListNode(6);
    
    // Print the original linked list
    cout << "Original linked list: ";
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Reverse every k nodes
    int k = 6; // Example: Reverse every 2 nodes
    Solution solution;
    head = solution.reverseKGroup(head, k);

    // Print the reversed linked list
    cout << "Reversed linked list (every " << k << " nodes): ";
    temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}