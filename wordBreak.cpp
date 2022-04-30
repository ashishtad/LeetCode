//////////////////////////////////////////////////////////////////////////
// 	WOD BREAK SOLUTION
//
//Date: 19/04/2022
// https://www.youtube.com/watch?v=hLQYQ4zj0qg
//////////////////////////////////////////////////////////////////////////
//This is recursive tree approach but it wil give Time limit exceeded.This is aniave approach of Time cpexit as O( 2 power of n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        //Brute force recursive tree approach
        if( s.empty() )
            return true;
        //Maintain a set so that look up will be faster.
        unordered_set<string> wordSet;
        for( auto word : wordDict)
            wordSet.insert(word);
        return dfs(s,wordSet);
        
    }
    bool dfs(const string &s,const unordered_set<string> &wordSet)
    {
        //Base condition if string is empty return true
        if( s.empty() )
            return true;
        //loop through string
        for( int len=1; len<=s.length();++len)
        {
            string sub = s.substr(0,len);
             
            if( (wordSet.count(sub)!=0) && dfs(s.substr(len)/*substring from len position to end of string*/,wordSet) )
            {
               
                return true;
            }
                
        }
        return false;
        
    }
};