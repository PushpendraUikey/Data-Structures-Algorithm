#include <bits/stdc++.h> 
using namespace std;

//// DAG: Directed acyclic graph(No cycle)
/// Topological Sorting is linear ordering of vertices such that for every edge "u->v", 'u' always appears 
//// before v in the sorted vertices.


void topsort(int e, unordered_map<int, bool>& visited,
    stack<int>& s, unordered_map<int, list<int> >& adj){
     visited[e] = true;

     for(auto& neigh:adj[e]){
         if(!visited[neigh]){
             topsort(neigh,visited,s,adj);
         }
     }
     s.push(e);     //// while returning push the elements in stack to get top sort.
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // creating an adjacency list
    unordered_map<int, list<int>> adj;

    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);    /// directed graph
    }

    unordered_map<int, bool> visited;   // to keep track of visited nodes

    stack<int> s;   /// stack to contain ele in topological sorted order
    for(int i=0; i<v; i++){
        if(!visited[i]){    /// assuming 0 based vertices are there
            topsort(i, visited, s, adj);
        }
    }

    vector<int> ans;

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}