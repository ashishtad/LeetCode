
/*
    1886. Determine Whether Matrix Can Be Obtained By Rotation

    Solution
    =========
    Here we need to know how the matrix rotation works.
    Consider matrix as a square which it is so it can be rotated max 3 times to get
    different results. On 4th rotation it would be back to it's original state.

    Each clockwise rotation or 90 degree rotation = transpose of matrix + reverse each row of matrix.
    Similarly for 180 degree = 2*(transpose of matrix + reverse each row of matrix)  and so on..

    Final Complexity Breakdown for Rotation
    Transpose : O(N^2)
    Reverse each row: O(N) -> O(N^2) for N rows
    overall - 3*O(N^2)
*/

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        if(mat.size() == 0 || target.size() == 0)
            return false;
        /* 0 rotation check*/        
        if(mat==target)
            return true;
        /* 3 rotations for 90,180 and 270 degree respectovely.
           Each loop does a 90degree rotation = transpose + reversing each row.
         */
        for( int rotate_count=0; rotate_count<3; ++rotate_count) {
            transposeMat(mat);
            for(auto &row: mat) {
               std::reverse(row.begin(), row.end());
            } 
            if(mat==target)
                return true;
        }
        return false; 
    }

    void transposeMat(vector<vector<int>> &mat) {
        for(int i=0; i<mat.size(); ++i) {
            for(int j=i+1; j<mat[0].size(); ++j) {
                std::swap(mat[i][j], mat[j][i]);
                
            }
        }
    }
};