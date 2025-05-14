#include <bits/stdc++.h>
using namespace std;

// approach 1
int common(vector<int>&a, vector<int>&b){
    set<int> st;
    for(auto&x:a) st.insert(x);
    int count=0; 
    for(auto&y:b){
        if(st.count(y)){
            count++;
        }
    } 
    return count;
}

// approach 2
// Same above algorithm, just use unordered_set instead of set
// it becomes O(n) from O(nLog(n))

// approach 3
// sort the elements then in O(n), you can count the common elements
int common3(vector<int>&a, vector<int>&b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i=0,
        j=0,
        count=0;
    while(i<a.size()&&j<b.size()){
        if(a[i]==b[j]) {
            i++;
            j++;
            count++;
            continue;
        }
        else if(a[i] < b[j]){
            i++;
        }else{
            j++;
        }
    }
    return count;
}