/*
  2101. Detonate the Maximum Bombs
* 1. Calculate the distance of each bomb to all other bombs in list.
     Distance , d= sqrt(x^2+ y^2) => sqrt ((x1-x2)^2 + (y1-y2)^2)
  2. Create adjlist say for bomb A can detonate bomb B  , then a directed edge from A to B.
     if distance d >= radius of B then A --> B in graph and adjlist.

  2. After creation of adjlist we have the dependency graph of each bomb.
  3. Do DFS/BFS of each node in adjlist and calculate which is having the maximum nodes. 

  Complexity
  Time: Building adj list O(n^2) + DFS for each node n*O(N+E) = O(N^2)
  Space: For DFS stack : O(N)+ visited vector:O(N)
*/

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {

        unordered_map<int, vector<int>> adjList;
        int n = bombs.size();
        for( int i=0; i<n; ++i) {
            double x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];

            for( int j=i+1; j<n; ++j) {
                double x2 =  bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                double x1x2 = x1-x2 , y1y2 = y1-y2;
                double dist = sqrt( x1x2*x1x2 + y1y2*y1y2);
                /* bomb i can detonate bomb j as r1 contains the dist*/
                if(dist <= r1) adjList[i].push_back(j);
                if(dist <= r2) adjList[j].push_back(i);
            }
        }

        /* Do the DFS */
        int res = 0;
        for(int i=0; i<n; ++i) {
            res = max(res, dfs(i, n, adjList));
        }
        return res;
        
    }
    private:

    int dfs(int start, int n,   unordered_map<int, vector<int>> &adjList) {
        vector<bool> visited(n, false);
        stack<int> st;
        int count = 0;
        st.push(start);
        visited[start] = true;

        while(!st.empty()) {
            int node = st.top();
            st.pop();
            ++count;
            for( const int &neighbour : adjList[node]) {
                if(!visited[neighbour]) {
                    st.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        return count;
    }
};