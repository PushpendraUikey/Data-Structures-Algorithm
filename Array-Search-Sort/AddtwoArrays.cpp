#include<bits/stdc++.h>
using namespace std;

//// following here is the algorithm to add two arrays


vector<int> addArr(int a[], int n, int b[], int m){
    int maxi = max(n, m);
    int carry = 0; int sum = -1;
    vector<int> ans;
    int k{n-1}, j{m-1};
    for(int i{0}; i<maxi; i++){
        cout << sum << endl;
        if(k < 0){
            sum = b[j] + carry;
            carry = sum/10;
            ans.push_back(sum%10);
            j--;
            continue;
        }
        if(j < 0){
            sum = a[k] + carry;
            carry = sum/10;
            ans.push_back(sum%10);
            k--;
            continue;
        }

        sum = a[k] + b[j] + carry;
        carry = sum/10;
        ans.push_back(sum%10);
        k--;
        j--;
    }
    while(carry){
        ans.push_back(carry%10);
        carry /= 10;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for(int i{0}; i< n; i++) cin >> a[i];
    for(int i{0}; i< m; i++) cin >> b[i];

    vector<int> ans = addArr(a, n, b , m);

    for(auto i:ans) cout << i << ' ';
    cout << endl;
}
/*
3
3 3 
4 5 1
3 4 5
4 1 
1 2 3 4
6
3 2
1 2 3
9 9
*/