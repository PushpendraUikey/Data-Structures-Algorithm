#include <bits/stdc++.h>
using namespace std;

// LPS array construction

// Naive approach
int longPrefixSuffix(const string&str, int n){
    for(int len=n-1; len>0; len--){
        bool flag = true;
        for(int i=0; i<len; i++){
            if(str[i] != str[n-len+i]){
                flag = false;
                break;
            }
        }
        if(flag) return len;
    }
    return 0;
}
vector<int> LPS(const string&str){
    int n = str.length();
    vector<int> ans(n);
    for(int i=0; i<n ;i++){
        ans[i] = longPrefixSuffix(str, i+1);
    }
    return ans;
}


// Here is the efficient approach to compute LPS array : O(n)
void LPS(const string&str, vector<int>&lps){
    int n = str.length();
    int len=0;
    lps[0] = 0;
    int i=1;
    while( i < n ){
        if(str[i] == str[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len==0){
                lps[i] = 0;
                i++;
            }else{
                len = lps[len-1];
            }
        }
    }
}

void KMP(const string& str, const string&pat){
    int n = str.length();
    int m = pat.length();
    if(m > n) return;
    vector<int> lps(m,0);
    LPS(str, lps);

    int i=0, j = 0;

    while(i < n){
        if(str[i] == pat[j]) {
            i++;
            j++;
        }
        if(j==m) {
            cout << "Pattern match found at index: " << (i-j) << endl;
            j = lps[j-1];
        }
        else if(i<n && (pat[j] != str[i])){
            if(j==0) i++;
            else{
                j = lps[j-1];
            }
        }
    }
}

int main(){
    string str, pat;
    cout << "Give the input string: "; cin >> str;
    cout << "Give the pattern to be searched for: "; cin >> pat;
    KMP(str, pat);
}