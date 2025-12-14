/*
  Basically it's just: "Find the longest continuous sub array that has at most 2 distinct elements.

  Approach
  ========
  1. Take a frequency map to frame frequency of window.
  2. Expand the window until it's valid.
  3. When invalid winodw form , start shrinkinf the window until it becomes valid.

  Complexity.
  Time: O(N)
  Space: O()
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size();
        if (0 == n) return 0;
        if (1 == n) return 1;
        /* Map of fruit and freq */
        unordered_map<int,int> fruitFreq;
        int left = 0;
        int res = 0;
        for (int right=0; right<n; ++right) {

            fruitFreq[fruits[right]] += 1;

            /* Invalid window - shrink the winodw until it becomes valid */
            while (fruitFreq.size() > 2) {
                /* Remove from left - increase left pointer*/
                if (--fruitFreq[fruits[left]] == 0) fruitFreq.erase(fruits[left]);
                ++left;
            }
            /* Valid window */
            res = std::max(res, (right-left)+1);
            
        }
        return res;
        
    }
}