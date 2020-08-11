/////////////////////////////////////////////////
// Make the string great
//
/////////////////////////////////////////////////



class Solution {
public:
    string makeGood(string s) {
        
        if( s.empty() || 1==s.length())
            return s;
        //stack to store the characters and compare the next char in string with top of stack
        //This will hold our final output string
        std::stack<char> st;
        st.push(s[0]);
        int i=1;
        string result ="";
        while( s[i] )
        {
            //compare the next char in string with top 
            if( !st.empty() && (s[i] != st.top()) ) 
            {
                char ch = s[i];
                //convert lowercase to uppercase and vice versa
                //This is to compare whether the s[i] and the previous char i.e top() are equal or                  not. If after conversion they are equal that means originally they  notequal in                   cases. So remove the top().
                
                //Not  equal that means origially not equal.Push to stack
                if( islower(ch)) ch = (char)toupper(ch);
                else
                    ch = (char) tolower(ch);
                if( ch != st.top() ) st.push( s[i]);
                else
                     st.pop();
            }
            //if top() and s[i] are equal
            else
                st.push( s[i]);
            ++i; 
        }
        
        //pop the characters from stack
        while( !st.empty()) 
        {
            result =st.top()+result;
            st.pop();
        }
        
        return result;
        
    }
};