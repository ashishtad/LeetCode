/*
  Longest Cycle in a Graph
  ========================

  Intuition
  ==========
   This can be solved using dfs by detecting cycle in directed graph.
   Here a node can have only one outgoing edge.
   So for a node dfs where cycle detected is detected we need to calculate the length and return it.

   Approach
   ========
   1. Use same DFS traversal to detect cycle using visited array where 0: unvisited 1: visited 2: Cur visit path.
   2. Tarverse all the nodes and start DFS() for each node, dfs returns -1 for no cycle and if cycle then it returns lenth of cycle.
   3. For each return of dfs  calulate the maxlen.
   4. Coming to DFS function
        4.1 Same as cycle detection mark the node as cur vispath '2'.
        4.2 Maintain a map to keep track of starting point of DFS which node and it's corresponding distance.
            First node is at dist 1 and second at 2 and so on.
        4.3 Where ther is cycle detected for neighbour node visited and in cur vispath '2' then
            calcualate the cycle distance by subtracting the distance of neighnode and cur node.

    Time complexity:
    O(V+E) standard DFS complexity.
    Space
    visited array : O(V) + nodeDist map : O(V) in worst case
    Overall: O(V)
*/

class Solution {
     
     
     int dfs(int node, vector<int> &visited, const vector<vector<int>> &adjList, unordered_map<int, int> &nodeDist,int dist) {
        visited[node] = 2;
        /* First step of the node */
        nodeDist[node] = dist;
        int maxcycleLen = -1;
        for(int neigh : adjList[node]) {
            if(0 == visited[neigh]) {
               int len = dfs(neigh, visited, adjList, nodeDist, dist+1);
               if(-1 != len) maxcycleLen = std::max(maxcycleLen, len);
            } else if(2 == visited[neigh]) {
                maxcycleLen = std::max(maxcycleLen, (nodeDist[node]-nodeDist[neigh])+1);
            }
        }
        /* Reset the node vispath to 0 as we are returning back fom this node */
        visited[node] = 1;
        return maxcycleLen;
  }
public:
    int longestCycle(vector<int>& edges) {
        int V = edges.size();
        vector<vector<int>> adjList(V);
        for(int i=0; i<V; ++i) {
            if(-1 == edges[i]) continue;
            adjList[i].push_back(edges[i]);
        }
        
        vector<int> visited(V, 0);
   
        int maxlen = -1;
        for(int node=0; node<V; ++node) {
            if(0 == visited[node]) {
                /* To keep track of node(key) and it's current distance or step (value) */ 
                unordered_map<int, int> nodeDist;
               int len = dfs(node, visited, adjList, nodeDist, 1);
               maxlen = std::max(len, maxlen);
            }
        }
        return maxlen;
    }
};