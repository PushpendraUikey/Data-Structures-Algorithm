#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--){
        int n, k; cin >> n >> k;
        string s;
        cin >> s;
        string temp=""; 
        for(int i=0; i<k ; i++) temp += "1";
        if(s.find(temp) != std::string::npos){
            cout << "NO\n";
            continue;
        }
        int val = 1;
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                ans[i] = val++;
            }
        }
        for(int i=0; i<n; i++){
            if(s[i] == '0') ans[i] = val++;
        }

        cout << "YES\n";
        for(int i=0; i<n; i++){
            cout << ans[i] << ' ';
        }
        cout << "\n";
    }
}