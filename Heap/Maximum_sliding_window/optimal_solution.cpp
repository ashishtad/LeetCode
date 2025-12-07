/*
The problem statement is a little vague.
We need to return the Maximum Element from each window.
max sliding window = list of max element for each window

Optimal Approach
==================

Here we will use the concept of decreasing monotonic stack (dequeue).
The sliding concept remains the same as done in previous solutions of using priority queue.


1. Check if front() elem i deq is within the current element window. If not pop from front.

2.  check if the current existing elements are greater than this element.
   If not remove from deq. This is to ensure the decreasing elements nature in deq.

3. push the cur element to deq.

4. Start recording the max when first window is framed

Time: O(N) : Eachelem gets pushed and popped once from deq and deq operation is O(1)
Space: O(K) + O(n): At most k elements can hold in deq (one window size). O(n) for result vector
Reference: https://www.youtube.com/watch?v=NwBvene4Imo
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  // stores indices
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++) {
            
            int startWindow = i-k+1;
            // 1. Remove elements out of the current window
            if (!dq.empty() && dq.front() < startWindow) dq.pop_front();

            // 2. Remove all smaller elements (they cannot be max)
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            // 3. Add current index
            dq.push_back(i);

            // 4. Start recording max when the first window is formed
            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};
