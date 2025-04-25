


/*

130. Surrounded Regions
  Intuition
  ==========
    1. The 'O's which are on boundary can not be converted to X as those are not surrounded by X on four sides 
       which is obvious.
    2. The 'O's which are connected from the boundary O also can't be converted to X.
    3. Only the Os which are sourrounded by X in all 4sides those are converted.

Approach
========
This problem can be solved by simple DFS/BFS traversal.

1. Take a visited matrix equivalent to input matrix.
2. Traverse only the boundaries i.e first,last row and first,last column.
3. On the boundary if found a O mark it as visited and start a DFS from it.
   On the way of DFS if any O found mark it as visited.
4. Start a fresh traversal of matrix : if found O and not visited simply convert to X.

Tip:
To traverse neighbours of a cell which is top, left, right , bottom.
for (row,col) cordinates
Top : row-1,col Right : row, col+1, Bottom: row+1,col left: row,col-1
So delta row {-1, 0, +1, 0}
delta col {0, +1, 0, -1}

Reeference: https://takeuforward.org/graph/surrounded-regions-replace-os-with-xs/

*/


class Solution {
private:

    void dfs(int row, int col, const vector<vector<char>>& board, vector<vector<int>> &visited, int deltarow[], int deltacol[],int m, int n) {
        visited[row][col] = 1;
        /* Four sides/cells of a corresponding cordinate top, right, bottom, left */
        for(int k=0; k<4; ++k) {
            int neighrow = row+deltarow[k];
            int neighcol = col+deltacol[k];
            if(neighrow>=0 && neighrow <m && neighcol>=0 && neighcol<n
               && board[neighrow][neighcol] == 'O' && !visited[neighrow][neighcol]) {
                 dfs(neighrow, neighcol, board, visited, deltarow, deltacol, m, n);
            }
        }
        
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        int deltarow[4] = {-1, 0, 1, 0};
        int deltacol[4] = {0, 1, 0, -1};
        /* Boundary traversal */
        for(int j=0; j<n; ++j) {
            /* First row */
            if(!visited[0][j] && board[0][j] == 'O') dfs(0, j, board, visited, deltarow, deltacol, m, n);

            /* Last row */
            if(!visited[m-1][j] && board[m-1][j] == 'O') dfs(m-1, j, board, visited,deltarow, deltacol, m, n); 
        }

        for(int i=0; i<m; ++i) {
            /* first col */
            if(!visited[i][0] && board[i][0] == 'O') dfs(i, 0, board, visited,deltarow, deltacol, m, n);

            /* last col */
            if(!visited[i][n-1] && board[i][n-1] == 'O') dfs(i, n-1, board,visited, deltarow, deltacol, m, n);
        }

        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(board[i][j] == 'O' && !visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};