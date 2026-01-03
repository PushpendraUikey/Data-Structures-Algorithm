#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int n, k;
string s;
void solve() {
    cin >> n >> k;
    cin >> s; 
    vector<char> count(26,0);
    for (char c : s) {
        count[c - 'a']++;
    }
    int odd = 0;
    int even = 0;
    for(int i=0; i<26; i++) {
        if( count[i]%2 != 0) {
            odd++;
        }else if( count[i] > 0){
            even++;
        }
    }
    //cout << odd << " " << k << "\n";
    if( odd > k ) {
        if( (k==0 && (odd == 0 || odd == 1)) || (odd-k) == 1 ){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }else{
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
