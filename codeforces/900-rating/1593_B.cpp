#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

// Make it divisible by 25
// https://codeforces.com/contest/1593/problem/B

ull n;

int cost(string num, string suff){
    if(suff.length() == 0) return 0;
    if(num.length() == 0) return -1;

    int n = num.length();
    int m = suff.length();

    if(num[n-1] == suff[m-1]){
        num.pop_back();
        suff.pop_back();
        int ans = cost(num, suff);
        return ans;
    }
    else{
        num.pop_back();
        int ans = cost(num, suff);
        if(ans!= -1) return ans + 1;
        return ans;
    }
}
void solve() {
    cin >> n;
    if((n%1000)%25==0){
        cout << "0\n";
        return;
    }
    string s = to_string(n);
    int mincst = INT_MAX;
    int cst1 = cost(s, "00");
    int cst2 = cost(s, "50");
    int cst3 = cost(s, "25");
    int cst4 = cost(s, "75");

    if(cst1 != -1) mincst = min(mincst, cst1);
    if(cst2 != -1) mincst = min(mincst, cst2);
    if(cst3 != -1) mincst = min(mincst, cst3);
    if(cst4 != -1) mincst = min(mincst, cst4);

    cout << mincst << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
