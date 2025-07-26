#include <bits/stdc++.h>
using namespace std;

// Naive pattern matching algorithm runs in O(n-m+1)*m: Sliding window technique
void naivePatternMatch(const string& str, const string& pat){
    int n = str.length();
    int m = pat.length();
    if(m > n) return;

    for(int i=0; i<= n-m; i++){
        int j=0;
        for( ; j<m; j++){
            if(pat[j] != str[i+j]){
                break;
            }
        }
        if(j==m) cout << "Pattern found at index: " << i << endl;
    }
}

// Slight optimization to work in O(n) iff the character in the pattern are distinct
void naivePatternMatch_1(const string& str, const string& pat){
    int n = str.length();
    int m = pat.length();
    if(m>n) return;
    
    for(int i=0; i<=n-m; i++){
        int j=0;
        for( ; j<m ;j++){
            if(pat[j] != str[i+j]) break;
        }
        if(j==m) cout << "Pattern found at index: " << i << endl;
        if(j==0) i++;
        else i = i+j;
    }
}