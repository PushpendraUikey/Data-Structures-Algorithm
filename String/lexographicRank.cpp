#include <bits/stdc++.h>
using namespace std;

/*
You are given a string S of lowercase characters, find the rank of the string amongst its permutations 
when sorted lexicographically. Return 0 if the characters are repeated in the string.
Note: Return the rank%1000000007 as the answer as rank might overflow.
*/

#define mod 1000000007
class Solution {
    long long int fact[27];
    void computefact(){
        fact[0]=1LL;
        for(int i=1; i<=26; i++){
            fact[i] = ((long long)i*fact[i-1])%mod;
        }
    }
  public:
    // Function to find lexicographic rank of a string.
    int findRank(string S) {
        int n = S.length();
        if(n>26) return 0;
        
        computefact();
        
        vector<int> cnt(26,0);
        
        for(int i=0; i<n; i++){
            if(++cnt[S[i]-'a'] > 1) return 0;
        }
        
        for(int i=1; i<26; i++){
            
            cnt[i] += cnt[i-1];
        }
        
        long long int ans = 1LL;
        
        for(int i=0; i<n ; i++){
            int idx = S[i]-'a';
            for(int j=idx; j<26; j++){
                cnt[j]--;
            }
            ans =  (ans + (cnt[idx] * fact[n-i-1])%mod)%mod;
        }
        
        return ans;
    }
};