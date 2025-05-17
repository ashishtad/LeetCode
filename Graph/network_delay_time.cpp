/*
    This problem is typical Dijkstra Algo problem.
    We need to find out the shortest path array where k is the src node.
    Then we have to return the max of dist array of the algo,
    as the max time is the minimum time taken to reach all nodes.
    In other other words max time is the time taken to reach all nodes.

*/


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        /*Create adjacency list */
        vector<vector<pair<int,int>>> adjList(n+1);
        for( auto time:times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adjList[u].push_back(make_pair(v,w));
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        /* K is src node and time taken to reach k is 0 */
        pq.push(make_pair(0,k));
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        while(!pq.empty()) {
            auto [edgeTime, node] = pq.top();
            pq.pop();

            for(auto neigh: adjList[node]) {
                auto [neighNode, neighTime] = neigh;

                if(edgeTime+neighTime < dist[neighNode]) {
                    dist[neighNode] = edgeTime+neighTime;
                    pq.push(make_pair(edgeTime+neighTime, neighNode));
                }
            }
        }
        int minTime = -1;
        for(int i=1; i<=n; ++i) {
            if(dist[i] == 1e9) return -1;
            minTime = std::max(minTime, dist[i]);
        }
        return minTime;
    }
};