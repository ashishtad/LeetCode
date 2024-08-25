/*
    802. Find Eventual Safe States
	Time complexity : O(V+E)
	
	
	O(V): This accounts for the time spent processing each node once.
     We loop through all nodes  in the graph to build the reversed graph and calculate the in-degrees.
	O(E): This represents the time spent processing the edges. For each node,
     we process its outgoing edges, which in total is proportional to the number of edges in the graph.
	Therefore, the algorithm runs in O(V + E) time because we:
	Iterate through each node (V nodes).
	For each node, iterate through its neighbors (E edges).
	
	Space complexity: O(V)
	O(V): We need space to store the in-degrees of all nodes, 
    as well as for the queue and the result array.
	O(E): We need space to store the reversed graph. 
    The reversed graph contains exactly the same number of edges as the original graph, which is E.
*/

#include "iostream"
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        if( 0 == graph.size() )
            return res;
        int n = graph.size();
        vector<int> indegree(n,0);
        vector<vector<int>> reverseGraph(n);
        /* Reverse the graph to make it fit for topological sort */
        for( int node=0; node<n; ++node ){
            for(int neigh: graph[node]){
                reverseGraph[neigh].push_back(node);
                indegree[node]+=1;
            }   
        }

        /* Queue to perform topo sort*/
        queue<int> q;
        /* Get the nodes with 0 indegree. These are terminal nodes.*/
        for( int v=0; v<n; ++v){
            if( 0 == indegree[v]){
                q.push(v);
            }
        }
        /* If q empty it means no node has indegree 0 and no nod is terminal node*/
        if( q.empty() )
            return res;
        /* Perform usual topo sort */
        while( !q.empty() ){
            int node = q.front();
            q.pop();
            res.push_back(node);

            for( int neigh: reverseGraph[node]){
                indegree[neigh] -=1;
                if( 0 == indegree[neigh])
                    q.push(neigh);
            }
        }
        /* Sort the result */
        std::sort( res.begin(), res.end());
        return res;
    }
};
