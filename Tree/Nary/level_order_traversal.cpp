/*429. N-ary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> result;
    if (!root)
        return result;
    
    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int num_cur_level_nodes = q.size();
        vector<int> cur_level_nodes;
        cur_level_nodes.reserve(num_cur_level_nodes); // Reserve space for current level nodes
        
        for (int i = 0; i < num_cur_level_nodes; ++i) {
            Node* node = q.front();
            q.pop();
            cur_level_nodes.emplace_back(node->val); // Use emplace_back for efficient in-place construction
            
            for (Node* child : node->children) {
                q.push(child); 
            }
        }
        result.emplace_back(std::move(cur_level_nodes)); // Use move semantics to avoid copying
    }
    return result;
}

};