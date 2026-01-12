#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

// Swap and Delete
// https://codeforces.com/contest/1913/problem/B


void solve() {
    string s;
    cin >> s;
    int cnt0=0, cnt1=0;
    for(int i=0;i<s.length(); i++){
        if(s[i]=='0') cnt0++;
        else cnt1++;
    }
    string t="";

    int swapped = min(cnt1, cnt0);
    cnt1=0;
    cnt0=0;
    int cost = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '0'){
            cnt0++;
            if(cnt0>swapped){
                t = t+"0";
            }else{
                t = t+"1";
            }

        }else{
            cnt1++;
            if(cnt1>swapped){
                t = t+"1";
            }else{
                t = t+"0";
            }
        }
    }

    int j = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[j] == t[i]){
            cost++;
        } else {
            j++;
        }
    }
    // cout << s << ' ' << t << '\n';
    cout << cost << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
