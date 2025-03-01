/*
Since both rows and columns are sorted, each element gives a clue on where to move next.
Start from the top-right corner (or bottom-left corner). These positions provide maximum decision power.
Time : O(M +N)
Space: O(1)
*/

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
            if(matrix.size()==0)
                return false;
            
            int row = matrix.size(), col = matrix[0].size();
            /* Start from top right corner*/
            int i = 0, j = col-1;
            while(i<row && j>=0) {
                if(matrix[i][j] == target)
                    return true;
                else if(matrix[i][j] > target)
                    --j; /* Move left */
                else
                    ++i; /* Move down */
            }
            return false;
            
        }
    };