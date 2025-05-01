
/* 
    Number of Enclaves

 *  Simplified Problem Statement
    ============================
    In the given matrix 0 and 1 represents sea and land respectively.
    The expected output is to return number of 1's (land) from where you can't move out of the grid.

    Intuition
    =========
    1. From the land(1) at boundaries we can move out of grid.
    2. If #1 is true then the 1s which are connected to 1's at boundaries also can be move out of grid.
    3. So we can use DFS/BFS approach here.
    This problem pattern is exactly same as "Surrounded Regions".

    Approach
    ========
    1. Traverse the boundaries and identify 1 (land).
    2. For each 1 at boundary start BFS and mark them as visited. This is multi source BFS.
    3. Traverse the grid and return the count for the 1s which are not visited.

    Complexity Analysis
    ====================
    Time: 
    For BFS if all the cells are lands (1) then the q will go through m*n times.
    For each cell again we traverse 4 directions so 4*m*n.
    In end we traverse m*n to find remaining 1s .
    So overal : O(4*m*n) + O(m*n) ~= O(m*n)

    Space:
    visited matrix: O(m*n) + queue : O(m*n) in worst case + deltarow+deltacol fixed size
    Overall: ~O(m*n)


    Reference: https://www.youtube.com/watch?v=rxKcepXQgU4&ab_channel=takeUforward
 */


class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        std::queue<pair<int,int>> q;
        /* Boundary Traversal */

        for(int j=0; j<n; ++j) {
            /* First row */
            if(grid[0][j] == 1 && !visited[0][j]) {
                q.push(make_pair(0,j));
                visited[0][j] = 1;
            }

            /* Last row */
            if(grid[m-1][j] == 1 && !visited[m-1][j]) {
                q.push(make_pair(m-1,j)); 
                visited[m-1][j] = 1;
            } 
        }

        for(int i=0; i<m; ++i) {
            /* First col */
            if(grid[i][0] == 1 && !visited[i][0]) {
                q.push(make_pair(i,0));
                visited[i][0] = 1;
            }

            /* Last col */
            if(grid[i][n-1] == 1 && !visited[i][n-1]) {
                q.push(make_pair(i,n-1));
                visited[i][n-1] = 1;
            }
        }
        int deltarow[4] = {-1, 0, 1, 0};
        int deltacol[4] = {0, 1, 0, -1};
        /* Start BFS */
        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for(int i=0; i<4; ++i) {
                int neighrow = row+deltarow[i];
                int neighcol = col+deltacol[i];
                if(neighrow>=0 && neighrow<m && neighcol>=0 && neighcol<n &&
                   grid[neighrow][neighcol] == 1 && !visited[neighrow][neighcol]) {

                    q.push(make_pair(neighrow, neighcol));
                    visited[neighrow][neighcol] = 1;
                }
            }
        }
        /* Traverse the entire matrix now and count 1s which are not visited yet */
        int count = 0;
        for( int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == 1 && !visited[i][j]) ++count;
            }
        }
        return count;
    }
};