#include<bits/stdc++.h>
using namespace std;

/*
tarzan's algorithm to find the SCC in graph
*/
/*
Implementation is similar to bridge finding but this time just 
as soon as we get the SCC we're pushing it into the ans
*/
class Solution
{

    void dfs(int u, vector<int>&disc, vector<int>&low, stack<int>& st,
    vector<bool>&inStack, vector<int> adj[], vector<vector<int>>& scc){
        static int t = 0;
        st.push(u);
        low[u] = disc[u] = ++t;
        inStack[u] = true;
    
        for(int &v: adj[u]){
            if(disc[v] == -1)   //// it hasn't discovered
            {
                dfs(v, disc, low, st, inStack, adj, scc);
                low[u] = min(low[u], low[v]);       //// update the lowest time corresp to the lowest time to any node in gp
            }   //// differentiate back-edge and cross-edge
            else if(inStack[v]){                //// back-edge case so we're taking discovery time of v
                low[u] = min(low[u], disc[v]);      
            }
        }
    
        if(low[u] == disc[u]){  //// if u is headNode of SCC
            vector<int> ans;
            while(st.top()!=u){
                ans.push_back(st.top());
                inStack[st.top()] = false;
                st.pop();
            }
            ans.push_back(u);
            inStack[u] = false;
            st.pop();
            sort(ans.begin(), ans.end());
            scc.push_back(ans);
        }
    }
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        vector<vector<int>> scc;
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> inStack(V, false);
        stack<int> st;
        for(int i=0; i<V; i++){
            if(disc[i] == -1){
                dfs(i, disc, low, st, inStack, adj, scc);
            }
        }

        sort(scc.begin(), scc.end());

        return scc;
    }
};