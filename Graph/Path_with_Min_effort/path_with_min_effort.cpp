/*
    1631. Path With Minimum Effort

    This is classic dijkstra algorithm problem with some additional processing.
 
*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push(make_pair(0, (make_pair(0,0))));
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols,1e9));
        dist[0][0] = 0;

        int deltarow[4] = {-1,0,1,0};
        int deltacol[4] = {0,1,0,-1};
        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int diff = node.first;
            int xcord = node.second.first;
            int ycord = node.second.second;
            /*Destination fetched and this has minimum effort */
            if( (xcord == rows-1) && (ycord == cols-1) ) return dist[xcord][ycord];
            /* Traverse the 4 adjacent cells */
            for(int i=0; i<4; ++i) {
                int neighrow = xcord+deltarow[i];
                int neighcol = ycord+deltacol[i];
                if(neighrow>=0 && neighrow<rows && neighcol>=0 && neighcol<cols) {
                    int neighdiff = abs(heights[neighrow][neighcol]-heights[xcord][ycord]);
                    int effort = max(neighdiff, diff);
                    if(effort < dist[neighrow][neighcol]) {
                        dist[neighrow][neighcol] = effort;
                        pq.push(make_pair(effort, make_pair(neighrow,neighcol)));
                    }
                }
            }
        }
        return 0;
        
    }
};