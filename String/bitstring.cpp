#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement

You are given a binary string s consisting of characters '0' and '1'.
In one operation (taking exactly 1 second), all occurrences of the substring "01" 
in s are simultaneously replaced with "10".
You must determine the total number of seconds required until the string contains 
no "01" substring, i.e., until all the '1' characters are positioned to the left 
of all the '0' characters.

Input

A binary string s of length n
(1≤n≤10^5).

Output
A single integer: the minimum number of seconds required to reach the stable state.
*/

int timeRequire(const string& str){
    int b=0;    // This counts the number of one's we've seen so far.
    int e=0;    // It is the index of the current char we're processing.
    int n = str.length();
    int maxtime=0;
    while(e<n){
        if(str[e] == '1'){
            maxtime = max(maxtime, e-b);
            b++;
        }
        e++;
    }

    return maxtime;
}

int main(){
    string str;
    cout << "Give a string: "; cin >> str;
    cout << "Time required: " << timeRequire(str) << endl;
}