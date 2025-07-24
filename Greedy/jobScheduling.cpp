#include <bits/stdc++.h>
using namespace std;

/*
You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is 
associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one 
job can be scheduled at a time. You will earn the profit associated with a job only if it is 
completed by its deadline.

Your task is to find:
The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.
*/

// O(n2) solution for the scheduling problem
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int,int>> vec(n);
        for(int i=0; i<n; i++){
            vec[i] = {profit[i], deadline[i]};
        }
        sort(vec.begin(), vec.end(), [&](const pair<int,int>&a,const pair<int,int>&b){
            return a.first > b.first;
        });
        vector<bool> isfill(n, false);
        int job=0;
        int prfit = 0;
        
        for(int i=0; i<n; i++){
            for(int j = min(vec[i].second,n)-1; j>=0; j--){
                if(isfill[j] == false){
                    isfill[j] = true;
                    job++;
                    prfit += vec[i].first;
                    break;
                }
            }
        }
        return {job, prfit};
    }
};


// Optimized solution using DSU;
class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);  // Path compression
    }

    void merge(int u, int v) {
        parent[u] = v;
    }
};
// one more optimization can be done that is to use 'n' instead of maxdeadline it'll work
class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int,int>> jobs(n);
        int maxDeadline = 0;
        for(int i = 0; i < n; i++) {
            jobs[i] = {profit[i], deadline[i]};
            maxDeadline = max(maxDeadline, deadline[i]);
        }

        sort(jobs.begin(), jobs.end(), greater<>());

        DSU dsu(maxDeadline);
        int job = 0, prfit = 0;

        for(auto &[p, d] : jobs) {
            int availableSlot = dsu.find(min(d, maxDeadline));
            if(availableSlot > 0) {
                dsu.merge(availableSlot, dsu.find(availableSlot - 1));  // making the parent of availslot equal parent of availslot prevents reuse
                job++;
                prfit += p;
            }
        }
        return {job, prfit};
    }
};
