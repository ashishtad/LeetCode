/////////////////////////////////////////////////////////////////////////////////////////////////
//  
// Minimum Height Trees
// check for below refernces for design:
//  https://leetcode.com/problems/minimum-height-trees/discuss/76055/Share-some-thoughts
// https://www.youtube.com/watch?v=wQGQnyv_9hI&t=946s&ab_channel=NeetCodeIO
//
////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<int> result;
        if( 1== n)
        {
            result.push_back(0);
            return result;
            
        }
        list<int> *adj;
        adj = new list<int>[n];
        //step1:create adj list of graph
        for( vector<int> t:edges )
        {
            //undirected graph
            adj[t[0]].push_back( t[1]);
            adj[t[1]].push_back( t[0]);
        }
        //step2:find the leaf nodes and store it
        vector<int> leaves;
        for( int vertex=0; vertex<n; ++vertex)
        {
            //leaf nodes size will be 1
            if( adj[vertex].size() ==1 )
            {
                //push the leaf vertex
                leaves.push_back(vertex);
            }
        }
        #if 0
        printf("leaves\n");
        for ( auto i: leaves)
            printf("%d\t",i);
        #endif
        //step3: Remove the leaves level by level till we have exactly 2 nodes
        while( n> 2)
        {
            //As we are removing only leaf nodes
            n = n-leaves.size();
            vector<int> nextLeaves;
            for( auto leaf: leaves)
            {
                //Get the only adjacent node of leaf
                int nextNode = *(adj[leaf].begin());
                //Remove the leaf from adjacent node i.e cut the edges
               adj[nextNode].erase( std::find( adj[nextNode].begin(), adj[nextNode].end(),leaf) );
                //erase the leaf node itself
                adj[leaf].erase( std::find(adj[leaf].begin(),adj[leaf].end(),nextNode) );
                
                //After erase check if nextNode size is 1. i.e it became leaf so push in next leaves
                if( adj[nextNode].size()==1)
                    nextLeaves.push_back(nextNode);
            }
            leaves=nextLeaves;
        }
        
        return leaves;
    }
};