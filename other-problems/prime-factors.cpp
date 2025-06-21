#include <bits/stdc++.h>
using namespace std;

int powerofPrimeinN(int, int, vector<int>&);
// n > 0
vector<int> prime_factors(int n){
    vector<int> ans;
    if(n == 1){
        ans.push_back(1);
        return ans;
    }
    int v;
    if(n%2==0){
        v = powerofPrimeinN(n, 2, ans);
        n /= pow(2, v);
    }
    if(n%3==0){
        v = powerofPrimeinN(n, 3, ans);
        n /= pow(3,v);
    }

    int i;
    int N = n;
    for(i=5; i*i<=N; i+=6){
        if(n%i == 0){
            v = powerofPrimeinN(n, i, ans);
            n /= pow(i, v);
        }
        if(n%(i+2) == 0){
            v = powerofPrimeinN(n, i+2, ans);
            n /= pow(i+2, v);
        }
    }
    if(n>1) ans.push_back(n);

    return ans;
}

int powerofPrimeinN(int n, int k, vector<int>&ans){
    int r=0;
    while(n>0){
        if(n%k==0){
            r++;
            n /= k;
        }else{
            break;
        }
    }
    int c = r;
    while(r-->0){
        ans.push_back(k);
    }
    return c;
}

int main(){
    int n; cout << "give a number whose prime factors you want: ";
    cin >> n;

    vector<int> ans = prime_factors(n);
    for(auto& e: ans){
        cout << e << ' ';
    }
    cout << endl;
}