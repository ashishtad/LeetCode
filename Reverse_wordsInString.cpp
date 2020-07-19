
///////////////////////////////////////////////////////////////
//  151. Reverse Words in a String
// Solved on: 19/07/2020
//////////////////////////////////////////////////////////////






class Solution {
public:
    string reverseWords(string s) {
        string result="";
        if( s.empty() )
            return result;
      
        //Remove the leasding and trailing spaces from input string
        result=removeLeadingAndTrailingSpaces(s);
        //If after removing leading/trailing characters string is empty
        if( result.empty() )
            return result;
        //Reverse the entire input string
        reverseString(result);
        
     int startPos =0;
    //Reverse the each word by removing the intermediate spaces    
    while( result[startPos] !='\0'  )
    {
        //Find the first space
        int wordEnd = result.find(' ',startPos+1);

        if( string::npos != wordEnd)
        {
            //reverse the word
            reverseWord(result,startPos,wordEnd-1);

            int len=0;
            //Remove if any extra spaces are there
            int space=wordEnd+1;
            while(result[space++] ==' ')
                ++len;

            result.erase(wordEnd+1,len);
            //Adjust the start position
            startPos=wordEnd+1;
        }
        //Last word is found , so reverse the last word and break from loop
        else
        {

            reverseWord(result,startPos,result.length()-1);
            break;
        }

    }

  return result;        
    }
    
    void reverseString( string &str)
{
    if( str.empty() )
        return;

    int start =0;
    int end = str.length()-1;

    while( start < end)
    {
        char temp =str[start];
        str[start++] = str[end];
        str[end--] = temp;

    }
}
string  removeLeadingAndTrailingSpaces(const string &str)
{
    string newString = "";
    if( str.empty())
        return newString;
    int startPos=0;
    while( (str[startPos]!='\0') && (' ' == str[startPos]) )
        ++startPos;
    //Case: Where all the characters in string are spaces
    if( startPos == str.length())
        return newString;

    int endPos = str.length()-1;
    while( ' ' == str[endPos])
        --endPos;
    newString = str.substr(startPos,(endPos-startPos)+1 );

    return newString;
}
void reverseWord( string &str,int start, int end)
{

    while( start < end)
    {
        char temp =str[start];
        str[start++] = str[end];
        str[end--] = temp;

    }
}
};