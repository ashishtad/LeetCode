/*
    57. Insert Interval
    Tim complexity : O(n) -> single pass of intervals
    Space compexity : O(n) -> ans list
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        
        // Case: No intervals
        if (n == 0) {
            ans.push_back(newInterval);
            return ans;
        }

        // Case: newInterval is after all intervals
        if (intervals.back()[1] < newInterval[0]) {
            ans = intervals;
            ans.push_back(newInterval);
            return ans;
        }

        int i = 0;

        // Add all intervals that end before newInterval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            ++i;
        }

        // Merge all overlapping intervals
        int start = newInterval[0];
        int end = newInterval[1];
        while (i < n && intervals[i][0] <= end) {
            start = std::min(start, intervals[i][0]);
            end = std::max(end, intervals[i][1]);
            ++i;
        }
        ans.push_back({start, end});

        // Add remaining intervals
        while (i < n) {
            ans.push_back(intervals[i]);
            ++i;
        }

        return ans;
    }
};
