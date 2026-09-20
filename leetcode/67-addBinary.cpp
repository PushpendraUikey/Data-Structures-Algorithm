#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int sa = a.length();
        int sb = b.length();
        if(sa < sb) return addBinary(b, a);
        int rem = 0;
        while(sb>0) {
            int val = (a[sa-1] - '0') + (b[sb-1] - '0') + rem;
            a[sa-1] = ('0' + val%2);
            rem = val/2;
            sa--;
            sb--;
        }

        while(sa > 0) {
            int val = (a[sa-1] - '0') + rem;
            a[sa-1] = ('0' + val%2);
            rem = val/2;
            sa--;
        }

        if(rem > 0) a = "1" + a;
        return a;
    }
};