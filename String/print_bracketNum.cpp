#include <bits/stdc++.h>
using namespace std;


/*
Algorithm to assign numbers to the valid brackets
*/
// It is a brute force algorithm for the given problem.

class Solution {
  public:
    
    bool check(vector<int> res, int target){
        int count = 0;
        for(int i=0; i<res.size(); i++){
            if(res[i] == target) count++;
        }
        if(count > 1) return true;
        return false;
    }
    vector<int> bracketNumbers(string str) {
        vector<int> ans;
        vector<int> res;
        
        int len = str.length();
        
        for(int i{0}; i<len; i++) res.push_back(i+1);
        
        int countl = 1, countR = 1;
        
        for(int i{0}; i<len; i++){
            
            if(str[i] == '('){
                ans.push_back(countl);
                countR = countl++;
            }
            
            else if(str[i] == ')'){
                while(check(res,countR)){
                    countR--;
                }
                ans.push_back(countR);
                res.push_back(countR);
                countR--;
            }
            
        }
        
        return ans;
    }
};
// (((()()()((())))))

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}