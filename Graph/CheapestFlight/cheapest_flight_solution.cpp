
/*
	787. Cheapest Flights Within K Stops
	Time Complexity:
	Graph Construction: O(E) Where E is number of flights.
	BFS Traversal:
		The outer loop runs at most K+1 times (for each stop level)
		The inner loop processes each node in the queue, and each node can push its neighbors into the queue.
		In the worst case, every node and every edge is processed, leading to O((K+1) * E)
		
	Overall compleity: O((K+1)*E)
	
	Space Complexity:
		Graph Representation : O(E) space for adj list
		Queue: O(V) V is number of cities
		dist: O(V)
	overall: O(V+E)
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
     
        /* Create an adjacency list to represent the graph.
           Each element in vector represents source city and in it
           pair of{dst,cost} */
        vector<vector<pair<int,int>>> adjList(n);
        for(int i=0; i<flights.size(); ++i){
            adjList[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
        }
        /*
          Adjacency list will look like this now:
          0 : {1,100}
          1 : {2,100}, {3,600}
          2 : {0,100}, {3,200}    
          3 : 
         */
        /*
            This queue is used to do th BFS of each city and neighbouring cities.
            dist to update the cheapest cost to reach ith city in dist[i].
        */
        std::queue<pair<int,int>> q;
        vector<int> dist(n,INT_MAX);
        /* Push src city and cost 0 */
        q.push(make_pair(src,0));
        /* Loop through k=0 and some more nodes to process in q*/
        while( !q.empty() && k-->=0 ){
            int neighbor_nodes = q.size();
            /* Loop through each level of nodes [BFS]*/
            while(neighbor_nodes--){
                int node = q.front().first;
                int cost = q.front().second;
                q.pop();
                /* visit neighbour nodes of node*/
                for( auto adjNodes : adjList[node]){
                    int cost_foradjNode = cost+adjNodes.second; /* cost -> cost to reach this node which is currently processed*/
                    /* 
                        If cheaper path found to reach city. Update dist and push to queue.
                     */
                    if(dist[adjNodes.first] > cost_foradjNode ){
                        dist[adjNodes.first] = cost_foradjNode;
                        q.push(make_pair(adjNodes.first,cost_foradjNode));
                    }

                }
            }
        }
        return ((dist[dst] != INT_MAX) ? dist[dst] :-1);
    }
};
