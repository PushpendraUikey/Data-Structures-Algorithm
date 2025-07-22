#include <bits/stdc++.h>
/*
You are given an array of intervals, where intervals[i] = [start(i), end(i)] and each start(i) is unique.

The smart interval for an interval ‘i’ is an interval ‘j’ such that start(j) is greater than or equal to 
end(i) and start(j) should be minimum. Your task is to return an array of smart interval indices for each 
interval. If no smart interval exists for an interval ‘i’, then place -1 at index ‘i’ in the output array.
*/
vector<int> smartInterval(vector<vector<int>> &intervals, int n)
{
	// Write your code here.
    vector<int> ans(n,-1);

    for(int i=0;i < n; i++){
        int curs = intervals[i][0];
        int cure = intervals[i][1];

        int idx=-1;
        int ministart = INT_MAX;
        for(int j=0; j<n; j++){
            int s = intervals[j][0];
            int e = intervals[j][1];
            if(s >= cure){
                if(ministart > s){
                    ministart = s;
                    idx = j;
                }
            }
        }
        ans[i] = idx;
    }
    return ans;
}

// binary search approach
vector<int> smartInterval(vector<vector<int>> &intervals, int n) {
    vector<int> ans(n, -1);

    // Step 1: Store (start, original index)
    vector<pair<int, int>> sortedStarts;
    for(int i = 0; i < n; i++) {
        sortedStarts.push_back({intervals[i][0], i});
    }

    // Step 2: Sort by start time
    sort(sortedStarts.begin(), sortedStarts.end());

    // Step 3: For each interval, binary search for smallest start ≥ end
    for(int i = 0; i < n; i++) {
        int endTime = intervals[i][1];
        int low = 0, high = n - 1;
        int idx = -1;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(sortedStarts[mid].first >= endTime) {
                idx = sortedStarts[mid].second;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        ans[i] = idx;
    }

    return ans;
}
