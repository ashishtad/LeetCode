

/*
    WORD SUBSETS


    SIMPLIFIED PROBLEM STATEMENT
    ============================
    You are given two string arrays: words1 and words2
    A word w from words1 is called universal if:
        For every word b in words2,
        w contains all characters of b with at least the same frequencies.

    Return all such universal words from words1.
    Note that here the order/sequence does not matter what matters is multiplicity of chars.

    APPROACH
    ========

    1. For each word in words1 create a list of char freq map.
    2. Iterate through all the word in words2 and create a max_freq map.
       This map represents the max freq of each character in words2. This is 
       because the constraint is universal w from word1 should contain all the
       chars of words2 with at least same frequencies.
    3. Iterate through max_freq map and if for each char freq <= char freq of 
       each word in words1 created in #1. If this satisfies then treat  
       word from word1 as universal.
       If not satisfies move to next word/char freq of word 1
    4. Return the resultant universal list.


*/

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        if (words2.size() ==0) return words1;

        array<int,26> required {};
        required.fill(0);     
        for (const string &str: words2) {
            array<int,26> temp;
            temp.fill(0);
            for (const char &c: str) temp[c-'a'] +=1;

            for (int i=0; i<26; ++i) required[i] = std::max(temp[i], required[i]);
        }
        vector<string> res;

        for (const string &str: words1) {

            array<int,26> freq1;
            freq1.fill(0);
            for (const char &c: str) freq1[c-'a'] +=1;
            bool valid = true;
            
            for (int i=0; i<26; ++i) {    
                if (freq1[i] < required[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) res.push_back(str);
        }
        return res;
    }
};