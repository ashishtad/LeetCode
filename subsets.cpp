/////////////////////////////////////////////////////////////////////////////////
//  We have to loop through each element and form the combination. Store them
//  in a temp vector i.e sub and in each backtrack we have to add sub to result.
//   We have to remove one element and chose remaining elements in nums to
//   form the combination. So the remove at end of loop
//   Time complexity: O(N*2^N)
//    Space Complexit: O(N*2^N)
////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result;
        if( 0==nums.size())
            return result;
        vector<int> sub;
        backtrack(nums,0,sub,result);
        
        return result;
    }
    
    void backtrack( vector<int>&nums, int index, vector<int> sub,vector<vector<int>> &result )
    {
        result.push_back(sub);
        
        for( int i=index; i<nums.size(); ++i )
        {
            sub.push_back(nums[i]);
            backtrack(nums,i+1,sub,result);
            sub.erase(sub.end()-1);
            
        }
    }
};