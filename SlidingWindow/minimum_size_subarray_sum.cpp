/*
    TIP: This follows the same design as "Minimum Window Substring".
    INTUITION
    =========
    We have to frame window by expanding it and check if the sum >= target.
    If so it's valid winodw , update result.
    For valid winodw , then shrink the winodw and keep on shrinking until window becomes invalid.
    At each step of shrinking until window is invalid keep updating result.

     APPROACH
    ========
    2. left and right starts from 0th index.cur sum represnts sum of curent window.
    3. Expand window by adding right in freq map and cur sum. If cursum >= target valid window found.
    4. For valid winodw -
        Update the res.
        Start shrinking one by left.
    5. For shrinking reduce the cur sum  until window becomes invalid.
    6. Repeat #3 to make it valid again.

    Complexity
    Time: O(N)
    Space: O(N)
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (0 == n) return 0;
        if (1 == n) return nums[0] >= target ? 1: 0;
        int left = 0;
        int res = INT_MAX;
        int cursum = 0;

        for (int right=0; right<n; ++right) {
    
            cursum += nums[right];
            /* Valid window found - start shrinking */
            while (cursum >= target) {
                res = std::min(res, (right-left)+1);
                cursum -= nums[left];
                left += 1;
            }
        }
        return res == INT_MAX ? 0: res;
    }
};