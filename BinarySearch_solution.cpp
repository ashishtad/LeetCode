////////////////////////////////////
//
//  Binary search 
// Solved : 9/08/2020
//////////////////////////////////

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if( 0== nums.size())
            return -1;
        if( 1==nums.size() )
        {
            if( target == nums[0])
                return 0;
            else
                return -1;
        }
        int index =-1;
        
        int low =0;
        int high = nums.size()-1;
        
        while( low<=high )
        {
            int mid = low+ (high-low)/2;
            if( target == nums[mid])
            {
                index = mid;
                break;
            }
            else if( target> nums[mid])
                low = mid+1;
            else
                high = mid-1;
        }
        return index;
        
    }
};