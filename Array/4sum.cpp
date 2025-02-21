/*
* 18. 4Sum
* Time complexity: O(n^3)
* Space complexity :O (1)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        size_t size = nums.size();
        vector<vector<int>> result;
        if(size<=3)
            return result;
        
        std::sort(nums.begin(), nums.end());
        
        for(int i=0; i<size-3; ++i) {
            if( i>0 && (nums[i] == nums[i-1]))
                continue;

            for(int j=i+1; j<size-2; ++j) {
                if(j>i+1 && (nums[j] == nums[j-1]))
                    continue;
                long long temp_target = (long long) target- ((long long)(nums[i]+nums[j]));
                int left = j+1;
                int right = size-1;

                while(left<right) {
                    if(nums[left]+nums[right] == temp_target){
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while( left<right && (nums[left] == nums[left+1])) ++left;
                        while(left<right && (nums[right] == nums[right-1])) --right;
                        
                        ++left;
                        --right;
                    } else if(nums[left]+nums[right] < temp_target) {
                        ++left;
                    } else{
                        --right;
                    }
                }
            }
        }
        return result;
    }
};