#include <bits/stdc++.h>
using namespace std;

//You are given three arrays 'A', 'B' and 'C' of length 'N', 'M' and 'K' respectively. 
//All the three arrays are sorted in non-decreasing order. Your task is to find all such 
//elements which are present in all the three given arrays.

vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    vector<int> ans;
    std::set<int> st;
    int i=0,
        j=0,
        k=0;

    while(i<a.size() && j<b.size() && k<c.size()){
        if (a[i] == b[j] && b[j] == c[k]) {
            st.insert(a[i]);
            i++;
            j++;
            k++;
            continue;
        }
        if(a[i] < b[j]) i++;
        if(b[j] < a[i]) j++;
        if(a[i] < c[k]) i++;
        if(c[k] < a[i]) k++;
        if(b[j] < c[k]) j++;
        if(c[k] < b[j]) k++;
    }
    for(auto &s : st){
        ans.push_back(s);
    }
    return ans;
}