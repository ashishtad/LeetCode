
class Solution {
public:
    vector<vector<string>> partition(string s) {

        if (s.empty()) return {};
        vector<string> path;
        vector<vector<string>> res;
        recur(s, path, 0, res);
        
        return res;
    }

    void recur(const string &s, vector<string> &path, int index, vector<vector<string>> &res) {

        if (index == s.size()) {
            res. push_back(path);
            return;
        }

        for (int i=index; i<s.size(); ++i) {

            if (isPallindrome(s, index, i)) {
                path.push_back(s.substr(index, i-index+1));
                recur(s, path, i+1, res);
                path.pop_back();
            }
        }
    }
    bool isPallindrome(const string &s, int start, int end) {
        if (start == end) return true;

        while (start < end) {
            if (s[start] != s[end]) return false;
            ++start;
            --end;
        }
        return true;
    }
};