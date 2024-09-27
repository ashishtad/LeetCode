
/*589. N-ary Tree Preorder Traversal
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        if(!root)
            return result;
        
        std::stack<Node*> s;
        s.push(root);

        while( !s.empty() ){
            Node *top = s.top();
            s.pop();

            result.push_back(top->val);
            if(top->children.size() > 0 ){
                for( int i=top->children.size()-1; i>=0 ; --i){
                    s.push(top->children[i]);
                }
            }
        }

        return result;
    }

};