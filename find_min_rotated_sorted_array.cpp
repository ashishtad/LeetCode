/*
    Approach:
    There is a deflection point in the rotated array at which the sorting deflects.
    Our result is at the deflection point and we need to find it.
    In binary search check if mid > high. If this then the right subarray contains the min/starting 
    element of actual non rotated array. Go to right.
    check if mid < high. If this then the left subarray contains the min/starting 
    element of actual non rotated array. Go to left.

    Time complexity : O(logn)
    Space Complexity : O(1)


*/

class Solution {
public:
    int findMin(vector<int>& nums) {

        int size = nums.size();
        if( 0 == size)
            return 0;
        if( 1 == size)
            return nums[0];
        
        return binaryMinSearch(nums,size);
        
    }

    int binaryMinSearch( const vector<int> &nums, const int &size) {

        int low = 0;
        int high = size-1;

        while( low <= high){
            int mid = low+(high-low)/2;
            //Deflection point where mid > mid+1 .So mid+1 is the starting elem of the actual array
            if( nums[mid]> nums[mid+1])
                return nums[mid+1];
            //Deflection point where mid < mid-1. So mid is starting elem of actual array
            else if(mid>0 && nums[mid]< nums[mid-1] ) 
                return nums[mid];
            else{
                if( mid ==0)
                    return nums[mid];
                else {
                    //Got to right subarray
                    if( nums[mid]> nums[high])
                        low = mid+1;
                     //Go to left subarray
                    else
                        high = mid-1;
                }
          
            }
        }
        return -1;
    }
};