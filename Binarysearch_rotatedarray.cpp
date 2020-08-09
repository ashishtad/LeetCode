/////////////////////////////////////////////////////////////////////////////////
// ALGORITHM:
// [4,5,6,7,0,1,2]
// In the rotated array there will be two parts:
// 1. 4,5,6,7: Left subarray 
// 2. 0,1,2: Right subarry
//
// This problem will be solved based on the mid of the array.
// Mid can lie on 3 cases:
// Case 1: Mid is in left subarray( low can be in left and high can be in right subarray)
// Case 2: Mid is in right subarray( low can be in left and high can be in rght subaray)
// Case 3: Mid is in fully sorted array i.e low and high both are in sorted array
//
//////////////////////////////////////////////////////////////////////////////////////




class Solution {
public:
    int search(vector<int>& nums, int target) {
        if( 0==nums.size()) return -1;
        
        if( nums[0] == target) return 0;
        if( nums[nums.size()-1] ==target) return nums.size()-1;
        
        int result = binarySearch(nums,target,0,nums.size()-1);
        return  result;  
    }
    int binarySearch(vector<int>& nums, int target,int l,int h)
    {
        int low = l;
        int high = h;
        int index =-1;
        
        while( low<=high)
        {
            int mid = low+(high-low)/2;
            if( target == nums[mid])
            {
                index = mid;
                break;
            }
            //Rotation exists and mid is in left subarray.
            if( nums[low]<= nums[mid]  )
            {
                //Target in between low and mid
                if( target>= nums[low] && target<nums[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
            //Rotation exists and mid is right subarray
            else if( nums[mid]<=nums[low] ) 
            {
                //Target between mid and high 
                if( target>nums[mid]&& target<=nums[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
            //no rotation normal binary search
            else
            {
                if( target> nums[mid])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return index;
    }
};