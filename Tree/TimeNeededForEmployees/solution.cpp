/* Refer notes for simplified description.

    This can be solved using dfs approach.
    We need frame a graph adjlist where manager will be key and it's subordinates as list.
    Do a DFS on the adj list. Time taken = informtime[i] + max(informtime of subordinates)
 */

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

        /* Frame the adjacency list */
        unordered_map<int, vector<int>> adjList;
        for (int emp = 0; emp < n; ++emp) {
            /* Head has -1 as mamanger , skip it */
            if (manager[emp] != -1) adjList[manager[emp]].push_back(emp);
        }
        /* DFS start with head */
        return timeTaken(headID, adjList, informTime);
        
    }
    int timeTaken(int emp, unordered_map<int, vector<int>> &adjList, const vector<int>& informTime) {
       int maxtime = 0;
        for (int sub : adjList[emp]) {
            maxtime = std::max(maxtime, timeTaken(sub, adjList, informTime));
        }
        return maxtime+informTime[emp];
    }
};