#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, pos, neg, val;
void solve() {
    cin >> n;
    pos = 0;
    neg = 0;

    for(int i=0; i<n; i++){
        cin >> val;
        if(val > 0) pos++;
        else neg++;
    }

    if(pos>=neg){
        if(neg%2==0){
            cout << "0\n";
        }else{
            cout << "1\n";
        }
    }else{
        int rem = (neg-pos+1)/2;
        if((neg-rem)%2){
            cout << rem+1 << "\n";
        }else{
            cout << rem << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
