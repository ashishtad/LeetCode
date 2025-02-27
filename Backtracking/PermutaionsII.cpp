/*
     47. Permutations II
    Here we can't sort the nums and use the check if(i > index && nums[i] == nums[i - 1]) does not work correctly because:

    It is applied in a loop that modifies nums (due to swapping).
    It does not prevent duplicate permutations fully when nums[i] has already been used in the recursion.
    This condition is only useful when choosing elements from a sorted array without modifying their order, but here, swaps reorder elements dynamically.

    Solution:
    To figure out the duplicates , we should use a set or a unordered_set<int> to track used elements at each recursion level.
    Time complexity : O(N * N!) : N! is the total no of permuations and each permuation is of N length.
    Space complexity: O(N * N!) 
        Recursive Call Stack:

        The recursion depth is O(N) because at each step, we increment index by 1.
        So, the worst-case recursive stack usage is O(N).
        Result Storage (vector<vector<int>> result):

        We are storing N! unique permutations, each of size N.
        This contributes O(N × N!) space.
        Temporary Data Structures (unordered_set<int> used):

        This is used once per level of recursion and holds at most N elements.
        This contributes O(N) space per recursion level, but since it does not persist beyond each recursive call, it is O(N) in the worst case.


*/


class Solution {
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<vector<int>> result;
            backtrack(nums, 0, result);
            return result;
        }
    
        void backtrack(vector<int> nums, int index, vector<vector<int>>& result) {
            if (index == nums.size()) {
                result.push_back(nums);
                return;
            }
    
            unordered_set<int> used;  // Tracks numbers used at this recursion level
    
            for (int i = index; i < nums.size(); ++i) {
                if (used.count(nums[i])) continue;  // Skip if already used at this level
                used.insert(nums[i]);  // Mark as used
    
                swap(nums[i], nums[index]);
                backtrack(nums, index + 1, result);
                
            }
        }
    };
    