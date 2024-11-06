#include<bits/stdc++.h>
using namespace std;

// articulation points are those nodes removing which the graph breaks down into two components
/*
Implementation is same as bridge finding with root handled differently 
*/

void dfs(int node, int parent, int&timer, vector<int>&disc, vector<int>&low,
    vector<int>& result, unordered_map<int, list<int> >&adj, 
    unordered_map<int, bool>& vis){

        vis[node] = true;
        disc[node] = low[node] = timer++;
        int child = 0;

        for(auto &nbr:adj[node]){
            if(!vis[nbr]){
                dfs(nbr, node, timer, disc, low, result, adj, vis);
                low[node] = min(low[node], low[nbr]);

                //// check if bridge edge is present
                if(low[nbr] >= disc[node] && parent != -1){ //(same as bridges with slight modification) if there 
                                                            // is only one way to go the neigbr and not from parent node then that node is AP
                    result.push_back(node);
                }
            }else if(nbr != parent){                //// same logic as that of bridges
                low[node] = min(low[node], disc[nbr]);
            }
            child++;
        }

        if(parent == -1 && child>1){    //// root node handled differently 
            result.push_back(node);
        }
    }
vector<int> findArticulationPoints(vector<vector<int>> &edges, int v, int e) {

    //// adj list preparation
    unordered_map<int, list<int>> adj;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    unordered_map<int, bool> vis;

    // for(int i=0; i<v; i++){
    //     disc[i] = -1;
    //     low[i] = -1;
    // }

    vector<int> result;

    /// dfs
    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(i, parent, timer, disc, low, result, adj, vis);
        }
    }
    return result;
}