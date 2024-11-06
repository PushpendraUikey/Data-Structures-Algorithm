#include <bits/stdc++.h> 
using namespace std;

/// @brief  Following is the algorithm to find the shortest path from source node to destination node
/// @param v    No of vertices
/// @param e    No of edges
/// @param edges Edge list
/// @param src  Source node
/// @param dest Destination node
/// @return     shortest path length

/// Algorithm is based on logic the shortest path will mark the destination visited first and using the parent logic
/// we can acutally find out the path.

int shortestPath(int v, int e, vector<vector<int>> &edges, int src, int dest)
{
    //// create adjacency list
    unordered_map<int, list<int> > adj;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //// do bfs
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;

    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while(!q.empty()){
        int frontN = q.front();
        q.pop();

        for(auto& i:adj[frontN]){
            if(!visited[i]){
                q.push(i);
                parent[i] = frontN;
                visited[i] = true;
            }
        }
    }

    //// prepare shortest path
    vector<int> ans;

    int currNode = dest;
    ans.push_back(currNode);
    while(currNode != src){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(), ans.end());

    return ans.size()-1;
}