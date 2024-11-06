#include<bits/stdc++.h>
using namespace std;

//// Khan's algorithm to find the topological sort.
/* Toposort using indegree, it's slight variation can be used to all possible toposort of graph */
vector<int> topologicalSort(vector<vector<int> >& edges, int v, int e){
    // create adjacency list 
    unordered_map<int, list<int> > adj;

    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);    /// DAG
    }

    // find all indegrees
    vector<int> indegree(v);
    for(auto& i:adj){
        for(auto &j:i.second){  // increment the indegree of corresponding neighbour
            indegree[j]++;
        }
    }

    //// push all the 0 indegree vertices in queue
    queue<int> q;
    for(int i=0;i<v; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> ans;
    //// here comes the topological sorting
    while(!q.empty()){
        int frontN = q.front();
        q.pop();

        ans.push_back(frontN);

        for(auto & neigh : adj[frontN]){
            indegree[neigh]--;
            if(indegree[neigh] == 0){   //// if any vertices indegree becomes zero then push it into the queue
                q.push(neigh);
            }
        }
    }

    return ans;

}