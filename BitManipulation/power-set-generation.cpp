#include <bits/stdc++.h>
using namespace std;

// We're generating all the subsets of the given character in the given string.

void powerset(string &s){
    int n = s.length();

    int bsize = (1<<n);

    for(int i=0; i<bsize; i++){
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                cout << s[j];
            }
        }
        cout << endl;
    }
    return;
}

int main(){
    string s;
    cout << "Give the string whose power set you want: ";
    cin >> s;
    powerset(s);
}