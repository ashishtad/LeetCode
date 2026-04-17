class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {

        /* Create adjacency list */
        vector<vector<int>> adjList(n + 1);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        int res = 0;
        /* Bipartite check and component discovery */
        vector<int> iscolor(n + 1, -1);
        for (int node = 1; node <= n; ++node) {
            if (-1 == iscolor[node]) {
                /* This represents one connected comp */
                vector<int> compList;
                if (!checkBipartite(node, adjList, iscolor, 0, compList)) return -1;
                /* For this component, compute max BFS levels */
                int maxLevel = 0;
                for (int v : compList) {
                    maxLevel = max(maxLevel, bfsLevel(v, adjList, n));
                }
                res += maxLevel;
            }
        }
        return res;
    }

   
   // BFS to compute levels from a node
    int bfsLevel(int start, vector<vector<int>>& adj, int n) {

        vector<bool> visited(n + 1, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        int level = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int node = q.front(); q.pop();

                for (int nei : adj[node]) {
                    if (!visited[nei]) {
                        visited[nei] = true;
                        q.push(nei);
                    }
                }
            }
            level++;
        }
        return level;
    }

    
    bool checkBipartite(int v, vector<vector<int>>& adjList,
                        vector<int>& iscolor, int color, vector<int> &comp) {
        iscolor[v] = color;
        queue<int> q;
        q.push(v);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            comp.push_back(node);

            for (int neigh : adjList[node]) {
                if (-1 == iscolor[neigh]) {
                    iscolor[neigh] = !iscolor[node];
                    q.push(neigh);
                } else if (iscolor[neigh] == iscolor[node])
                    return false;
            }
        }
        return true;
    }
};