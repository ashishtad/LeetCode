/*
  1695. Maximum Erasure Value
  This is same as classical sliding window "longest substring without repeating characters".

  Complexity
  Time : O(N)
  Space: O(N)
*/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        if (0 == n) return -1;
        if (1 == n) return nums[0];

        int startIdx =0;
        int endIdx = 0;
        /* Pair of numvalue and it's index */
        unordered_map<int,int> numIdx;
        int res = 0;
        int curSum = 0;
       
        while (startIdx<n && endIdx<n) {
            
            /* Found duplicate - Adjust the startIndex.
               Remove the elements from curValue upto new startIdx.
             */
            if (numIdx.count(nums[endIdx])) {
                int prevStart = startIdx;
                startIdx = std::max(startIdx, numIdx[nums[endIdx]]);
                for (int i=prevStart; i< startIdx; ++i) curSum -=nums[i];
            }

            curSum += nums[endIdx];
            res = std::max(res,curSum);
            numIdx[nums[endIdx]] = endIdx+1;
            ++endIdx;
        }
        return res;
    }
};