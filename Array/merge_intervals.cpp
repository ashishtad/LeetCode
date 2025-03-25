/*
    56. Merge Intervals
    Time complexity : O(N logN) for sorting + O(N) traversal
    Space complexity: O(N)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedList;
        if(intervals.size()==0) return mergedList;
        /* Note Input list is not sorted Sort it by start time*/
        std::sort(intervals.begin(), intervals.end(),[](const vector<int> &a, const vector<int> &b){
            return a[0]<b[0];
        } );
        /* If the mergelist is empty or the mergedlist last element end time < cur interval start,
            append to merged list.
            Else which is overlap case the endtime in last element of merged list would be updated
            as max(cur interval end, mergedlist lastelem endtime) 
        */
        for(const auto &interval: intervals) {
            int start = interval[0];
            int end = interval[1];
            if(mergedList.size()==0 || mergedList.back()[1]<start) mergedList.push_back(interval);
            else mergedList.back()[1] = std::max(mergedList.back()[1], end);
        }
        return mergedList;
    }
};