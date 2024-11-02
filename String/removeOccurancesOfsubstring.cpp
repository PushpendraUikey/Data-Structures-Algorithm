#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to remove all the occurances of given string from the main string
*/
string removeOccurance(string s, string part){
    while(s.length() != 0  && s.find(part) < s.length()){
        s.erase(s.find(part), part.length());   // find the starting ind of part and then remove the part by giving size of part.
    }
    return s;
}

int main(){
    string s; cin >> s;
    string part; cin >> part;

    cout << removeOccurance(s, part) << endl;
}

// replace(s.begin(), s.end(), ' ', 'M');  How replace method work? 