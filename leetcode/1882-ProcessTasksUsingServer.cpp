#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        vector<int> ans(m);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> freeServers;
        priority_queue<pair<long long,pair<int,int>>, vector<pair<long long,pair<int,int>>>, greater<pair<long long,pair<int,int>>>> busyservers;
        
        for(int i=0; i<n; i++) {
            freeServers.emplace(servers[i], i);
        }

        long long currtime = 0;
        int currtask = 0;
        while (currtask < m) {
            currtime = max(currtime, (long long)currtask);
            while(!busyservers.empty() && busyservers.top().first <= currtime) {
                freeServers.emplace(busyservers.top().second);
                busyservers.pop();
            }
            if(freeServers.empty()) {
                currtime = busyservers.top().first;
                while(!busyservers.empty() && busyservers.top().first <= currtime) {
                    freeServers.emplace(busyservers.top().second);
                    busyservers.pop();
                }
            }
            ans[currtask] = freeServers.top().second;
            busyservers.emplace(currtime + tasks[currtask], freeServers.top());
            freeServers.pop();
            currtask++;
        }
        return ans;
    }
};