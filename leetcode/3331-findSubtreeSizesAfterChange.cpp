#include <bits/stdc++.h>
using namespace std;


class Solution {
    int find(const vector<int>& parent, const string& s, const char& c, int i) {
        if(i==-1) return -1;
        if(s[i] == c) return i;
        return find(parent, s, c, parent[i]);
    }
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> ans(n, 1);
        vector<int> pending(n, 0);
        vector<int> newparent = parent;
        queue<int> q;


        for(int i=1; i<n; i++) {
            int idx = find(newparent, s, s[i], newparent[i]);
            if(idx != -1) {
                parent[i] = idx;
            }
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