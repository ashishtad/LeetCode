

/*
   Number of Islands

*  Intuition
   ==========
   The goal is to find the number of islands or in other words the number of connected '1's.
   A group of connected '1's is an island surrounded by '0's. So we need to find out the group of
   connected 1s. The number of such groups is the result.

   Approach
   ========
   We can solve this by simple DFS/BFS traversal approach.
   1. Travrese the matrix - if found 1(land) start BFS if not visited. 
      By BFS we will cover all the connected 1s to it and mark them visited.
   2. Increment result counter after finish of BFS, since we have traversed all the connected 1s by now.

    Note: A land or 1 can be connected in all 4 directions i.e top, right, bottom, left cell.
    Ref: https://www.youtube.com/watch?v=muncqlKJrH0&ab_channel=takeUforward
*/

class Solution {

private:
    void DFS(int row, int col, const vector<vector<char>>& grid, vector<vector<int>> &visited, int m, int n, int deltarow[], int deltacol[]) {
        
        visited[row][col] = 1;

            for(int i=0; i<4; ++i) {
                int neighrow = row+deltarow[i];
                int neighcol = col+deltacol[i];
                if(neighrow>=0 && neighrow<m && neighcol>=0 && neighcol<n && grid[neighrow][neighcol]=='1' && !visited[neighrow][neighcol]) {
                   DFS(neighrow, neighcol, grid, visited, m, n, deltarow, deltacol);
                   visited[neighrow][neighcol] = 1;
                }
            }
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int deltarow[4] = {-1, 0, 1, 0};
        int deltacol[4] = {0, 1, 0, -1};
        int count = 0;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    DFS(i, j, grid, visited, m, n, deltarow, deltacol);
                    ++count;
                }
                
            }
        }
        return count;
    }
};