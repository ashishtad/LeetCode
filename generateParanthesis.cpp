class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        //corner case empty check
        if( 0==n )
        {
            result.push_back("");
            return result;
        }
           
        
        string temp;
        
        backtrack(temp,0,0,n,result);
        
        return result;
        
    }
    
    void backtrack(string temp,int leftCount,int rightCount,int max,vector<string> &result)
    {
        
        //Base condition
        if( (max == leftCount) || ( max== rightCount) )
        {
            //Push the string if left braces and right braces are equal
            if( 0== (leftCount-rightCount) )
            {
                //check if the string is valid expression
                if( isValid(temp) )
                    result.push_back(temp);
                 
                return;
            }
           
        }
        
        if( leftCount<max)
        {
            backtrack(temp+"(",leftCount+1,rightCount,max,result);
        }
        if( rightCount < max )
        {
            backtrack(temp+")",leftCount,rightCount+1,max,result);
        }
    }
        bool isValid(string s) {
        
        if( s.empty() )
            return true;
        //Stack to store only the open braces.
        //keep the closed barces to later for checking  a valid expresion
        stack<char> paranthesisStack;
        bool result = false;
        int i =0;
        while( '\0' != s[i] )
        {
            if( s[i]=='(' || s[i]=='[' || s[i]=='{' ) //push only open braces
                paranthesisStack.push(s[i]);
            else
            {
                result = checkForValidSubExpression(s[i],paranthesisStack);//for closed braces
                if(!result) // Invalid subexpression found break
                    break;
            }
            i++;
            
        }
        //No invalid subexpressions found and stack is empty
        
        if( result && paranthesisStack.empty() )     
            return true;
        else
            return false;
        
        
    }
    //for closed braces check if the stack top is corresponding open brace. If so its a valid
    //sub expression and remove the element from stack. Else its an invalid
    bool checkForValidSubExpression( char ch, stack<char> &stack)
    {
        bool retVal = false;
        
        switch(ch)
        {
            case ')':
                if(!stack.empty())
                {
                   retVal = ( stack.top()=='(' )? true:false;
                     if(retVal) stack.pop(); 
                }
                
                break;
            case '}':
                
                if( !stack.empty() )
                {
                    retVal = ( stack.top()=='{' )? true:false;
                     if(retVal) stack.pop();
                }
                
                break;
            case ']':
                if(!stack.empty())
                {
                    retVal = ( stack.top()=='[' )? true:false;
                    if(retVal) stack.pop();
                }
                
                break;
            default:
                printf("Inavlid caharcter found\n");
        }
        return retVal;
    }