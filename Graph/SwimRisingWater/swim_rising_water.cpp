/*
  Swim in Rising Water

  This problem follows exact same solution as "Path with Minimum effort". Solve Path with Minimum effort first then solve this one.
 Simplified explanation:
 We just need to find a path going from top left to bottom right cell in the grid,
 such that the highest value on the path is the smallest possible out of all possible paths.

  Approach
  ========
  This can be solved using dijkstra algorithm.
*/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        /* pair is time, <rows,cols>*/
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        /* For (0,0) the time reqd is grid[0][0] and not 0. */
        pq.push(make_pair(grid[0][0], (make_pair(0,0))));
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols,1e9));
        dist[0][0] = grid[0][0];

        int deltarow[4] = {-1,0,1,0};
        int deltacol[4] = {0,1,0,-1}; 
        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int time = node.first;
            int xcord = node.second.first;
            int ycord = node.second.second;
            if(xcord == rows-1 && ycord == cols-1) return time;

            for(int i=0; i<4; ++i) {
                int neighrow = xcord+deltarow[i];
                int neighcol = ycord+deltacol[i];
                 if(neighrow>=0 && neighrow<rows && neighcol>=0 && neighcol<cols) {
                    int ntime = max(time, grid[neighrow][neighcol]);
                    if(ntime < dist[neighrow][neighcol]) {
                        dist[neighrow][neighcol] = ntime;
                        pq.push(make_pair(ntime, make_pair(neighrow,neighcol)));
                    }
                 }
            }
        }
        return 0;
    }
};