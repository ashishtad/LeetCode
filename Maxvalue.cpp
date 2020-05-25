////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1219. Path with Maximum Gold
// Solved : 24/5/2020
// Time complexity: O(M*N)
// Spcae complexity: O(M*N)
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        if( grid.empty())
            return 0;
        int maxGold =0;
        int m = grid.size(); // rows in grid
        int n = grid[0].size();  //columns in grid
        bool **visitedArray = new bool*[m]; //Keep track of visiting element
         for( int i =0; i<m; ++i)
        {
            visitedArray[i] = new bool[n];
         }
        
         for( int i =0; i<m; ++i)
        {
            for( int j=0; j<n; ++j)
                visitedArray[i][j] = false;
         }
        
        for( int i =0; i<m; ++i)
        {
            for( int j=0; j<n; ++j)
            {
                //process if only value is gretaer that zero as in condition
                //Never visit a cell with 0 gold.
                if( grid[i][j]> 0)
                {
                    int gold = FindMaxGold(grid,i,j,m,n,visitedArray );
                    maxGold=max(gold,maxGold);
                }
            }
        }
        return maxGold;
    }
    int FindMaxGold( vector<vector<int>>& grid,int i,int j,int m,int n,bool **visitedArray )
    {
        //Base conditions
        // 1. If value is zero return 0
        //2. If already viisited return 0
        //Out of bound elements return 0
        if(  i<0 || j<0 | (i>=m) || (j>=n) || (grid[i][j]==0) || (visitedArray[i][j]==true) )
            return 0;
        //since we are visting [i][j] element
        visitedArray[i][j]=true;
        int left=FindMaxGold(grid,i,j-1,m,n,visitedArray); //calculate for left element
        int right=FindMaxGold(grid,i,j+1,m,n,visitedArray);// right element
        int up=FindMaxGold(grid,i-1,j,m,n,visitedArray);// Up element
        int down=FindMaxGold(grid,i+1,j,m,n,visitedArray);//down element
        
        //max = max from all the sides + own value i.e grid[i][j]
        int val =max( max(left,right),max(up,down) )+grid[i][j];
        //since we are returning from [i][j] element by completing processing mark as false.
         visitedArray[i][j]=false;
        return val;
    }
};