
/*
    Is Graph Bipartite?

* In simple words, a graph is said to be a Bipartite Graph,
  if we are able to colour the graph using 2 colours such that no adjacent nodes have the same colour.

  Reference: https://www.youtube.com/watch?v=KG5YFfR0j8A&ab_channel=takeUforward
             https://rohithv63.medium.com/graph-algorithm-bipartite-graph-dfs-f7f6a4afed4c
*/

class Solution {
private:
    bool dfs(int v, const vector<vector<int>>& graph, vector<int> &iscolor, int inputcol) {
        iscolor[v] = inputcol;
        for(int neigh: graph[v]) {
            if(-1 == iscolor[neigh]) {
                if(false == dfs(neigh, graph, iscolor, !inputcol)) return false;
            } else if(inputcol == iscolor[neigh]) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> iscolor(n, -1);

        for(int v=0; v<n; ++v) {
            if(-1 == iscolor[v]) {
                if(false == dfs(v, graph, iscolor, 0)) return false;
            }
        }
        return true;
    }
};