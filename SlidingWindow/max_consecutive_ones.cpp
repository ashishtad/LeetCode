/*
    The approach here is to solve the problem using sliding window technique.
    Key here is in a given window[subset array] max k number of 0s can be present.
    This is because we can flip only max 0s to make 1s.

    Approach:
    Use two pointers (as we need to frame windows) start and end both starting forom index 0.
    Move end pointer towards right to frame a window.
        - If encountered 0 increment a zero counter.
        - Also at each iteration calculate the max len util that point.
    When the end pointer reaches a point where zero count > k( window becomes invalid), 
    then we need to slide the start index to frame a new window.
    We need to move start index (slide) to remove one 0 (slide just after first 0 in window zerocount==k).
    This because in a given window max k zeros are allowed. And here we are going to frame
    new window.

    Refer this nice explanation:
    https://www.youtube.com/watch?v=HsGKI02yw6M

    Complexity:
    Time Complexity: O(n), where n is the size of the array nums. We process each element once with the sliding window.
    Space Complexity: O(1), as we only use a fixed amount of extra space for tracking variables.
*/


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        if(0 == n)
            return 0;
        
        int zeroCount = 0;
        int start = 0;
        int end = 0;
        int maxlen = 0;

        while( (start<n) && (end<n) ){
            //count the zeroes
            if(0 == nums[end] )
                ++zeroCount;

            // If we have more zeros than allowed, shrink the window
            while(zeroCount > k){
                if(0 == nums[start] )
                    --zeroCount;
                ++start;
            }
            maxlen = std::max(maxlen, (end-start)+1);
            ++end;
        }
        return maxlen;
    }
};