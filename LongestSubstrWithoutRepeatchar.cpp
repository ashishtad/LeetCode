
///////////////////////////////////////////////////////////////////////////
// 3. Longest Substring Without Repeating Characters
//
// Here the logic is sliding window technique.
// Time: O(n)
// Space: O(k) ; k is the no characters in the map worst case O(n)
//////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int result = 0;
        int size = s.size();
        
        if(s.empty() || 1==size)
        {
            if( 1== size)
                result=1;
            
            return result;
        }
        
        //Map to store char and its index in s
        unordered_map<char,int> substringMap;
        //startIndex denotes the index from where we will mark our substring formation
        //endIndex will move forward to make substrings with reference to startIndex
        int startIndex =0; int endIndex =0;
        
        while( startIndex<size && endIndex<size )
        {
            //If duplicate found 
            if( 0 != substringMap[s[endIndex]] )
            {
                //The index at which dupliate found can be ahead of startIndex or behind.
                //Case: Ahead then we need to jump startIndex to index+1 where duplicate found.
                //We have to start new substring formation as this is broken now 
                //Case: Behind No need to change start as the duplicate is behind the start
                startIndex = std::max(startIndex,substringMap[s[endIndex]]);
            }
            
           //calculate the length of substring without duplicates,
            //max between previous length and current substring length
            result = std::max(result, (endIndex-startIndex)+1);
            substringMap[s[endIndex]] =endIndex+1;
            ++endIndex;
            
        }
        
        return result;
    }
};