#include <bits/stdc++.h>
using namespace std;

class Solution {
    string solve(int n) {
        if(n==1) return "1";
        string temp = solve(n-1);

        string ans = "";
        int cnt = 1;
        for(int i=1; i<temp.size(); i++) {
            if(temp[i] == temp[i-1]) {
                cnt++;
            }else{
                ans += to_string(cnt) + temp[i-1];
                cnt = 1;
            }
        }
        ans += to_string(cnt) + temp[temp.size()-1];
        return ans;
    }
public:
    string countAndSay(int n) {
        return solve(n);
    }
};

// There's this important property of count and say sequence that the count of any digit
// in the sequence is never more than 3. So we can use this property to optimize the solution
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        
        string current = "1";
        for(int step = 2; step <= n; step++) {
            string next_str = "";
            //prelocation of memory to avoid relocation overhead.
            next_str.reserve(current.size() * 2);
            int cnt = 1;
            for(int i=1; i<current.size(); i++) {
                if (current[i] == current[i-1]) {
                    cnt++;
                } else {
                    // bcz the cnt isn't going to be more than 3 (property!)
                    next_str += (cnt + '0');
                    next_str += current[i-1];
                    cnt = 1;
                }
            }

            next_str += (cnt + '0');
            next_str += current.back();

            current = next_str;
        }
        
        return current;
    }
};