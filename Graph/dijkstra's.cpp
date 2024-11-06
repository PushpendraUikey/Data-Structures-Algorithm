#include <bits/stdc++.h> 
using namespace std;

//// following is the dijkstra's algorithm to find the shortest path from a given node to
// all the other nodes-> It is for undirected weighted graph(+ve weight)


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // create ajdacency list

    unordered_map<int, list< pair<int, int> > > adj;
    for(int i=0 ;i< edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        pair<int, int> p1 = { u, w };
        pair<int, int> p2 = { v, w };
        adj[u].push_back(p2);
        adj[v].push_back(p1);
    }
    
    /// dist vector
    vector<int> dist(vertices, INT_MAX);
    // for(int i=0; i<vertices; i++){
    //     dist[i] = INT_MAX;
    // }
/// set to process mini weighted node first(no need for custom comparator as it will take st.first to compare)
    set<pair<int, int> > st;    

    dist[source] = 0;

    st.insert({0, source});

    while(!st.empty()){
        pair<int, int> top = *(st.begin());

        int nodedist = top.first;
        int node = top.second;

        st.erase(st.begin());   // removing the top element

        /// traverse on neighbour
        for(auto & nbr : adj[node]){  // nbr is pair of {neighbour, weight}
            if(nbr.second+nodedist < dist[nbr.first]){
                auto record = st.find({dist[nbr.first], nbr.first});

                //// if record found then remove that
                if(record != st.end()){ // becz we want to upload updated record otherwise there is a possiblity of double swap
                    st.erase(record);
                }

                //// distance update
                dist[nbr.first] = nbr.second + nodedist;

                //// record push in set
                st.insert({dist[nbr.first], nbr.first});
            }
        }
    }
    return dist;
}
/* This algorithm will work even if there is a loop as once a shortest path to node is determined it 
    won't be processed again as it won't pass the if condition if it is already finalized
    This is clear bruh.
*/