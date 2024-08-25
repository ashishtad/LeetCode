/*
    Time Complexity: O(V + E)
    Space Complexity: O(V)  


    Time Complexity
    DFS Traversal:

    In the worst-case scenario, you perform a depth-first search (DFS) on every node. If the graph is dense and each node has many neighbors, the DFS will traverse all nodes and edges.
    Let V be the number of nodes (vertices) and E be the number of edges in the graph. In the DFS traversal, each node is processed once, and each edge is explored once.
    Thus, the time complexity for DFS is O(V + E).
    Memoization with safe_map:

    The safe_map ensures that nodes are processed only once. If a node has already been determined to be safe or unsafe, it is retrieved directly from the map, avoiding redundant calculations.
    Therefore, the time complexity remains O(V + E), as the algorithm efficiently skips revisiting already processed nodes.
    Iterating Over All Nodes:

    The outer loop iterates over each node once to initiate DFS. This is an O(V) operation.
    Thus, the overall time complexity of the solution is O(V + E).

    Space Complexity
    Recursive Stack:

    In the worst case, the recursive depth of the DFS can be up to O(V) (in the case of a linear graph).
    This results in an O(V) space complexity for the recursion stack.
    Safe Map (safe_map):

    The safe_map stores the results for each node, so its space complexity is O(V).
    Result Vector (res):

    The res vector stores the eventual safe nodes, which could be up to O(V) in size.
    Thus, the overall space complexity is O(V), since the safe_map, res, and the recursion stack all scale linearly with the number of nodes.

    Final Complexity:
    Time Complexity: O(V + E)
    Space Complexity: O(V)


*/

class Solution {
public:
    map<int,bool> safe_map;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        if( 0 == graph.size() )
            return res;
        int n = graph.size();
        /* Traverse each node sequencially */
        for( int node=0; node<n; ++node){
            /* Perform dfs on node and if it's terminal or
               all it's paths leads to terminal( no cycle) ,
               then it's a result candidate 
            */
            if( dfs_terminal(node,graph) )
                res.push_back(node);
        }
        return res;
    }

    bool dfs_terminal( int node, const vector<vector<int>> &graph){

        /* If already processed or in map return it's val */
        if( safe_map.find(node) != safe_map.end())
            return safe_map[node];
        /* Not proceseed yet, we don't know it's result make it false */
        safe_map[node] = false;
        /* Go thrugh the neighbours */
        for( int neigh: graph[node] ){
            if( !dfs_terminal(neigh,graph) )
                return safe_map[neigh];
        }
        /* Terminal node */
        safe_map[node] = true;
        return safe_map[node];

    }
};
