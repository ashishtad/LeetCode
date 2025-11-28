/*
Find the Safest Path in a Grid.

 Intuition
 =========
 We have to maximise the safeness factor. Start from 0,0 and end is bottom right cell.
 We have to take  a path which is most safest i.e safety factor is maximum.
 Reference: https://www.youtube.com/watch?v=-5mQcNiVWTs&t=702s
 Check this reference only for approach.

  Approach
  ========

  1. Determine the minimum manhattan distance of each cell having 0 (no thief) from the cell with 1 (thief).

     1.1 Initialise a safetydist matrix and populate the 1's cell with 0(as distance from 1cell to same cell 
     is 0) and 0's cell as INT_MAX. This represents manhattan distance of all the cells. Basically we marked the thief 
     cells as 0 distance.
     1.2 Push these thief cordinates in a queue.
     1.2 Pop these cordinates and calculate the distance of neighbouring cells and push them in queue if not
      visited yet. Distance between the immediate neighbour cell in all 4dirs is 1.

      In the end of this we are having a dist matrix populated with safety distances from thieves.
      This is inspired from multi source BFS - "01 Matrix problem".

   2. We have to maximise the safety so we have to take the path having highest safety values.
      The intuition here is use Dijkstra.

      2.1 Please note we don't have to calculate minimum rather the maximum so take max heap.
      2.2 Take the result dist matrix and initialise with -1. 
      2.3 Take priority queue - max heap and start from 0,0. Push the safety diff and the cords.
      2.4 Follow the dijkstra.
      2.5 The “relaxation” rule
        When moving from one cell to a neighbor: nextSafety = min(currSafety, safetydist[nr][nc])
        And update only if:nextSafety > best[nr][nc]
        Because the safety of a path is defined as:
        “the minimum safety value among all cells on the path”
        Think of a path like a chain:
        The weakest (least safe) cell determines the safety of the whole path.
        Just like a chain’s strength = strength of the weakest link.

        This step is inspired from "swim in rising water" problem.
*/


class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        /* If thief is at start (0,0) then there is no safe path */
        if (grid[0][0] == 1) return 0;
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> safetydist (rows, vector<int>(cols, 1e9));
        queue<pair<int,int>> q;
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                if (1 == grid[i][j]) {
                    safetydist[i][j] = 0;
                    q.emplace(i,j);
                }
            }
        }

        vector<vector<int>> ncords = {{-1,0}, {0,-1}, {0,1}, {1,0}};
        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            for (auto ncord : ncords) {
                int neighx = x+ncord[0];
                int neighy = y+ncord[1];

                if (neighx>=0 && neighx<rows && neighy>=0 && neighy<cols) {
                    if (safetydist[neighx][neighy] == 1e9) {
                        safetydist[neighx][neighy] = safetydist[x][y]+1;
                        q.emplace(neighx, neighy);
                    }
                }
            }
        }

        /* Step-2 Dijkstra */

        vector<vector<int>> bestdist (rows, vector<int>(cols, -1));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>> pq;

        pq.push(make_pair(safetydist[0][0],make_pair(0,0)));
        bestdist[0][0] = safetydist[0][0];

        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            int cursafety = node.first;
            auto [x,y] = node.second;
            /* Destination found */
            if (x == rows-1 && y == cols-1) return bestdist[x][y];

            for (auto ncord : ncords) {
                int neighx = x+ncord[0];
                int neighy = y+ncord[1];

                if (neighx>=0 && neighx<rows && neighy>=0 && neighy<cols) {
                    int nextsafety = std::min(cursafety,safetydist[neighx][neighy]);
                    if (nextsafety > bestdist[neighx][neighy]) {
                        bestdist[neighx][neighy] = nextsafety;
                        pq.push(make_pair(nextsafety, make_pair(neighx,neighy)));
                    }
                }
            }
        }
      
        return 0;
        
    }
};
