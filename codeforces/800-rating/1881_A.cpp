#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
void solve() {
    cin >> n >> m;
    string x, s;
    vector<int> first(26,0), second(26,0);
    cin >> x >> s;
    
    for(int i=0; i<n; i++){
        first[x[i]-'a']++;
    }
    for(int i=0; i<n; i++){
        second[s[i]-'a']++;
    }
    for(int i=0; i<26; i++){
        if(second[i] != 0 && first[i]==0){
            cout << -1 << "\n";
            return;
        }
    }
    if(m <= n){
        if(x.find(s) != string::npos){
            cout << 0 << "\n";
            return;
        }else if((x+x).find(s) != string::npos){
            cout << 1 << "\n";
            return;
        }else{
            cout << 0 << "\n";
            return;
        }
    }
    int opr = 0;
    while(n<=4*m){
        if(x.find(s) != string::npos){
            cout << opr << "\n";
            return;
        }
        opr++;
        x = x + x;
        n *= 2;
    }

    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
