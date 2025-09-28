#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char target[10][10];
ll score = 0;
void solve() {

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> target[i][j];
            if(target[i][j] != '.'){
                if( i==0 || i==9 || j==0 || j==9 ){
                    score += 1;
                }
                else if(i==1 || i==8 || j==1 || j==8){
                    score += 2;
                }
                else if(i==2 || i==7 || j==2 || j==7){
                    score += 3;
                }
                else if(i==3 || i==6 || j==3 || j==6){
                    score += 4;
                }else{
                    score += 5;
                }
            }
        }
    }
    cout << score << '\n';
    score = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
