///////////////////////////////////////////////////////////
//
//	219. Contains Duplicate II
///////////////////////////////////////////////////////////



class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int iSize = nums.size();
        if( 0==iSize || 1== iSize )
            return false;
        bool retVal = false;
        unordered_map<int,int> unumMap;
        for(int i=0; i<iSize; ++i)
        {
            unordered_map<int,int>::iterator it = unumMap.find(nums[i]);
            if( unumMap.end()!= it && (abs(it->second-i) <=k) )
            {
                retVal = true;
                break;
            }
            else
            {
                unumMap[nums[i]]=i;
            }
        }
        return retVal;
    }
};