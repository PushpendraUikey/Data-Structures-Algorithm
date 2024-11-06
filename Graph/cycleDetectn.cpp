#include<bits/stdc++.h>
using namespace std;

// Following here is the solution to the problem to find the cycle in Undirected Graph using BFS

bool isCyclicBFS(int src,unordered_map<int, bool>&visited,
    unordered_map<int, list<int> >&adj, unordered_map<int, int>&parent){

        parent[src] = -1;
        visited[src] = true;

        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int frontN = q.front();
            q.pop();

            for(auto& neig: adj[frontN]){
                if(visited[neig] && neig != parent[frontN]){    /// if any node is already visited and is not the parent then cycle
                    return true;
                }
                if(!visited[neig]){
                    q.push(neig);
                    visited[neig] = true;
                    parent[neig] = frontN;

                }
            }
        }
        //// cycle wasn't present
        return false;
    }

/// Given algorithm detects a cycle in undirected graph using DFS

bool isCyclicDFS(int node, int parent,unordered_map<int, bool>&visited,
unordered_map<int, list<int> >&adj){

    visited[node] = true;
    for(auto& neig : adj[node]){
        if(!visited[neig]){
            bool cycleDetect = isCyclicDFS(neig, node, visited, adj);
            if(cycleDetect){
                return true;
            }
        }

        else if( neig != parent){   /// found a neighbour visited which is parent then cycle
            return true;
        }
    }

    /// cycle wasn't found
    
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // create adjacency list;
    unordered_map<int, list<int> > adj;

    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //// to handle disconnected components
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = isCyclicBFS(i, visited, adj, parent);
            // bool ans = isCyclicDFS(i, -1, visited, adj);
            if(ans) return "Yes";
        }
    }
    return "No";
}