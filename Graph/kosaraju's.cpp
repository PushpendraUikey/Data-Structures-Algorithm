#include<bits/stdc++.h>
using namespace std;

//// algorithm to find the Strongly connected component
//// any component is SCC if from the given node we can visit all the nodes in that component
//// the single node itself are strongly connected components if they are not part of any other SCC

//// there are cycles in graph still we're doing toposort.
//// we are keeping the element based on their departure time.


void TopoSort(int node,unordered_map<int, bool>& vis, stack<int>& st,
	unordered_map<int, list<int>>& adj ){
		vis[node] = true;
		for(auto nbr:adj[node]){
			if(!vis[nbr]){
				TopoSort(nbr, vis, st, adj);
			}
		}
	st.push(node);	// deepest element in dfs call will be last and the root will be the top element
					// so after transposing the graph we'll again start calling revDFS starting root.
}


void revDfs(int node, unordered_map<int, bool>& vis, unordered_map<int, list<int>>& adj ){
	vis[node] = true;

	for(auto nbr: adj[node]){
		if(!vis[nbr]){
			revDfs(nbr, vis, adj);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	//// first of all you have to make an adjacency list
	unordered_map<int, list<int>> adj;

	for(int i=0; i<edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v); /// directed graph
	}

	//// topsort
	stack<int> st;
	unordered_map<int, bool> vis;
	for(int i=0; i<v; i++){
		if(!vis[i]){
			TopoSort(i, vis, st, adj);
		}
	}

	//// TransPose the edges(Reverse the dirn)
	unordered_map<int, list<int> > transpose;
	for(int i=0; i<v; i++){
		vis[i] = false;
		for(auto &nbr:adj[i]){
			transpose[nbr].push_back(i);
		}
	}

	//// DFS call using the stack element in the transposed 

	int cnt=0;
	while(!st.empty()){
		int v = st.top();
		st.pop();
		if(!vis[v]){
			cnt++;
			revDfs(v, vis, transpose);
		}
	}
	return cnt;
}