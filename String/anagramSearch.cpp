#include <bits/stdc++.h>
using namespace std;

// Given a string txt and a pattern pat, check if any permutation of pat is present in txt or not
// This permutatio is also called anagram
// Note: All strings a lower case words

// Naive solution 
bool anagram(const string&pat, const string& txt, int j){
    vector<int> count(26,0);
    for(int i=0; i<pat.length(); i++){
        count[pat[i]-'a']++;
        count[txt[j+i]-'a']--;
    }
    for(int i=0; i<26; i++){
        if(count[i] != 0) return false;
    }
    return true;
}
bool ispresent(const string&txt, const string&pat){
    int n = txt.length();
    int m = pat.length();
    for(int i=0; i<=(n-m); i++){
        if(anagram(pat, txt, i)) return true;
    }

    return false;
}

// Here is more efficient implementation: Sliding Window Technique
bool isSame(const vector<int>&first, const vector<int>&second){
    for(int i=0; i<first.size(); i++){
        if(first[i] != second[i]) return false;
    }
    return true;
}
bool ispresent_eff(const string&txt, const string&pat){
    int n = txt.length();
    int m = pat.length();
    vector<int> patcnt(26,0), txtcnt(26,0);
    for(int i=0; i<m ; i++){
        patcnt[(pat[i]-'a')]++;
        txtcnt[(txt[i]-'a')]++;
    }

    // sliding window 
    for(int i=m; i<n; i++){
        if(isSame(patcnt, txtcnt)) return true;
        txtcnt[(txt[i-m]-'a')]--;
        txtcnt[(txt[i]-'a')]++;
    }
    return isSame(patcnt, txtcnt);
}