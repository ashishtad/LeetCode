
/*
    14/01/2024

    Time complexity : O( log(k)*mn)
    O(m*n) : To merge two lists
    O( logk) : To divide the list to half and traversing
    Space complexity : O(1)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int len = lists.size();
        //Empty list
        if( 0 == len )
            return nullptr;
        //Lists having one element 
        if( 1== len )
            return lists.front();

        while( len > 1) {

            /*
            Approach: Break the k list into k/2, k/4, k/8 ... till we reach k=1 list 
            Traverse till len/2 - Merge two lists in each itr ith and (len-1-i)th
              In this till we reach len/2 we have already merged the lists after len/2 with corresponding ith
              position list before len/2.
            */
            for ( auto i=0; i< len/2; ++i ){
                lists[i] = mergeTwoLists(lists[i], lists[len-1-i]);
            }
            //Divide le to len+1/2
            len = (len+1)/2;
        }
        return lists.front();        
    }

    ListNode* mergeTwoLists( ListNode* l1, ListNode* l2) {

        if( !l1 and !l2)
            return nullptr;
        if(l1 && !l2)
            return l1;
        if(l2 && !l1)
            return l2;
        ListNode *new_node = new ListNode();
        ListNode *temp = new_node;

        while( l1 && l2 ){

            if( l1->val <= l2->val){
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        if( l1 && !l2 )
            temp->next = l1;
        else if ( l2 && !l1 )
            temp->next = l2;

        temp = new_node->next;
        delete new_node;
        new_node = nullptr;

        return temp;

    }
};