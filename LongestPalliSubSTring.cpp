///////////////////////////////////////////////////////////////////////////////////////
//  Longest Palindromic Substring
//  Solved on: 16/04/2022
//
//  Reference: https://www.youtube.com/watch?v=XYQecbcd6_c&t=211s
// ////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    string longestPalindrome(string s) {
        
        if( (s.empty()) || (s.length()==1) )
            return s;
        int len = s.length();
        int resLen =0;
        string res ="";
        for(int i=0; i<len;++i)
        {
			//For odd substring
			//Move outwards from i and check if l and r are same i.e pallindrome.
            int l=i,r=i;
            while( (l>=0 && r<len) && (s[l]==s[r]) )
            {
                if( (r-l)+1 >resLen )
                {
                    resLen= max(resLen,(r-l)+1);
                    res = s.substr(l,(r-l)+1);
                }
                
                --l;
                ++r;
            }
			
			//For even substring
            
           l=i,r=i+1;
            while( (l>=0 && r<len) && (s[l]==s[r]) )
            {
                if( (r-l)+1 >resLen )
                {
                    resLen= max(resLen,(r-l)+1);
                    res = s.substr(l,(r-l)+1);
                }
                
                --l;
                ++r;
            }
            
            
            
        }
        return res;
        
    }
};