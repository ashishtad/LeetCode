
/* 449. Serialize and Deserialize BST*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void preorder(TreeNode *root, string &out) {
        if (!root) return;
        out += to_string(root->val) + ',';
        preorder(root->left, out);
        preorder(root->right, out);
    }
    TreeNode * buildBST(const vector<int> &nodes, int &idx, long long low, long long high) {

        if (idx >= (int)nodes.size()) return nullptr;
        /* Check the range of the idx element */
        int val = nodes[idx];
        if (val <= low || val >= high) return nullptr; /* Does not fit in range */

        /* Fits in range , consume it */
        TreeNode *newNode = new TreeNode(val);
        ++idx;
        /*left subtree values must be in (low, val) */
        newNode->left = buildBST(nodes, idx, low, val);
        /* right subtree values must be in (val, high)*/
        newNode->right = buildBST(nodes, idx, val, high);

        return newNode;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string data = "";
        preorder(root, data);
        /* Remove the last ',' */
        if (!data.empty()) data.pop_back();
        return data;     
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        stringstream str(data);
        string token;
        vector<int> preOrderVal;
        while (getline(str, token, ',')) preOrderVal.push_back(stoi(token));
        
        int idx = 0;
        return buildBST(preOrderVal, idx, LLONG_MIN, LLONG_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;