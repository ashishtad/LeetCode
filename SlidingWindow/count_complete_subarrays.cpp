/*CLASSICAL SLIDING WINDOW APPROACH
  ==================================

  1. Popualate the nums elements in a set- to get the count of distinct
  elements.
  2. Follow regular sliding window, take left and right pointer and a map to count the 
  distnct elemenst in winodw. Expand right pointer (add elements to windowmap) 
  until the window becomes valid. 
   How to check validity ?
   windowmap count== numset count: valid window.
   Important point is how to calculate the num of valid subaarys.
   Please note at this point in between [left,right] we have found a valid subarray.
   So all the elements post right index until n will also frame a valid subarray each.

   e.g [1,3,1,2] -> valid subarray 
       Then all the elements individually post right index at 2,
        which is another 2 [1,3,1,2,2] is also a valid subarray

    To calculate the total subarrays( n-right idx)

  3. For the valid window found shrink from left until winodw becomes invalid.
  At each shrink check the validity and update result.
*/

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

        int n = nums.size();
        if (0 == n)
            return 0;
        if (1 == n)
            return 1;

        unordered_set<int> numSet(nums.begin(), nums.end());
        int left = 0;
        int required = numSet.size();
        int res = 0;
        unordered_map<int,int> windowMap;
        for (int right = 0; right < n; ++right) {

            windowMap[nums[right]] +=1;

            /* valid window*/
            while (left <= right && windowMap.size() == required) {
                /* Complete subarray found increase the result */
                res += (n-right);
                /* SHrink the winodw */
                if (--windowMap[nums[left]] == 0) windowMap.erase(nums[left]);
                left += 1;
            }
        }
        return res;
    }
};