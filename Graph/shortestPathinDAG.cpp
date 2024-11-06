#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<pair<int, int> > > adj;

        void addEdge(int u, int v, int weight){
            pair<int, int> p = {v, weight};
            adj[u].push_back(p);        //// since DAG
        }

        void dfs(int e, unordered_map<int, bool>& visited, stack<int>& st){
            visited[e] = true;
            for(auto& i: adj[e]){
                if(!visited[i.first]){
                    dfs(i.first, visited, st);
                }
            }
            st.push(e);     //// contains element in topSort
        }

        //// shortest path from src
        void getShortestPath(vector<int>& dist, int src, stack<int>&s){
            dist[src] = 0;

            while(!s.empty()){
                int tp = s.top();
                s.pop();

                if(dist[tp] < INT_MAX){
                    for(auto& i : adj[tp]){
                        if(dist[tp] + i.second < dist[i.first]){/*If from a way distance is lesser then update with that distance.*/
                            dist[i.first] = dist[tp] + i.second;
                        }
                    }
                }
            }
        }

};

int main(){
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);
    // g.addEdge(0,1,5);

    //// topological sort
    unordered_map<int, bool> visited;
    stack<int> st;
    for(int i=0; i<6; i++){
        if(!visited[i]){
            g.dfs(i, visited, st);
        }
    }


    int src = 1;
    vector<int> dist(6);
    for(int i=0; i<6; i++){
        dist[i] = INT_MAX;
    }

    g.getShortestPath(dist, src, st);

    for(int i=0; i<6; i++){
        cout << dist[i] << ' ' ;
    }cout << endl;
}