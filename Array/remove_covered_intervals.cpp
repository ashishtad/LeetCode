/*
    Remove Covered Intervals
*/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if(0==intervals.size()) return 0;

        std::sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[0]==b[0]) return a[1]>b[1]; 
            return a[0]<b[0];
        });
        vector<vector<int>> mergeList;
        mergeList.push_back(intervals[0]);
        int coveredCount = 0;
        for(auto it = intervals.begin() + 1; it != intervals.end(); ++it) {
            int start = (*it)[0];
            int end = (*it)[1];
            /* Scenario 1: Completely covered suppose existing interval in vector is [1, 8] and this ith interval is [2, 6] ,
             this is completely inside i.e. start and end
			lies inside , hence this interval is surely removed, count this. */
            if(start>=mergeList.back()[0] && end<=mergeList.back()[1]) coveredCount +=1;
            /* Scenario 2: vector has [1, 8] and ith interval is  [5, 10], so take maximum of both end point.*/
            else if(start>mergeList.back()[0] && end>=mergeList.back()[1]) mergeList.back()[1] = std::max(mergeList.back()[1],end);
            /* Proper distinct interval */
            else mergeList.push_back(*it);
        }
        return intervals.size()-coveredCount;
    }
};