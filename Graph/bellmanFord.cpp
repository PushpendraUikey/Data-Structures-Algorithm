#include<bits/stdc++.h>
using namespace std;

//// The algorithm is used to find the shortest path in negative weighted graphs
//// shortest path can't be find out using this if neg cycle exists

///// DAG
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n+1, 1e8);
    dist[src] = 0;  /* basic starting condition */

    //// check n-1 times on each the dist if it can be updated
    for(int i=1; i<n; i++){
        /// traverse on edge list
        for(int j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != 1e8 &&(dist[u]+wt < dist[v])){
                dist[v] = dist[u]+wt;       /// update the dist to reach v
            }
        }
    }

    return dist;
    
    // check for negative cycle[nth time check ]
    bool flag = false;

    for(int j=0; j<m; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] != 1e8 && (dist[u] + wt < dist[v] )){
            flag = true;
        }
    }
}