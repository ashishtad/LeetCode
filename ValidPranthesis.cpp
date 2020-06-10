/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 20. Valid Parentheses
//
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

//An input string is valid if:

//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Note that an empty string is also considered valid.
// 
// Note: A subexpression of a valid expression should also be a valid expression.Though not mandatorily every
// subexpression
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



class Solution {
public:
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
};