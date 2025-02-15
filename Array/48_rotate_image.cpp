class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        if(matrix.size()==0)
            return;
        transposeMat(matrix);
        for(auto &row: matrix) {
            std::reverse(row.begin(), row.end());
        } 
    }
    void transposeMat(vector<vector<int>> &mat) {
        for(int i=0; i<mat.size(); ++i) {
            for(int j=i+1; j<mat[0].size(); ++j) {
                std::swap(mat[i][j], mat[j][i]);
                
            }
        }
    }
};