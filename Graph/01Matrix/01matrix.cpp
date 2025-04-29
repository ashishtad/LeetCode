

/*
  542. 01 Matrix
  Approach
  ========

  This can be solved by multi source BFS.
  1. Traverse the matrix and get the cordinates of all 0's and push them to queue in format(x,y),0 -> x,y are cordinates.
     0 is the distance travelled for nearest 0 , since this cell is 0 itself so 0 distance is traveled.
  2. Push all the above to queue and mark them visited in a visited matrix.
  3. For each elem in queue pop it and update the distance in resultant distance matrix. This is the reqd resultant distance for this cell.
     Then start BFS for the cell in all 4 directions i.e top, left, bottom, right and push the cell cordinates and distance to queue if not visited.
     Note: Here the distance would increase by 1 in each step.

     Reference: https://takeuforward.org/graph/distance-of-nearest-cell-having-1/
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        queue<tuple<int, int, int>> q;
        for(int x=0; x<m; ++x) {
            for(int y=0; y<n; ++y) {
                if(mat[x][y] == 0) {
                    /* 0 is the distance as cell is 0 itself, x and y are the cordinates  */
                    tuple<int,int,int> cell = {x,y,0};
                    q.push(cell);
                    visited[x][y] = 1; 
                }
            }
        }
        int deltarow[4] = {-1, 0, 1, 0};
        int deltacol[4] = {0, 1, 0, -1};
        while(!q.empty()) {
            auto [x, y, distance] = q.front();
            q.pop();
            dist[x][y] = distance;
            /* Start BFS for the cell */

            for(int i=0; i<4; ++i) {
                int neighrow = x + deltarow[i];
                int neighcol = y + deltacol[i];
                int d = distance + 1;
                if( neighrow>=0 && neighrow<m &&
                   neighcol>=0 && neighcol<n && 0 == visited[neighrow][neighcol]) {
                    q.push({neighrow, neighcol, d});
                    visited[neighrow][neighcol] = 1;
                }
            }
        }
        return dist;
    }
};