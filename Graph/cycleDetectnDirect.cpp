#include<bits/stdc++.h>
using namespace std;

//// Following here is the solution to the problem where we have to detect "cycle in directed graph"

bool isCyclicDFS(int node, unordered_map<int, list<int>>&adj, unordered_map<int, bool>&visited,
    unordered_map<int, bool>&dfsVisit){

      visited[node] = true;
      dfsVisit[node] = true;    // we keep track of node where we already visited during dfs


      for(auto &i : adj[node]){
        if(!visited[i]){
          bool cycleDete = isCyclicDFS(i, adj, visited, dfsVisit);
          if(cycleDete) return true;
        }
        else if(dfsVisit[i]){   // visited and dfsvisited both holds means cycle, otherwise not visited.
          return true;
        }
      }

      dfsVisit[node] = false;   // this is kind of backTracking
      return false;             // cycle not found
    }

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

    unordered_map<int, list<int>> adj;

    /// Adjacency list creation
    for(auto &i : edges){
      adj[i.first].push_back(i.second); /// directed graph
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisit;
    for(int i=0; i<n; i++){
      if(!visited[i]){
        bool ans = isCyclicDFS(i,adj, visited, dfsVisit);
        if(ans) return 1;
      }
    }
    return 0;
}


/***********************************************************************************************************/

//// Following the Khan's algorithm of Topological sorting used to check if it has valid topSort or not 
//// because only DAG have valid topological sort and Cyclic DA wont have valid top sort

bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	unordered_map<int, list<int> > adj;

    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);    // DAG
    }

    /// find all indegrees
    vector<int> indegree(v);
    for(auto& i:adj){
        for(auto &j:i.second){
            indegree[j]++;    // increase the indegree of all the connected nodes from the current node
        }
    }

    //// push all the 0 indegree vertices in queue
    queue<int> q;
    for(int i=0;i<v; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

  // if it doesn't have cycle then it's topSort elements should be num of vertices
	// but if it has then wrong result produces i.e. some vertices gets count twice.
    int cnt = 0;	

    //// here comes the topological sorting
    while(!q.empty()){
        int frontN = q.front();
        q.pop();

        cnt++;	//// Here comes the logic we are using to detect cycle(counting vertices visited during top sort)

        for(auto & neigh : adj[frontN]){
            indegree[neigh]--;
            if(indegree[neigh] == 0){   //// if any vertices indegree becomes zero then push it into the queue
                q.push(neigh);
            }
        }
    }

    if(cnt == v) return false;
	return true;
}