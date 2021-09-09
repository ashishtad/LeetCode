/////////////////////////////////////////////////////////////////////////////////////////////////
// To identify the judge: 
// All the people should trust judge so truct count should be n-1. as judge don't trust himself
// Draw an edge from trusting to trusted people and represent as graph for better visualization.
//
///////////////////////////////////////////////////////////////////////////////////////////////////



class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        int result =-1;
        vector<int> trustCount(n+1,0);//n+1 as people are from 1 to n not from 0
        
        for( vector<int> t:trust )
        {
            trustCount[t[0]]--; // t[0] is the trusting people so --1.This can't be judge as it  trusts
            trustCount[t[1]]++;//t[1] is the trusted people . candidate for judge so ++1.
        }
        
        for( int i=1; i<=n;++i)
        {
            if( trustCount[i]==n-1)// For the judge all people except itself trusts.
                                    // So count of trust should be n-1
            {
                result=i;
                break;
            }
        }
        return result;
    }
};