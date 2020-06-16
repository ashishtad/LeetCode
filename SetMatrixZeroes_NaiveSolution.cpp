//////////////////////////////////////////////////////////////////////////////////
//
//73. Set Matrix Zeroes
// Time complexity: O(M*N)
// Space complexity: O(M+N)
// Naive approach
//////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        if( 0 == matrix.size() )
            return;
        int row = matrix.size();
        int col = matrix[0].size();
        //To mark the already visited elements
        bool **visited = new bool*[row];
        for( auto i =0; i<row; ++i)
        {
            visited[i] = new bool[col];
         }
        for( auto i=0; i<row; ++i)
        {
            for( auto j=0; j<col; ++j)
                visited[i][j] =false;
        }
        
        
        for(auto i=0; i<row; ++i)
        {
            for(auto j=0; j<col; ++j)
            {
                if( !visited[i][j] )
                {
                    if( 0== matrix[i][j])
                    {
                        setRowAndColumnToZero(matrix,i,j,visited,row,col);
                    }
                    visited[i][j] = true;
                } 
                
            }
        }
        //Deleting the viisted array
        for( auto i=0; i<row; ++i)
                delete[] visited[i];
        //Free array of pointers
        delete[] visited;
    }
    void setRowAndColumnToZero( vector<vector<int>>& matrix, int i, 
                               int j,bool **visited,int row,int col )
    {
        //setting corresponding row to zero
        for(auto k=0; k<col;++k)
        {
            //Setting to zero those which are non zero. 
            // Those cells which are zero/inputted as zero those needs to be traversed as 
            //coresponding row/cloumn needs to be set to zero.e.g for row: [0 2 0]
            // Only set second element ie to zero no need to set 3rd elem to zero because if that 
            // we are doing and marking it as visited then corresponding 3rd columen and will be                missed
            if( 0 !=matrix[i][k] )
            {
                //row i.e i will be constant. col: k will vary 
                matrix[i][k] = 0;
                 visited[i][k] = true;
            }
            
        }
        
        //setting corresponding column to zero
        for( auto k=0; k<row;++k)
        {
            
            if( 0 != matrix[k][j] )
            {
                //col:j will be constant row :k will vary
                matrix[k][j]= 0;
                visited[k][j] = true;
            }
            
        }
    }
};