#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pair<int,int>> events;
        vector<int> ans;
        vector<pair<int,int>> serverLogs;
        vector<int> serverCount(n+1,0);
        events.reserve(queries.size());
        ans.resize(queries.size());
        serverLogs.reserve(logs.size());
        
        for (int i=0; i<queries.size(); i++) {
            events.emplace_back(queries[i], i);
        }
        sort(events.begin(), events.end());

        for (const auto& log: logs) {
            serverLogs.emplace_back(log[1], log[0]);
        }
        sort(serverLogs.begin(), serverLogs.end());

        int left = 0;
        int right = 0;
        int activeServers = 0;

        for(const auto &[queryTime, queryIndex] : events) {
            while (right < serverLogs.size() && serverLogs[right].first <= queryTime){
                int serverId = serverLogs[right].second;
                if(serverCount[serverId] == 0){
                    activeServers++;
                }
                serverCount[serverId]++;
                right++;
            }
            while (left < right && serverLogs[left].first < queryTime - x) {
                int serverId = serverLogs[left].second;
                serverCount[serverId]--;
                if(serverCount[serverId] == 0) {
                    activeServers--;
                }
                left++;
            }

            ans[queryIndex]  = n - activeServers;
        }

        return ans;
    }
};
