#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, x, y;
// int xcord[200001], ycord[200001];
ll xcnt, ycnt;
ll tmp;
void solve(){
    cin >> n >> m >> x >> y;
    
    xcnt=0;
    ycnt=0;
    tmp=0;
    for(int i=0; i<n; i++){
        cin >> tmp;
        if(tmp <= y) ycnt++;
    }
    for(int i=0; i<m; i++){
        cin >> tmp;
        if(tmp <= x) xcnt++;
    }

    cout << (xcnt+ycnt) << "\n";
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}