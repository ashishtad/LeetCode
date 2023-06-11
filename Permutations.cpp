//////////////////////////////////////////////////////////////////////
// 46. Permutations
//
////////////////////////////////////////////////////////////////////////


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        int size = nums.size();
        vector<vector<int>> result;
        {
              vector<int> vtemp;
            if( size ==0)
            {
                result.push_back(vtemp);
                return result;
            }
            if( size ==1)
            {
                vtemp.push_back(nums[0]);
                result.push_back(vtemp);
                return result;
            }
        }
       
        
        backtrack(nums,0,result);
        return result;
    }
    void backtrack(vector<int> nums,int index, vector<vector<int>> &result )
    {
        //Base condition
        if( nums.size() == index )
        {
             result.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); ++i)
        {
            swap( nums[i],nums[index]);
            backtrack( nums,index+1,result);
        }     
    }
};