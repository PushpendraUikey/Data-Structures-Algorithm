#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int i=0;
    int curlen=1, globlen=1;

    for(i=1; i<s.length(); i++){
        if(s[i] == s[i-1]){
            curlen++;
            globlen = max(curlen, globlen);
        }else{
            curlen = 1;
        }
    }

    cout << globlen << "\n";

}