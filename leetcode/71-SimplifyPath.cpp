#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> stack;

        while(getline(ss, token, '/')){
            // ignore empty string from "//" or "." for current directory
            if(token == "" || token == "."){
                continue;
            }
            // pop the parent directory
            else if (token == ".."){
                if(!stack.empty()) stack.pop_back();
            } 
            // push all the valid directory
            else{
                stack.push_back(token);
            }
        }

        string ans = "";
        for(int i=0; i<stack.size(); i++) {
            ans += "/" + stack[i];
        }

        return ans.empty() ? "/" : ans;
    }
};

class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        int len = path.length();
        deque<string> curr;

        auto idx = path.find('/');

        while(idx != string::npos) {
            while(idx+1 < len && path[idx+1] == '/') idx++;
            auto sec = path.find('/', idx+1);
            string first, second;

            if(sec != string::npos) {
                first = path.substr(idx, sec-idx);
                second = path.substr(sec);
                len -= sec;
                idx = 0;
                path = second;
            } else{
                first = path.substr(idx);
                if(first == "/..") {if(!curr.empty()) curr.pop_back();}
                else if (first.length() > 1 && first != "/."){
                    curr.push_back(first);
                }
                break;
            }
            if (first == "/.") {
                continue;
            }
            if (first == "/..") {
                if(!curr.empty())
                    curr.pop_back();
            }
            else{
                curr.push_back(first);
            }
        }

        while(!curr.empty()) {
            string tem = curr.front(); curr.pop_front();
            ans = ans + tem;
        }
        if(ans.empty()) return "/";
        return ans;
    }
};