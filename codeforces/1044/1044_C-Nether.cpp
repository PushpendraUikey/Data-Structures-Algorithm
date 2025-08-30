#include <bits/stdc++.h>
using namespace std;

int read_int() {
    int x;
    if (!(cin >> x)) {
        // interactive judge closed or error
        exit(0);
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    if (!(cin >> tt)) return 0;
    while (tt--) {
        int n; cin >> n;

        // helper to do a query: S (vector of ints), start x
        auto query = [&](const vector<int>& S, int x)->int {
            // print query
            cout << "? " << ' ' << x << ' ' << (int)S.size();
            for (int v : S) cout << ' ' << v;
            cout << "\n";

            cout.flush();
            int ans = read_int();
            if (ans == -1) exit(0); // protocol error / judge indicates failure
            return ans;
        };

        // 1) get len[v] for all v by querying full set {1..n} with start v
        vector<int> all;
        all.reserve(n);
        for (int i = 1; i <= n; ++i) all.push_back(i);

        // The longest path from each location
        vector<int> len(n+1);
        for (int v = 1; v <= n; ++v) {
            len[v] = query(all, v);
        }

        // 2) pick a start vertex with maximum len
        int start = 1;
        for (int v = 1; v <= n; ++v)
            if (len[v] > len[start]) start = v;

        int maxlen = len[start];
        vector<int> path;
        path.push_back(start);
        int cur = start;

        // Precompute nodes grouped by len value
        int maxL = max(maxlen, 0);
        vector<vector<int>> byLen(maxL+1);
        for (int v = 1; v <= n; ++v) if (len[v] >= 1 && len[v] <= maxL) byLen[len[v]].push_back(v);

        // 3) reconstruct path by descending length
        for (int want = maxlen; want >= 2; --want) {
            // candidates are nodes with len == want-1
            vector<int> candidates = byLen[want-1];
            // remove cur from candidates if present (usually isn't)
            vector<int> tmp;
            tmp.reserve(candidates.size());
            for (int x : candidates) if (x != cur) tmp.push_back(x);
            candidates.swap(tmp);

            // find one candidate reachable from cur using binary search on subset
            while (candidates.size() > 1) {
                int m = candidates.size();
                int half = m/2;
                // choose the smaller half to query (editorial trick)
                int leftSize = half;
                int rightSize = m - half;
                int queryLeft = (leftSize <= rightSize) ? 1 : 0;
                int take = queryLeft ? leftSize : rightSize;

                vector<int> S;
                S.reserve(take + 1);
                for (int i = 0; i < take; ++i) S.push_back(candidates[i + (queryLeft ? 0 : leftSize)]);
                // ensure cur present in S
                bool hasCur = false;
                for (int v : S) if (v == cur) { hasCur = true; break; }
                if (!hasCur) S.push_back(cur);

                int ans = query(S, cur);
                if (ans > 1) {
                    // candidate is inside the tested half -> keep that half
                    if (queryLeft) {
                        candidates.erase(candidates.begin() + leftSize, candidates.end()); // keep first leftSize
                    } else {
                        candidates.erase(candidates.begin(), candidates.begin() + leftSize); // keep last rightSize
                    }
                } else {
                    // candidate is in the other half -> keep the other half
                    if (queryLeft) {
                        candidates.erase(candidates.begin(), candidates.begin() + leftSize); // keep second half
                    } else {
                        candidates.erase(candidates.begin() + leftSize, candidates.end()); // keep first half
                    }
                }
            }

            if (candidates.empty()) {
                // No candidate found (shouldn't happen on valid data), break
                break;
            }
            int nxt = candidates[0];
            path.push_back(nxt);
            cur = nxt;
        }

        // 4) output the path
        cout << "! " << path.size();
        for (int v : path) cout << ' ' << v;
        cout << '\n';
        cout.flush();

        // read judge verdict for this test case if any (some interactive problems expect no reply)
        // Continue to next test case
    }
    return 0;
}


// Second solution
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt, n, i, poss, maxp, maxs, path, u, v, pt, j;
    cin >> tt;

    while(tt-->0){
        cin >> n;
        maxp = 0;
        maxs = 1;

        vector<ll> adj;
        ll lp[n+1];
        for(i=1; i<=n; i++){
            cout << "? " << i << ' ' << n << ' ';
            for(j=1; j<=n; j++){
                cout << j << ' ';
            }
            cout << "\n";
            cout.flush();
            cin >> path;

            lp[i] = path;
            if(path > maxp){
                maxp = path;
                maxs = i;
            }
        }
        adj.push_back(maxs);
        maxp--;
        i = 1;
        while(maxp && i<=n){
            for( ; i<=n ; i++) if(lp[i] == maxp){
                u = i;
                break;
            }
            cout << "? " << maxs << " 2 " << u << " " << maxs;
            cout << "\n";
            cout.flush();
            cin >> v;
            i++;
            if(v == 2){
                adj.push_back(u);
                maxs = u;
                maxp--;
                i = 1;
            }
        }
        cout << "! " << adj.size() << ' ';
        for(i=0; i<(int)adj.size(); i++){
            cout << adj[i] << ' ';
        }
        cout << "\n";
        cout.flush();
    }
}