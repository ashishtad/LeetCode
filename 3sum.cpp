
/*15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

/*

TWO POINTER APPROACH

Requirements we need to fulfil: Find the triplets having sum = 0.

As array has both -ve and +ve numbers, firstly we sort the array. Sorted array would have -ve numbers together and +ve numbers together in an increasing order. This will make easy for searching the required numbers to make a 0 sum.

Base cases after sorting:

If array size is < 3, means no triplet would exist from that array. Return empty vector of vectors.
If first element is +ve, that means there is no -ve number by which we can make a 0 triplet sum. Return empty vector of vectors.
Two Pointer Approach:
The basic thinking logic for this is: Fix any one number in sorted array and find the other two numbers after it. The other two numbers can be easily found using two pointers (as array is sorted) and two numbers should have sum = -1*(fixed number).

Traverse the array and fix a number at every iteration.
If number fixed is +ve, break there because we can't make it zero by searching after it.
If number is getting repeated, ignore the lower loop and continue. This is for unique triplets. We want the last instance of the fixed number, if it is repeated.
Make two pointers high and low, and initialize sum as 0.
Search between two pointers, just similiar to binary search. Sum = num[i] + num[low] + num[high].
If sum is -ve, means, we need more +ve numbers to make it 0, increament low (low++).
If sum is +ve, means, we need more -ve numbers to make it 0, decreament high (high--).
If sum is 0, that means we have found the required triplet, push it in answer vector.
Now again, to avoid duplicate triplets, we have to navigate to last occurences of num[low] and num[high] respectively. Update the low and high with last occurences of low and high.

Time complexity: O(logn) for sort + O(n*k) 
Space complexity : O(1)

*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        std::sort(nums.begin(),nums.end());
        //If after sort first element is positive then we can't achieve sum=0
        if ( nums.size() <3 || nums[0] >0 )
            return {};

        vector<vector<int>> result;
        
        for( int i=0; i< nums.size(); ++i ) {
            //If num is +ve break here, as we can't achieve sum as zero from here.
            //The array is already sorted and hence no -ve numbers after it.
            if ( nums[i] > 0 )
                break;
            //Avoid duplicate triplet
            if ( i>0 && nums[i] == nums[i-1] )
                continue;
            
            int low = i+1;
            int high = nums.size()-1;

            while( low < high ) {
                int sum = nums[i]+nums[low]+nums[high];
                if( sum > 0)
                    --high;
                else if( sum < 0 )
                    ++low;
                else {
                    //found triplet
                    result.push_back({nums[i],nums[low],nums[high]});
                    int last_low = nums[low];
                    int last_high = nums[high];
                    //Avoid duplicates for the triplet starting with nums[i]
                    while ( low < high && nums[low] == last_low )
                        ++low;
                    
                    while ( low < high && nums[high] == last_high )
                        --high;

                }
            }

        }

        return result;

    }
};


/*

HashMap Approach:
In this approach, firstly, we will hash the indices of all elements in a hashMap. In case of repeated elements, the last occurence index would be stored in hashMap.

Here also we fix a number (num[i]), by traversing the loop. But the loop traversal here for fixing numbers would leave last two indices. These last two indices would be covered by the nested loop.
If number fixed is +ve, break there because we can't make it zero by searching after it.
Make a nested loop to fix a number after the first fixed number. (num[j])
To make sum 0, we would require the -ve sum of both fixed numbers. Let us say this required.
Now, we will find the this required number in hashMap. If it exists in hashmap and its last occurrence index > 2nd fixed index, we found our triplet. Push it in answer vector.
Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
Update i to last occurence of 1st fixed number to avoid duplicate triplets.
Return answer vector.
*/

class Solution {
 public:
 vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    unordered_map<int, int> m;
    sort(nums.begin(), nums.end());    
    
    int n = nums.size();
    
    if (n < 3) return {}; 
    if (nums[0] > 0) return {}; 
    
    for (int i = 0; i < n; i++)
        m[nums[i]] = i;
    
    for (int i = 0; i < n - 2; i++) {
        if (i != 0 && nums[i] == nums[i - 1]) continue;
        if (nums[i] > 0) return ans;
        
        for (int j = i + 1; j < n - 1; j++) {
            
            if (j != i + 1 && nums[j] == nums[j - 1]) continue; // update j to avoid duplicate triplets
            
            int key = -(nums[i] + nums[j]);
            if (m.find(key) != m.end() && m[key] > j) // check the index of key > j, so we dont count any duplicate element
                ans.push_back({nums[i], nums[j], key});
        }
    }
    return ans;
}
};