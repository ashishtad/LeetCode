////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//402. Remove K Digits
//Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
//Example 1:
//
//Input: num = "1432219", k = 3
//Output: "1219"
//Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// 
// Approach:
// Maintain a string and use it as stack say ans.
// if input char is lesser than the top char at stack(ans) then there is possibility it would create a smaller number.
// so pop the top char from ans stack. Keep the count of K deletions.
// For leading zeroes:
// If ans stack is non empty push whatever comes but if its empty(ans having leading zeros) then push only if the input is non zero.
// Time complexity: O(n)
// Space complexity : O(n)
////////////////////////////////////////////////////////////////////////////////////////////////////////////


    string removeKdigits(string num, int k) {
        if( num.empty() || num.size()==k )
            return "0";
        string ans="";
        int i=0;
        
        
        while( num[i] )
        {
		    
            while( ans.size() && (ans.back()>num[i]) && k ) 
            {
                ans.pop_back();
                --k;
            }
			//ans.size() if fails that means nothing is there in ans. so accept only non zeros
			//Because accepting zeroes will become leading zeros in ans
            if( ans.size() || (num[i]!='0') )
                ans.push_back(num[i]);
            i++;
        }
        if(k) // at the end if still K deletions are present 
        {
            while( ans.size() && k-- )
                ans.pop_back();
        }
        
        return ( (ans=="") ? "0":ans);
        
    }