#include<bits/stdc++.h>
using namespace std;

/// @brief Given here is algorithm to find the unique permutation of a string in lexicographic ordered
class Solution
{
    void solve(set<string>& ans, string& orig, string& path, unordered_set<int>& ind){
        if(path.length() == orig.length()){
            ans.insert(path);
            return;
        }
        
        for(int i=0; i<orig.length(); i++){
            if(ind.find(i)==ind.end()){
                path.push_back(orig[i]);
                ind.insert(i);
                
                solve(ans, orig, path, ind);

                ind.erase(i);   //// These here are the backTrack
                path.pop_back();    //// These here are the backTrack
            }
        }
    }
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string> ans;
		    string path = "";
		    unordered_set<int> ind;
		    
		    solve(ans, S, path, ind);
		    
		    vector<string> perm;
		    
		    for(auto& u : ans){
		        perm.push_back(u);
		    }
		    return perm;
		}
};
