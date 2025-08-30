#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;
    cin >> tt;
    while(tt--){
        int n = 1; cin >> n;
        vector<int> vec(n);
        for(int i=0; i<n; i++) cin >> vec[i];
        long long oprn = 0;

        for(int i=1; i<n; i+=2){
            if(vec[i-1] > vec[i]){
                int diff = vec[i-1] - vec[i];
                oprn += diff;
                vec[i-1] -= diff;
            }
            if(i<n-1 && vec[i+1] > vec[i]){
                int diff = vec[i+1] - vec[i];
                oprn += diff;
                vec[i+1] -= diff;
            }

            if(i<n-1 && (vec[i-1] + vec[i+1] > vec[i])){
                int diff = vec[i+1] + vec[i-1] - vec[i];
                oprn += diff;
                vec[i+1] -= diff;
                vec[i+1] = max(vec[i+1], 0);
            }
        }

        cout << oprn << "\n";
    }
}