#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, x;
int arr[200001];

void solve(){
    cin >> n;
    int zeros = 0;

    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i] == 0) zeros++;
    }

    int firstel = 1;
    while(firstel<=n){
        if(firstel == arr[firstel-1]) firstel++;
        else if(arr[firstel-1] == 0 && zeros==1){
            bool found = false;
            for(int i=firstel; i<n; i++){
                if(arr[i] == firstel) found = true;
            }
            if(found) break;
            else firstel++;
        }
        else{
            break;
        }
    }
    int lastel = n;
    while(lastel>0){
        if(lastel == arr[lastel-1])  lastel--;
        else if(arr[lastel-1] == 0 && zeros == 1){
            bool found = false;
            for(int i=lastel-1; i>=0; i--){
                if(arr[i] == lastel) found = true;
            }
            if(found) break;
            else lastel--;
        }
        else{
            break;
        }
    }
    if(firstel == n+1 || lastel == 0){
        cout << 0 << "\n";
    }else{
        cout << lastel - firstel + 1 << "\n";
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}