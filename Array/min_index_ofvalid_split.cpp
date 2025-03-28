

/*
2780. Minimum Index of a Valid Split
Approach
========
Find the dominant element of the entire array.

Use a frequency map or Boyer-Moore Voting Algorithm. Here boyre moore is used.

If there is no dominant element, return -1.

Perform a left-to-right traversal to check for valid splits:

Maintain a count of the dominant element in the left and right parts.

Check if both parts satisfy the dominant condition.

return the index if this condition holds.
*/

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        
        if(0==nums.size()) return -1;

        int ele, count=0;
        for(const int &num : nums) {
            if(0==count) {
                ele = num;
                count = 1;
            } else if(num == ele) count +=1;
            else count -= 1;
        }
         int cnt = 0;
         for(const int &num : nums) {
            if(ele == num) ++cnt;
         }
         int dominant = -1;
         if(cnt>nums.size()/2) dominant = ele;
        int len = nums.size();
        /* left and  right count denotes the dominant element in left and right subaary respctively.
           Since we are traversing the array , so at start left half is empty hence leftcount is 0
           right half is actual entire array so right count is totalcount of dominant elements.
        */
        int leftcount = 0, rightcount = cnt;
       /* As we traverse the array, split array at ith position if index i is dominant elem,
          and increase leftcount and reduce rightcount by 1.
       */
        for(int i=0; i<len; ++i) {
            if(nums[i] == dominant) {
                ++leftcount;
                --rightcount;
            }
            /* Check valid split:
              dominant element satisfies the majority condition in both halves after splitting at index i.
              Dominanat element must the majority in both halves.
              If leftCount * 2 > (i + 1), it means the dominant element appears more than half of the elements in the left subarray.
              Similar for right subarray.
            */
            if((leftcount*2 > (i+1)) && (rightcount*2 > len-(i+1))) return i;
        }
        return -1;
    }
};