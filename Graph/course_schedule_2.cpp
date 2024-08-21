/*
  Course Schedule II

  Author: Ashish Tad
  Date: 21/08/20224
  Similar approach as complexity as Course Schedule.
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> res;
        if( 0 == numCourses )
            return res; 
        /* If no prequisites then courses can be taken in any order.
            So push the courses in same order as they are.
         */
        if( 0 == prerequisites.size() ){
            for( int v =0; v<numCourses; ++v){
                res.push_back(v);
            }
            return res;
        }
            
        /* Build the adjacency list and indegree vector */
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adjList(numCourses);
        for( auto e: prerequisites){
            /* e[1] is a prequisite of e[0]*/
            adjList[e[1]].push_back(e[0]);
            ++indegree[e[0]];
        }
        getTopoSort(numCourses, adjList, indegree, res);
        if( numCourses != res.size())
            res.clear();
        return res;
    }

    void getTopoSort(int numcourse, const vector<vector<int>> &adjList,
                       vector<int> &indegree,
                       vector<int> &res ) {

        std::queue<int> enq;
        for( int v =0; v<numcourse; ++v){
            if( 0 == indegree[v])
                enq.push(v);
        }
        /* Cycle is there */
        if ( enq.empty())
            return;

        while( !enq.empty() ){
            int front_node = enq.front();
            enq.pop();
            res.push_back(front_node);

            for(auto neigh_node : adjList[front_node]){
                --indegree[neigh_node];
                if( (0 == indegree[neigh_node]) )
                    enq.push(neigh_node);
            }
        }
    }
};