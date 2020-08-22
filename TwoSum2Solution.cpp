///////////////////////////////////////////
//  167. Two Sum II - Input array is sorted
///////////////////////////////////////////////

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> result ;
       
        result.reserve(2);
        
        int inumSize = numbers.size();
        if( 0== inumSize) return result;
        
        int istart = 0;
        int iend = inumSize-1;
        
        while( istart <iend )
        {
            int sum = numbers[istart]+numbers[iend];
            if( sum == target)
            {
                
                result.push_back(istart+1);
                result.push_back(iend+1);
               
                break;
            }
            else if( sum> target ) iend-=1;
            else istart+=1;
        }
        
        
        return result;
        
    }
};