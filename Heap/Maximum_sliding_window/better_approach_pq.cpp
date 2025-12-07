/*
Better approach
===============

Use a max-heap of pairs:
(value, index)

Push each element as you slide the window.

For each window:

Keep popping from the heap while the top element’s index is outside the window
(i.e., index <= i - k)

The top of the heap is the max of the current window.

Time comlexity : O(n*logn) + O(n*logn)-> logn for prio q insert and for all ements in array
                                         Popping out also takes logn 
										 
Space complexity: O(n)
*/


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        if (0 == size) return {};
        if (1 == size) return nums;
        /* pair (value,index) */
        priority_queue<pair<int,int>> pq;
        int i =0;
        while (i < k) {
            pq.emplace(nums[i], i);
            ++i;
        }
        vector<int> res;
        res.push_back(pq.top().first);

        for (int i=k; i<size; ++i) {

            pq.emplace(nums[i], i);
            int startWindow = i-k+1;
            /* Pop elements outside window */
            while (!pq.empty() && pq.top().second < startWindow) pq.pop();

            res.push_back(pq.top().first);
        }
        return res;
    }
};