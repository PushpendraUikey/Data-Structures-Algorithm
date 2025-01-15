#include <bits/stdc++.h>

//it finds all shortest paths between the nodes in a single run.

void _shortestPath(std::vector<std::tuple<int, int, int>>&edges, int n){
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n,0)), dist(n, std::vector<int>(n,0));
    for(auto& tup:edges){
        int a, b, w;
        std::tie(a,b,w) = tup;
        matrix[a][b] = w;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else if (matrix[i][j]) dist[i][j] = matrix[i][j];   // if ther's a direct edge bw i&j
            else dist[i][j] = 1e9;  // no direct edge bw i&j
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = std::min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}
// after run dist matrix will have shortest distance between any two nodes in the graph
// Time compelxity is O(n^3)