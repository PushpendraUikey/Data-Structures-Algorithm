#include<bits/stdc++.h>
using namespace std;

//// Prism algorithm to find the Minimum spanning Tree
//// Nodes start from 1;


vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, 
vector<pair<pair<int, int>, int>> &g)
{
    // create adjacency list
    unordered_map< int, list< pair<int, int> > > adj;

    for(int i=0; i<g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for(int i=0; i<=n; i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    //// source node process
    key[1] = 0;
    parent[1] = -1;

    for(int i=1; i<=n; i++){
        int mini = INT_MAX;
        int u;
        /// find min node
        for(int v =1; v<=n; v++){           // can be done using heaps which reduces time complexity
            if( !mst[v] && key[v] < mini){  // which hasn't already formed mst and has minimum key value
                u = v;                      //// minimum node
                mini = key[v];
            }
        }
        //// mark min node as true; bcz we brought it into minspanning tree
        mst[u] = true;

        //// check its adjacent nodes
        for(auto& it:adj[u]){
            int v = it.first;
            int w = it.second;
            if(!mst[v] && w < key[v]){ //if we haven't already included it in min spanning tree then process weight of edge to it.
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair< int, int>, int> > ans;

    for(int i=2; i<=n; i++){
        ans.push_back({{parent[i], i}, key[i]});
    }
    
    return ans;
}
/* What does prism do is that it takes the mini edge and form MST and successively do this thing with
    other remaining edges, i.e. choose minimum edge and include it into MST and minEdge to be connected 
    to the already formed MST
*/