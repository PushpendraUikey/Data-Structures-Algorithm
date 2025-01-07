#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to get all possible permutation from the given given string with the and without 
updated character 
*/
class Solution {
private:
    char update(char& ch){
        if(ch <= 'z' && ch >= 'a'){
            return ch + 'A' - 'a';
        }else{
            return ch + 'a' - 'A';
        }
    }
    bool isChar(char ch){
        return ((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A'));
    }
    void solve(string s, int i, vector<string>& ans){
        // if the given string is not already there in answer then push it
        if(find(ans.begin(), ans.end(), s) == ans.end()){  
            ans.push_back(s);
        }
        if(i >= s.size()){
            return;
        }
        while( i < s.size() && !isChar(s[i])){
            i++;
        }
        if(i >= s.size()){
            return;
        }
      
        solve(s, i+1, ans);
        char ch = s[i];
        char ch1 = update(ch);
        s[i] = ch1;
        solve(s, i+1, ans);

    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(s, 0, ans);
        return ans;
    }
};

int main(){
    string sh = "a";
    vector<string> ans;
    Solution sb;
    ans = sb.letterCasePermutation(sh);

    for(int i{0}; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}