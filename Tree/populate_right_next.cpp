/*
    Populating Next Right Pointers in Each Node
    Approach
    You need to make use of the next links that you're creating.
    Time complexity : O(n)
    Space complexity: O(1)
*/

class Solution {
public:
    Node* connect(Node* root) {

        if(!root) return root;
        connectNext(root);
        return root;
    }
    void connectNext(Node *cur) {
        if(!cur || (!cur->left && !cur->right)) return;

        cur->left->next = cur->right;
   
        connectNext(cur->left);
        if(cur->next)
            cur->right->next = cur->next->left;
        else
            cur->right->next = nullptr;
        connectNext(cur->right);
    }
};