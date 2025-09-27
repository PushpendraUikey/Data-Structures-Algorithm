#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n; 
string x;

bool findout(string&x){
    int n = x.length();
    int i=0;

    while(i<n){
        int b = i;
        while(i<n && x[i]=='.') i++;

        if(i-b > 2){
            return true;
        }
        i++;
    }

    return false;
}
void solve() {

    cin >> n >> x;
    
    int count=0;
    int i=0;

    if(findout(x)) {
        cout << 2 << '\n';
        return;
    }
    while(i<n){
        int b = i;
        while(i<n && x[i]=='.') i++;
        count += (i-b);
        i++;
    }

    cout << count << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
