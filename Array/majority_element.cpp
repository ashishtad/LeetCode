/*
169. Majority Element 
Boyre Morre's voting algorithm 
This is the most efficient approach for finding Majority element.
Boyre Moore's votingalgorithm
Time : O(N)
Space: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        if(0==nums.size()) return 0;

        int ele, count = 0;
        for(const int &num : nums) {
            if(0==count) {
                ele = num;
                count = 1;
            } else if(num == ele) count +=1;
            else count -= 1;
        }
         int cnt = 0;
         for(const int &num : nums) {
            if(ele == num) ++cnt;
         }
         if(cnt>nums.size()/2) return ele;

         return -1;
    }
};