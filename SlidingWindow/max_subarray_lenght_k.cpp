/*
  Approach : SLIDING WINDOW
  =========================

  1. Maintain left and right two pointers initialised at 0th index. right-left+1 represents window size.
  2. Move right index and add the frequence of each element to freqmap. ALongwith this add the right index elem to cur sum.
  3. After each move (i.e #2) check
     3.1 if freq of rightIndex elem is > 1. If yes shrink the window i.e. move left by one and simultaneously
         remove the leftindex from cur sum and the frqmap. This ensures we are in a winodw where no dup elements exist.
    3.2 if window size >k. If yes again shrink the window as above.
        This ensures our window size is always within k.
   4. If window size ==k update the result sum.  


Time Complexity

O(n), where n is the size of nums.

Why this is O(n):
The right pointer moves from index 0 to n-1 exactly once.
The left pointer also moves from 0 to n-1 at most once.
Although there are two while loops, they do not make the algorithm quadratic:
Every iteration of either while loop advances left
Each element is removed from the window only once
So the total number of pointer movements is linear.

Space Complexity
O(k) (or more precisely O(min(n, k))).

The unordered_map stores frequencies only for elements currently inside the window.
The window size is capped at k, so at most k keys exist in the map at any time.

*/


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        if (n == 0 ) return 0;
      

        int left = 0;
        unordered_map<int,int> freqMap;
        long long res = 0;
        long long cursum = 0;
        for (int right =0; right<n; ++right) {

            freqMap[nums[right]] +=1;
            cursum += nums[right];
            /* Duplicate element found shrink window */
            if (freqMap[nums[right]] > 1) {
                while (freqMap[nums[right]] > 1) {
                    freqMap[nums[left]] -=1;
                    cursum -= nums[left];
                    ++left;
                }
            }
            int windowSize = (right-left)+1;
            /* Shrink the window */
            if (windowSize > k) {   
                while (windowSize > k) {
                    freqMap[nums[left]] -=1;
                    cursum -= nums[left];
                    ++left;
                    windowSize = (right-left)+1;
                }
            }

            if (windowSize == k) res = std::max(cursum, res);
        }
        return res;
    }
};