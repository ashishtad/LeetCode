//////////////////////////////////////////////////////////////////////////////////
//
//73. Set Matrix Zeroes
// Time complexity: O(M*N)
// Space complexity: O(1)
// Effective solution
//////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
         bool fr = false,fc = false; //marker for first row and column
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            if(matrix[i][j] == 0) {
                if(i == 0) fr = true;  //if any element in first row is zero
                if(j == 0) fc = true;  // If any element in first column is zero
                matrix[0][j] = 0;      //setting corresponding first cell of correspondng col
                matrix[i][0] = 0;    //setting first cell of corresponding row
            }
        }
    }
    //starting from matrix[1][1] as we have already marked first row and col elements in 
        // previous loop so no need to loop it again
    for(int i = 1; i < matrix.size(); i++) {
        for(int j = 1; j < matrix[0].size(); j++) {
            //If corresponding first elelmnt either of row or col is zero
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    //If first row is true i.e any one element in first row is zero as marked in above first loop
    //Mark entire row as zero
    if(fr) {
        for(int j = 0; j < matrix[0].size(); j++) {
            matrix[0][j] = 0;
        }
    }
    //If first col is true i.e any one element in first col is zero as marked in above first loop
    //Mark entire col as zero
    if(fc) {
        for(int i = 0; i < matrix.size(); i++) {
            matrix[i][0] = 0;
        }
    }
    }
};