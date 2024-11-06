#include<bits/stdc++.h>
using namespace std;

/*
Here is the algorthitm to check if the graph is Bipartite or not
*/

class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    
		vector<int> color(V, -1);	/*To color the graph and also check if the graph is visited or not*/
	    
	    queue<int> q;	/* It will help in doing bfs traversal */
	    
	    for(int i=0; i<V; i++){     //// traverse all the nodes
	        if(color[i] == -1){     //// If not already visited then give it a base color
	            color[i] = 0;   
	            q.push(i);
	            
	            while(!q.empty()){
	                int frnt = q.front();
	                q.pop();
	                
	                for(auto& e:adj[frnt]){
	                    if(color[e]==-1){
	                        q.push(e);
	                        color[e] = 1 - color[frnt];     //// assign opposite to parent color
	                    }else if(color[frnt] == color[e]){  //// same level have edge bw them in bfs, means we can't bipartite the graph.
	                        return false;
	                    }
	                }
	            }
	        }
	    }
	    
	    return true;    /// Yes it is bipartite if we're able to color the graph according to their level alternatively then it holds.
	}

};