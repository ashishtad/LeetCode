
/*
36. Valid Sudoku
 Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
*/


#include "iostream"
#include <vector>
#include<unordered_set>

using namespace std;


    bool isValidSudoku(vector<vector<char>>& board) {

        bool retVal = false;
        if(board.size() == 0)
            return retVal;
        
        int row = board.size();
        int col = board[0].size();

        vector<unordered_set<char>> row_set(row);
        vector<unordered_set<char>> col_set( col);

        //For sub grid
        vector<vector<unordered_set<char>>> subgrid_set(row/3, vector<unordered_set<char>>(col/3));
        for( int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){

                char elem = board[i][j];
                if( elem != '.'){
                    if( (row_set[i].find(elem) != row_set[i].end()) || 
                        (col_set[j].find(elem) != col_set[j].end()) ||
                        (subgrid_set[i/3][j/3].find(elem) !=subgrid_set[i][j].end()) )
                            return retVal;
                    else {

                        row_set[i].insert(elem);
                        col_set[j].insert(elem);
                        subgrid_set[i/3][j/3].insert(elem);
                    }
                }
            }
        }
        retVal = true;
        return retVal;
}

int main() {
    // Example of a valid Sudoku board
    std::vector<std::vector<char>> board =  {
        {'5', '3', '.', '.', '7', '.', '.', '9', '2'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '1', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    // Call the isValidSudoku function
   bool valid = isValidSudoku(board);

 // Print the result
    std::cout << (valid ? "The Sudoku board is valid." : "The Sudoku board is not valid.") << std::endl;

    return 0;
}