

class Solution {
public:
    int longestContinuousSubstring(string s) {
        if(s.empty())  return 0;

        int len = s.length();
        int max_streak = 1;
        int cur_streak = 1;
        for(int i=0; i<len; ++i) {
            if(s[i]+1 == s[i+1])
                cur_streak+=1;
            else {
                max_streak = std::max(cur_streak, max_streak);
                cur_streak = 1;
            }
        }
        max_streak = std::max(cur_streak, max_streak);
        return max_streak;
    }
};