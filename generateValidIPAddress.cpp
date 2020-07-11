
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  This problem will solve in recursive DFS/backtrack technique.  
//	Here we have to make 4 segments and each segment is separated by "." since IP address always have segments.
//  How to make each segment:
//  1.Here we have 3 choices to make a segment.
//  1.1. Take single digit and further explore the remaining segments
//  1.2. Take two digits and further explore the remaining segments.
//  1.3. Take three digits and further explore the remaining segments. 
//  
//
//  References : https://www.youtube.com/watch?v=KU7Ae2513h0
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if( s.empty() )
            return result;
        string temp[4]; 
        backtrack(s,0,0,temp,result);
        return result;
    }
    /////////////////////////////////////////////////////////////////////////////////
    // BuilderIndex: This indicates the current index from where string needs to be 
    //               parsed for the respective segment.
    // Segment : Corresponding segment for which processing needs to be done.
    //  temp   : array of 4 strings to store each segment.
    //////////////////////////////////////////////////////////////////////////////////
    
    void backtrack( string s, int builderIndex, int segment,string *temp,vector<string> &result)
    {
        //Base condition
        //Found one combination as segment is 4 and builderIndex has reached till end
        if( (4==segment) && builderIndex == s.length())
        {
            //combine all the segments
            string buf = temp[0] + "." + temp[1] + "." + temp[2] + "." + temp[3];
            result.push_back(buf);
            return;
        }
        else if( (4==segment) ||  builderIndex == s.length() )
            return;
        
        //since we can make 3 choices , len represent each choice
        // For choice of 1 digit we will take substring from builderIndex position till len or 1.
        // For choice of 2 digit we will take substring from builderIndex position till len or 2.
        // For choice of 3 digit we will take substring from builderIndex position till len or 3.
        for( int len=1; len<=3 && builderIndex<s.length(); ++len )
        {
            //Take the substring from builderIndex till len
            string snippet = s.substr(builderIndex,len);
            //check if the snippet is valid or not
            if( !isValidIP(snippet) )
                break;
            //keep the current snippet in corresponding segment's place.
            temp[segment] = snippet;
            //Next processing should be done for segment+1 because currently we are done with                   segment processing.
            //For next segment processing we should start the parsing from builderIndex+len                    //position. Becasue currently for this segment we have parsed till len starting from              // builderIndex
             
            backtrack(s,builderIndex +len,segment+1,temp,result);
            //We have returned as either we have made a wrong choice/exploration or one                       // combination found. so we need to backtrack i.e erase the last choice or segment                 //value. 
            temp[segment] = "";
        }
       
    }
    bool isValidIP(const string &ip)
    {
        //Each integer/part of IP address should be max 3 digits
        // If 0 is there at first index,then it must be a single . Nothing should come after 0 i.e          05 is invalid.
        // Where as 50 is valid
        if( (3 < ip.length()) || (ip[0]=='0'&& (1 <ip.length())) )
            return false;
        bool bretVal = false;
        stringstream ss(ip);
        
        int ipValue;
        ss >> ipValue;
        if( (0<=ipValue) && (255>=ipValue) )
            bretVal = true;
        
        return bretVal;
    }
};