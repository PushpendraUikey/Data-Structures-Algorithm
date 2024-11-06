#include<bits/stdc++.h>
using namespace std;

//// bridge in a graph is an edge removing which breaks the graph in two components
//// more precisely make it disconnected


/// low[] is used to keep track of lowest time in which a node is seen from root
/// but there is a catch in it and that is we update it as soon as we get the cycle 
/// and keep updating the all nodes of that cyle by low seen time of any node from 
/// that cycle, which prevents the condition we are applying here to detect the bridge edge
/// low of neighbour if more than it's dicovery time then there is only one way to reach 
/// there and it is a bridge edge

void dfs(int node, int parent, int&timer, vector<int>&disc, vector<int>&low,
    vector<vector<int> >& result, unordered_map<int, list<int> >&adj, 
    unordered_map<int, bool>& vis){

        vis[node] = true;
        disc[node] = low[node] = timer++;

        for(auto &nbr:adj[node]){
            if(!vis[nbr]){
                dfs(nbr, node, timer, disc, low, result, adj, vis);
                low[node] = min(low[node], low[nbr]);

                //// check if bridge edge is present
                /*The concept is based on the trick that if lowest seen time of neighbour is more than current
                node's discovery time then there is only one way to reach the neighbour and that is from current 
                edge and if it is removed then two components(bridge) hence condition will detect bridge effectively
                and also see that it is after dfs call*/
                if(low[nbr] > disc[node]){
                    vector<int> ans;
                    ans.push_back(node);
                    ans.push_back(nbr);
                    result.push_back(ans);
                }
            }else if(nbr != parent){    /*This condition will hold if we loop back in cycle*/
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {

    //// adj list preparation
    unordered_map<int, list<int>> adj;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v,-1);
    vector<int> low(v, -1);
    int parent = -1;
    unordered_map<int, bool> vis;

    // for(int i=0; i<v; i++){
    //     disc[i] = -1;
    //     low[i] = -1;
    // }

    vector<vector<int> > result;

    /// dfs
    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(i, parent, timer, disc, low, result, adj, vis);
        }
    }

    return result;

}