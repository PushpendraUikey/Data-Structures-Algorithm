#include <bits/stdc++.h>
using namespace std;


class Solution {
    int find(const vector<int>& parent, const string& s, const char& c, int i) {
        if(i==-1) return -1;
        if(s[i] == c) return i;
        return find(parent, s, c, parent[i]);
    }
    void dfs(int node, vector<int>& parent, const string& s, unordered_map<int,vector<int>>& children, vector<int>&last) {
        int c = s[node]-'a';
        if( node != 0 && last[c] != -1) {
            parent[node] = last[c];
        }
        int saved = last[c];
        last[c] = node;
        for(int child: children[node]) {
            dfs(child, parent, s, children, last);
        }
        last[c] = saved;
    }
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> ans(n, 1);
        vector<int> pending(n, 0);
        queue<int> q;
        unordered_map<int, vector<int>> children;
        vector<int> last(26, -1);

        for(int i=1; i<n; i++) {
            children[parent[i]].push_back(i);
        }

        dfs(0, parent, s, children, last);
        
        for(int i=1; i<n; i++) {
            pending[parent[i]]++;
        }

        // Collecting the leaf.
        for (int i=1; i<n; i++) {
            if(pending[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(node == 0) continue; // root has nobody to report to
            int p = parent[node];
            ans[p] += ans[node];
            pending[p]--;
            if(pending[p] == 0){    // parent has no more pending children
                q.push(p);
            }
        }

        return ans;
    }
};