

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

 Approach
 =========
 The shortest path between any two nodes pass through their lowest common ancestor.

 1.Find the paths from root to start and root to dest.
 2. Remove the common path(common prefix) which is nothing but the path from
 root to LCA.
 3. At this step we are left with path from LCA to start + LCA to dest.
 4. Update the path from LCA to start as 'U' as from start to LCA we aways move upwards.
 5. Append the updated path to the dest path and return this as result. 

 complexity:
Time: O(n) for traversal of left and right subtree to find the start and dest path
+ O(n) common prefix removal
+O(n) Updating start path to 'U'
overall : O(n)
Space:
O(m) : to store root to start nodes
O(k): to store root to dest nodes
overall :O(n)

 */
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        std::string res ="";
        if(!root) return res;;
       vector<char> startPath, destPath;
        
        // Find paths from root to both nodes
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);
        // Now remove the path from root to LCA (common prefix in both startPath and destPath)
        removeCommonPrefixPath(startPath, destPath);
        //Update only the start path to 'U' 
        if(!startPath.empty()) {
            for(int i=0; i<startPath.size(); ++i)
                startPath[i] = 'U';
        } 
        res.append(startPath.begin(), startPath.end());
        res.append(destPath.begin(), destPath.end());
        return res;
    }
    bool findPath(TreeNode *root, int target, vector<char> &targetPath) {

        if(!root) return false;
        if(root->val == target) return true;

        targetPath.push_back('L');
        if(findPath(root->left, target, targetPath)) return true;
        targetPath.pop_back();

        targetPath.push_back('R');
        if(findPath(root->right, target, targetPath)) return true;
        targetPath.pop_back();

        return false;
    }

    void removeCommonPrefixPath(vector<char> &start, vector<char> &dest) {
        int i=0,j=0;
        for( i=0,j=0; i<start.size() && j<dest.size(); ++i,++j) {
            if(start[i] != dest[j])
                break;
        }
        //When start and dest in same path e,g example-2 [2,1]
        if(i == start.size() || j == dest.size()){
            if(i == start.size()) {
                start.clear();
                dest.erase(dest.begin(), dest.begin()+j);
            } 
            else {
                dest.clear();
                start.erase(start.begin(), start.begin()+i);
            }
            return;
        }
        start.erase(start.begin(), start.begin()+i);
        dest.erase(dest.begin(), dest.begin()+j);
    }

     
};