#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while(tt--) {
        int n; 
        cin >> n;
        vector<int> adj[n+1];
        for(int i=1,u,v; i<n; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(n+1), parent(n+1);

        function<void(int,int)> dfs = [&](int u, int p){
            parent[u] = p;
            for(int v:adj[u]){
                if(v != p){
                    dist[v] = dist[u] + 1;
                    dfs(v,u);
                }
            }
        };

        // First DFS from node 1
        dist[1] = 0;
        dfs(1,-1);
        int x = max_element(dist.begin(), dist.end()) - dist.begin();

        // Second DFS from farthest node x
        dist[x] = 0;
        dfs(x,-1);
        int y = max_element(dist.begin(), dist.end()) - dist.begin();

        if(dist[y] == n-1){
            cout << -1 << "\n"; 
            continue;
        }

        // Mark diameter path
        vector<int> on_diameter(n+1,0);
        int cur = y;
        while(cur != -1){
            on_diameter[cur] = 1;
            cur = parent[cur];
        }

        int a=-1,b=-1,c=-1;
        for(int u=1; u<=n; u++){
            for(int v:adj[u]){
                if(on_diameter[u] && !on_diameter[v]){
                    a = parent[u];
                    b = u;
                    c = v;
                    break;
                }
            }
            if(a!=-1) break;
        }
        cout << a << " " << b << " " << c << "\n";
    }
}
