
/**
80. Remove Duplicates from Sorted Array II
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150

 Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.
Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
Return k after placing the final result in the first k slots of nums.
Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
 * */


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int size = nums.size();
        if ( size == 0 || size ==1 || size == 2 ) 
            return size;
        // This will keep track of K [2] duplicate elements at max.    
        int index =0;
        for ( int i=0;i< size; ++i ) {

            // Untill 2 elements copy the elements from nums as it is.
            // This is because here our requirement is to keep 2 duplicate elements max.
            //After index 2 or 2 elements [can be dup or distinct], check if element in original array is greater to [index-2]th element. This is to ensure always that after k i.e 2 dup elements a distinct/non dup element is placed.
            // If element in original array is lesser then it's a dup one then skip it and move the iterator of original array to next element keeping index as it is.  
            if( (index < 2) || (nums[i] > nums[index-2]) )
                nums[index++] = nums[i];
        }
        return index;
    }
};