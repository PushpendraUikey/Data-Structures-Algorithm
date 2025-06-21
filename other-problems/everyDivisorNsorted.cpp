#include <bits/stdc++.h>
using namespace std;

/*
int main(){
    int n; cin >> n;
    vector<int> fir, sec;
    for(int i=1; i*i<=n ; i++){
        if(n%i == 0){
            fir.push_back(i);
            if(i!=n/i)
            sec.push_back(n/i);
        }
    }
    fir.insert(fir.end(), sec.rbegin(), sec.rend());
    for(auto& e:fir){
        std::cout << e << ' ';
    }
    std::cout << endl;
}
*/

// Better alternative to above is:
int main(){
    int n; cin >> n;
    int i;
    for(i=1; i*i < n; i++){
        if(n%i==0) cout << i << ' ';
    }
    for( ; i>=1; i--){
        if(n%(n/i) == 0) cout << n/i << ' ';
    }
    cout << endl;
}