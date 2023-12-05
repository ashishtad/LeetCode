


class Solution {
public:

    string smallestFromLeaf(TreeNode* root) {

        if( !root)
            return "";
        
        string result = "";
        calcSmallestString(root,result,"");
        return result;
    }


    void calcSmallestString( TreeNode *root, string &result, string num) {
	
		if(!root)
			return;
			
		num += char(root->val+'a');
		if( !root->left && !root->right ) {
			
			std::reverse(num.begin(),num.end());
			if( !result.empty() ){
				result = ( num<result)? num:result;
			} else 
				result = num;
			return;
		}
		
		calcSmallestString(root->left,result,num);
		calcSmallestString(root->right,result,num);
	}
};