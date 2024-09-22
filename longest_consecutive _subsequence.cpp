/*
    Approach :
    The idea is to do this in O(n) time.
    So std::sort won't be applicable here.

    Take a set and populate the input vector.
    Then traverse each element in nums
    and for each num try to search the consecutive subsequence.

    How? For each num if there exists num-1 then it can't be a starting of consecutive subseuence.
    If num-1 does not exits(can be traeted as starting of subseq), then check if num+1, num+2..exists in set.

    Manipulate th max len accordingly.
    Time : O(2n) = O(n)
    Space: O(n)
*/
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if( nums.size() == 0 )
            return 0;
        int result = INT_MIN;
        std:unordered_set<int> uset(nums.begin(), nums.end());
        for( const int &num : nums){
            /* If num-1 is not present in set.
               That means this num can be used
               as starting of sequence. 
             */
            if( uset.end() == uset.find(num-1)) {
                /* Since starting subsequence is num */
                int len = 1;
                /* find num+1, num+2 i.e num+len is present in set */
                while( uset.end() != uset.find(num+len))
                    ++len;
                
                result = std::max(result,len);
            }
        
        }
        return result;
    }
};