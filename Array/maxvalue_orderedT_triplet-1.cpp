/*
    2873. Maximum Value of an Ordered Triplet I
    Brute force approach:
    Brute force is to use 3 loops.
     1. i from 0 to n
     2. j=i+1 to n
     3. k=j+1 to n
     For each diff = nums[i]-nums[j] calculate the (diff*k)
     The time complexity for this is O(n^3).

     Now with greedy approach let's try to optimise a bit.
     From nums[i]-nums[j]*nums[k] we know that to get maximum result,
     nums[i] and nums[k] needs to be max , especially nums[i].
     If nums[i] will be large then difference would be large.
     E.g 2 4 6 1 2 8 10
     Now in this if you see 2-4 = -2, 2-6=-2 ...
     We know we need to have nums[i] as large as possible.
     We'll take first elem as max and traverse until find any smaller than it and
     meanwhile if any larger no found update it as max.
     Till 2 4 6 we know 6 is largest so making this as index i would gives us the maximum difference.
     Keep j as 2 and k as j+1 and compute the operation.
     In this we will reduce the complexity to O(n^2).
     
     Reference:https://www.youtube.com/watch?v=sFY_14A28x0&ab_channel=NeetCodeIO

*/

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if(0 == n || n<3) return 0;

        long long maxLeft = nums[0]; 
        long long  result = 0;
        for(int j=1; j<n; ++j) {
            if(nums[j] >= maxLeft) {
                maxLeft = nums[j];
                continue;
            } 
            
            for(int k=j+1; k<n; ++k) {
                result = std::max(result, static_cast<long long>((maxLeft-nums[j])*nums[k]));
            }
        }
        return result;
    }
};