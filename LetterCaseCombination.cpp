
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 784. Letter Case Permutation
// Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  
// Return a list of all possible strings we could create.
// Examples:
//Input: S = "a1b2"
//Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
//
//Solved on: 24/05/2020
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        backtrack(S, 0, ans);
        return ans;
    }
    
    void backtrack(string &s, int i, vector<string> &ans) {
        if (i == s.size()) {
            ans.push_back(s);
            return;
        }
        //There will be two cases possible
        //case 1: With toggling the character, form all the combinations
        //case 2: Without toggling the character, form all the combinations
        //Save initial value
        char c = s[i];
        // Case1: toggle lower/upper case
        if( isalpha(c))
        s[i] = islower(c) ? toupper(c) : tolower(c);
        
        backtrack(s, i + 1, ans);
        // Case2: reset back/original value
        if (isalpha(c)) {
            s[i] = c;
            backtrack(s, i + 1, ans);
        }
    }
};