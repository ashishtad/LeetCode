/*
    INTUITION
    =========
    This is a sliding window problem. Now how to slide the window ?
    All the chars of t need to exist in substring of s. Note here all the chars in it means
    all the chars including duplicates. e.g t : AAB then in substring of s 'A' must appear twice.

    This point gives us a sense that we need to have all the char frequncy in substring of s.
    So we need to have a freqMap of "t".
    Key point: A substring is valid only if the freq of chars in substring is greater or equal to
    the chars frequency in "t". That means if t="AAB" then substring can be ACDABACB this is valid.
    Here in t A's freq is 2 and B's freq is 1 but in substring A appears (freq) 3 times and B also 2times.
    This is valid. In simple words freq of each char in t <= freq of that char in substring. 

    Now we know how to check the validity of substring.
    Next is how to traverse the source s ?
    We have to frame window by taking pointers and in each framed window need to maintain a freq map.
    If the window is valid as per above points, then update the result.
    Once a valid window is frames then we need to shrink that window from left so as to minimise the length which is our goal
    in this question.
    While shrinking for shrink check the validity of window if valid update the result if it's smaller than previous
    window/substring.
    We expand  until substring becomes valid. Once it's valid only then start shrinking.
    Only shrink on valid window.

    APPROACH
    ========

    1. create a freqMap of t and populate it.
    2. Maintain two pointers left and right starting from 0th index. Create a window freqmap to maintain freq of chars in window.
    3. Expand the right pointer and add to the freqmap. At each expansion check the validity. If it's valid update result and 
       start shrinking the window.

        Validity check
        3.1 If len(t) > len(substring) : Invalid
        3.2 for all the chars in t's freqmap , check if window freqmap is greater or equal
            for c in tfreqmap
            winfreqmap[c] > = tfreqmap[c]
    4. Now we have found valid substring/winodw,start shrinking the window from left.
       Increase left index by one and check the validity of winodw. If valid update result.
       If invalid then again start expanding.
*/


class Solution {
public:
    string minWindow(string s, string t) {

        int m = s.size();
        int n = t.size();
        if (m == 0 || n == 0 || m < n) return "";

        /* ASCII frequency arrays */
        vector<int> tFreq(128, 0);
        vector<int> windowFreq(128, 0);

        for (char c : t) {
            tFreq[c]++;
        }

        int required = 0;
        for (int i = 0; i < 128; ++i) {
            if (tFreq[i] > 0) required++;
        }

        int formed = 0;
        int left = 0;

        int minLen = INT_MAX;
        int startIdx = 0;

        for (int right = 0; right < m; ++right) {

            char c = s[right];
            windowFreq[c]++;

            /* Character just satisfied its requirement */
            if (tFreq[c] > 0 && windowFreq[c] == tFreq[c]) {
                formed++;
            }

            /* Shrink while window is valid */
            while (left <= right && formed == required) {

                int windowLen = right - left + 1;
                if (windowLen < minLen) {
                    minLen = windowLen;
                    startIdx = left;
                }

                char leftChar = s[left];
                windowFreq[leftChar]--;

                /* Character just became unsatisfied */
                if (tFreq[leftChar] > 0 &&
                    windowFreq[leftChar] < tFreq[leftChar]) {
                    formed--;
                }

                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};
