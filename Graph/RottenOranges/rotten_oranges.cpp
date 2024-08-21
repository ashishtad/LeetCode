/*
	Author: Ashish Tad
	Dtae: 15/08/2024
    Complexity
    Time: O(n*m) As all nodes needs to be traversed
    Space: O(n*m) In worst case every cell can be enqued and dequeed once
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if( 0 == row)
            return -1;
        
        int fresh_oranges = 0;
        /* To push rotten oranges cordinates*/
        std::queue<pair<int,int>> q;
        /* Traverse the grid and calculate fresh oranges */
        for( int i=0; i<row; ++i){
            for( int j=0; j<col; ++j){
                if( grid[i][j] == 1 )
                    fresh_oranges += 1;
                else if( grid[i][j] == 2){
                    /* Rotten found push it to q*/
                    q.push(make_pair(i,j));
                }
            }
        }
        int minutes = 0;
        /* Cordinates to identify the adjacent cells */
        vector<pair<int,int>> dimension = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        /* Do multi source BFS from the queue */
        while( !q.empty() && fresh_oranges>0 ){
            /* This is one unit of time.
                In one unit we need to process the rotten
                oranges existing in queue, and then mark the 
                next set of fresh ornages as rotten.
                Push them to queue. 
            */
            int bfs_node_count = q.size();
            for( int i=0; i<bfs_node_count; ++i){
                auto [x,y] = q.front();
                q.pop();
                for( auto cordinate: dimension){
                    int nx = x + cordinate.first;
                    int ny = y + cordinate.second;
                    /* Check for valid grid and the grid must contain fresh orange */
                    if( (nx>=0 && nx<row) && (ny>=0 && ny<col) &&
                        grid[nx][ny]==1) {
                            /* Mark the grid as rotten*/
                            grid[nx][ny] = 2;
                            fresh_oranges -=1;
                            q.push(make_pair(nx,ny));
                        }
                }
            } /* One unit of time elapsed here.*/
            minutes += 1;
            /* In next iteration of while next unit of time starts.*/
        }
        /* If still fresh oranges exist return -1*/
        return ( fresh_oranges>0) ? -1: minutes;
    }
};