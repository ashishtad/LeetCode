// A C++ Program to detect cycle in a graph
#include<bits/stdc++.h>

using namespace std;

class Graph
{
	int V; // No. of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists
	bool isCyclicUtil(int v, bool visited[], bool *rs); // used by isCyclic()
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // to add an edge to graph
	bool isCyclic(); // returns true if there is a cycle in this graph
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

bool Graph::isCyclic()
{
  bool *visited = new bool[V];
  for( int i=0;i<V;++i)
    visited[V]=false;
  
  stack<int> graphstack;
  graphstack.push( *(adj[0].begin()) );
  
  while( !graphstack.empty() )
  {
    int topelement = graphstack.top();
    //printf("Top ele=[%d]\n",topelement);
    graphstack.pop();
    if( visited[topelement] )
      return true;
    visited[topelement] = true;
    for(list<int>::iterator it = adj[topelement].begin(); it!=adj[topelement].end();++it)
    graphstack.push(*it);
  }
  return false;
}
int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	if(g.isCyclic())
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain cycle";
	return 0;
}
