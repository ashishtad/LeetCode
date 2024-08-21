
/*
        207. Course Schedule
        Approach is to use topological sort and check if all the courses are processed or no.
        If all courses are processed during topological sort then return true else false.

        The time complexity is O(V + E), where V is the number of courses and E is the number of prerequisites.

        The space complexity is also O(V + E) due to the following:

        Adjacency list: O(V + E) as each vertex can have multiple edges.
        Indegree vector: O(V) to store the indegree for each vertex.
        Queue: O(V) in the worst case when all vertices have 0 indegree.
        Visited array: O(V) to keep track of visited vertices.
        Therefore, the overall space complexity is O(V + E + V + V + E) = O(V + E).
*/


class Solution {
public:


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses ==0 || prerequisites.size() ==0 )
            return true;
        //Build the adjacency list and the indegree vector
        vector<vector<int>> adjList(numCourses);
        adjList.reserve(numCourses);
        vector<int> indegree(numCourses,0);
   
       for (auto p : prerequisites) {
            adjList[p[1]].push_back(p[0]);
            indegree[p[0]]++;
       }
       
        return getTopologicalSort(adjList,numCourses,indegree);
    }
    bool getTopologicalSort( const vector<vector<int>> &adjList, const int &numCourses, 
                             vector<int> &indegree) {

        queue<int> enq;
        vector<bool> visited(numCourses,false);

        //Check the vertex/course with 0 indegree or dependency and push to enq.
        for( int i =0; i<numCourses; ++i) {
            if( 0== indegree[i]) 
                enq.push(i);
        }
        //If no course has indegree 0 then cycle exists and the course can't be completed return false
        if( enq.empty())
            return false;
        
        //counter to keep track of the num of courses processed
        int course_processed = 0;
        while( !enq.empty()) {
            int course = enq.front();
            enq.pop();
            visited[course] = true;
            ++course_processed;
            for( int v: adjList[course]) {
                --indegree[v];
                if( 0 == indegree[v]) {
                    if( !visited[v])
                         enq.push(v);
                }
                   
            }
        }
        //If course_processed is same as total course count then task is completed.
        return (numCourses ==course_processed);

    }
};