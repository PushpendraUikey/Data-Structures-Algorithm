#include <bits/stdc++.h>
using namespace std;

// Load balancing is a NP-Hard problem and we're trying to find approximate solution closest to optimal
/// @brief  The algorithm makes one pass through the jobs in any order; when it comes to job j, it assigns
/// j to the machine whose load is smallest so far
/// @param jobs n jobs: < ith job, time it takes>
/// @param machines m machines in which we've to balance load
void greedy_balance(std::vector<std::pair<int,int>>& jobs, int machines){
    int m, n, i;
    std::pair<int,int> curr;
    m = machines;
    n = jobs.size();
    std::priority_queue<std::pair<int,int>, vector<std::pair<int,int>>, greater<std::pair<int,int>>> loads;
    std::vector<std::list<std::pair<int, int>>> machine_job(m); // contains jobs scheduled to job 'm'
    int maxi = INT_MIN;

    for(i=0; i<m; i++){
        loads.push({jobs[i].second, i});
        maxi = max(maxi, jobs[i].second);
        machine_job[i].push_back(jobs[i]);
    }
    for(; i<n ; i++){
        curr = loads.top();
        loads.pop();
        curr.first += jobs[i].second;   // adding new load
        loads.push(curr);

        maxi = max(maxi, curr.first);
        machine_job[curr.second].push_back(jobs[i]);
    }
    std::cout << "Maximum load to the server is: " << maxi << " \n";
}