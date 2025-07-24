#include<bits/stdc++.h>


using ll = long long;
// Check if it's possible to buy all candies by day d
bool isPossible(int d,
                const unordered_map<int, vector<int>>& mp,
                const vector<int>& k_input) {
    ll coinIhave = 0;
    vector<ll> k(k_input.begin(), k_input.end());  // work with 64?bit copy

    // Simulate day by day
    for (int day = 1; day <= d; ++day) {
        coinIhave++;  // one new coin each morning

        auto it = mp.find(day);
        if (it != mp.end()) {
            // for each candy type on sale today
            for (int idx : it->second) {
                // buy as many of this type as you can at 1 coin each
                ll buy = min<ll>(k[idx], coinIhave);
                k[idx]   -= buy;
                coinIhave -= buy;
            }
        }
    }

    // Remaining candies must be bought at 2 coins each
    ll remCandy = accumulate(k.begin(), k.end(), 0LL);
    return coinIhave >= 2 * remCandy;
}

// Binary search the minimum day
int minimumDays(const vector<int>& days,
                const vector<int>& candies,
                const vector<int>& k, int n, int m) {

    // Build sale-map: day -> list of 0?based candy indices on sale
    unordered_map<int, vector<int>> mp;
    mp.reserve(m * 2);
    for (int i = 0; i < m; ++i) {
        // candies[i] is 1-based in input ? convert to 0-based here
        mp[ days[i] ].push_back(candies[i] - 1);
    }

    // total candies needed
    ll total = accumulate(k.begin(), k.end(), 0LL);
    int low  = total;
    int high = 2 * total;
    int ans  = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(mid, mp, k)) {
            ans   = mid;
            high  = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}



// Above solution doesnt work correctly for reason not known, below is the correct code 
// by someone else using DP
bool isPossible(vector<int>& days, vector<int>& candies, vector<int>& k, int n, int m, int currDay)

{
    vector<int> candiesLastSaleDay(n + 1, -1);
    for(int i = 0; i < m; i++)
    {
        if (days[i] <= currDay)  {
            candiesLastSaleDay[candies[i]] = max(candiesLastSaleDay[candies[i]], days[i]);
        }
    }
    vector<vector<int>> lastSaleDay(currDay +1);
    for(int i = 0; i < n; ++i) 
    {
        if (candiesLastSaleDay[i+1] != -1) 
        {
            lastSaleDay[candiesLastSaleDay[i+1]].push_back(i);
        }
    }
    vector<int> need = k;
    int currMoney = 0;
    for(int i = 1; i <= currDay; ++i) 
    {
        currMoney++;
        for(int j = 0; j < lastSaleDay[i].size(); j++) 
        {
            if (currMoney >= need[lastSaleDay[i][j]]) 
            {
                currMoney -= need[lastSaleDay[i][j]];
                need[lastSaleDay[i][j]] = 0;
            } 
            else 
            {
                need[lastSaleDay[i][j]] -= currMoney;
                currMoney = 0;
                break;
            }
        }
    }
    int totalCandies = 0;
    for(int i = 0; i < n; i++)
    {
        totalCandies += need[i];
    }
    return ((totalCandies * 2) <= currMoney);
}
int minimumDays(vector<int>& days, vector<int>& candies, vector<int>& k, int n, int m)
{
	int sumi = accumulate(k.begin(), k.end(), 0);   // total number of candies
    int high = sumi * 2;
    int low = sumi;
    int ans = 0;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(isPossible(days, candies, k, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}
