class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if(meetings.size()==0) return days;

        /* Sort the meeting days based on meting start days */
        std::sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        int nextAvailDay = 1;
        int noMeetingDays = 0;
        /* calculate nomeeting days metingstartday - nextavail day.
           Update nextvail day.
         */
        for( const auto &meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            if(start>nextAvailDay)
                noMeetingDays += start-nextAvailDay;
            /* This will take care of overlapped meetings say [1,4], [2,3]*/
            nextAvailDay = std::max(nextAvailDay, end+1);
        }
        /*If still some days are left */
        if(days>=nextAvailDay) noMeetingDays += (days-nextAvailDay)+1;
        return noMeetingDays;
    }
};