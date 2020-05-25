//////////////////////////////////////////////////////////////
// 39. Combination Sum
// Solved : 25/05/2020
/////////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> result;
        vector<int> temp;
         FindCombinations(candidates,target,0,temp,result);
        
        return result;
        
    }
    //This functions runs on recursive DFS to find all the combinations
    //index: current index working on
    //temp: temporary vector to store intermoediate results
    void FindCombinations(vector<int>& candidates,int target,int index, vector<int> &temp,vector<vector<int>> &result)
    {
        //Base conditon:
        // If target is less than zero return
        //If target is equal to zero, we got one combination. Push to result
       
        if( target<=0)
        {
            if( 0 == target)
                result.push_back(temp);
            return ;
        }
        //Out of bound input vector check
        if( index<candidates.size() )
        {
            int value = candidates[index];
            temp.push_back(value);
            FindCombinations(candidates,target-value,index,temp,result); //new target should be difference of curent index element
            //Control returned after doing all the combinations of ith index.
            //Now we need to erase the last element of temp and perform the combinations by taking i+1th index
            temp.pop_back();
            //No need to change the target.It will be 
            FindCombinations(candidates,target,index+1,temp,result);
            
        }
        
    }
    
};

