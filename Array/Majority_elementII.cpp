
/*
    229. Majority Element II
    Intuition
    =========
    Here ask is to find elem which is more than n/3 times.
    Let say if we have n =8 n/3= floor(8/3)=2. More than n/3 means minimum it should be 3 times.
    say elem1 appears 3 times(which is minimum) and elem2 appears 3times. Both together makes 6time out of total size 8. 
    This gives us a result that at max only two elements can be more than n/3 times. Try it for varying n.

    We know for sure at max two elements can be our answer.

    This problem can be solved via 3 methods
    1. Brute force by checking each element and then looping again the array which makes complexity of time O(n^2) and const space.
    2. Using a hashmap which makes time complexity O(n) but space as o(n) in worst case as we need hashmap to store
    3. Using Boyre Moore's voting algorithm which makes O(n) time and constant space: This is most efficient.

    The logic of Majority element is leveraged with some modificatins.

*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {


        int ele1 = INT_MIN, ele2 = INT_MIN;
        int count1 = 0, count2 = 0;
        for(const int &num : nums) {
            if(0==count1 && ele2!=num) {
                ele1 = num;
                count1 = 1;
            } else if(0==count2 && ele1!=num) {
                ele2 = num;
                count2 +=1;
            } else if(num == ele1) count1 +=1;
            else if(num==ele2) count2 +=1;
            else{
                count1 -=1;
                count2 -=1;
            }
        }
         count1 = 0;
         count2 = 0;
         for(const int &num : nums) {
            if(ele1 == num) ++count1;
            if(ele2 == num) ++count2;
         }
         int len = nums.size();
         vector<int> res;
         if(count1 > len/3) res.push_back(ele1);
         if(count2 > len/3) res.push_back(ele2);

         return res;
        
    }
};