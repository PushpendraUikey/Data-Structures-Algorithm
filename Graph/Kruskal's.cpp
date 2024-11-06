#include<bits/stdc++.h>
using namespace std;

//// Algorightm to find the minimum spanning tree 
/* 
Algorithm uses rank and path compression simultanously 
*/

bool comp(vector<int>& a, vector<int> &b){  //// custom comparator
  return a[2]<b[2];
}

///// Union by rank and path compression
void makeSet(vector<int>& parent, vector<int>& rank, int n){
    for(int i=0; i<n; i++){
        parent[i] = i;  // set every node's parent as itself and then proceed.
        rank[i] = 0;
    }
}

//// This also simplifies the logic of whether the two nodes belong to the same component or not.

int findParent(vector<int>& parent, int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findParent(parent, parent[node]); 
    // this does the job of returning parent as well as tree compression
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank){
    u = findParent(parent, u);
    v = findParent(parent, v);

    //// whosoever's rank is more make it parent
    //// and increment the rank

    if(rank[u] < rank[v]){
        parent[u] = v;
        rank[v]++;
    }else if(rank[u] > rank[v]){
        parent[v] = u;
        rank[u]++;
    }else{
      //// if same rank then can anyone randomly
        parent[v] = u;
        rank[u]++;
    }
}


 //// convert into MSP and return the weight of weight of min Spanning tree

int minimumSpanningTree(vector<vector<int>>& edges, int n) 
{
  sort(edges.begin(), edges.end(), comp); // sort edges according to weights first

  vector<int> parent(n);
  vector<int> rank(n);
  makeSet(parent, rank, n);

  int minWeight = 0;

  for(int i=0; i<edges.size(); i++){
    int u = findParent(parent, edges[i][0]);
    int v = findParent(parent, edges[i][1]);
    int wt = edges[i][2];

    if(u!=v){ // if they are not connected according to our minimum edge connectivity then connect them and 
      minWeight += wt;
      unionSet(u, v, parent,rank);
    }
  }

  return minWeight;
}