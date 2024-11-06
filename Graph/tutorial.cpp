#include<bits/stdc++.h>
using namespace std;

/*
Implementation of graph and algorithms over it
*/

class graph{
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int& u, int& v, bool directed){
        /// atleast u->v edge to bnna hi hai thus
        adj[u].push_back(v);

        /// if it is a undirected graph
        if(!directed){
            adj[v].push_back(u);
        }
    }

    void printgraph(){
        for(auto &e:adj){
            cout << e.first << " --> " ;
            for(auto &v:e.second){
                cout << v << ' ' ;
            }
            cout << "\n";
        }
    }
};

int main(){
    int n;
    cout << "Enter the number of nodes? " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges? " << endl;
    cin >> m;

    graph g;

    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        // creating an undirected graph for now
        g.addEdge(u,v,false);
    }

    g.printgraph();
}