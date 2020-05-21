///////////////////////////////////////////////////////////////////////////////////////////////////////
// 17. Letter Combinations of a Phone Number
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// Example: Input: "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Author: Ashish Tad
// SOlved Date: 21/05/2020
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> result;
        if( digits.empty() || digits=="1" )
            return result;
        
        map<string,string> numberIndexMap;
        //Map to store the corresponding letters of respectve numbers in telephone buttons
        initialiseMap(numberIndexMap);
        
         FormLetterCombination(numberIndexMap,result,digits);
       
        
        return result;
        
        
    }
    void FormLetterCombination(const map<string,string>& numberIndexMap, vector<string> &result,const string &digits)
    {
        //Deque to store the combinations
        std::stack<string> combinationStack;
        int n = digits.length();
       
        combinationStack.push("");
        
        while( !combinationStack.empty() )
        {
            string s = combinationStack.top();
            combinationStack.pop(); //pop the element as we are goint to create a new                                            combination and push it
            
            //If the element/combination in queue length is same as input digit, then we got               our result.
            if( n == s.length())
                result.push_back(s);
            else
            {
                //get the corresponding number's leeter and amke combinations with existing                 elemet in deque.
                string letter = numberIndexMap.at(string(1,digits[s.length()])) ;
                for( string::iterator it=letter.begin(); it!=letter.end();++it)
                {
                    combinationStack.push( s+string(1,*it));
                }  
            } 
        }
    }
 
    void initialiseMap(map<string,string> &numberIndexMap)
    {

        numberIndexMap["2"] = "abc";
        numberIndexMap["3"] = "def";
        numberIndexMap["4"] = "ghi";
        numberIndexMap["5"] = "jkl";
        numberIndexMap["6"] = "mno";
        numberIndexMap["7"] = "pqrs";
        numberIndexMap["8"] = "tuv";
        numberIndexMap["9"] = "wxyz";
        
    }
};