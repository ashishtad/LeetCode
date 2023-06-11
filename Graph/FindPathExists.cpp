//////////////////////////////////////////////////////////////
//
//  1971.Find if Path Exists in Graph
////////////////////////////////////////////////////////////////


class Solution {

public:
    list<int> *adj;
    void addEdge(int a, int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool dfs(int start, int end, int n){
        vector<bool> visited(n, false);
        if(start == end)
            return true;
        stack<int> stack;
        stack.push(start);
        
        while(!stack.empty()){
            int k = stack.top();
            stack.pop();
            
            visited[k] = true;
            for(auto it = adj[k].begin(); it != adj[k].end(); it++){
                if(*it == end) //valid path exists from start to end as its bidirectional 
                    return true;
                if(!visited[*it]){
                    stack.push(*it);
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        adj = new list<int>[n];
        for(int i = 0; i < edges.size(); i++)
            addEdge(edges[i][0], edges[i][1]);
        return dfs(start, end, n);
    }
};