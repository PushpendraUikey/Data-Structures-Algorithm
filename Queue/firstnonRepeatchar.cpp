#include<bits/stdc++.h>
using namespace std;

/*
Given a string A representing a stream of lowercase characters, determine the first non-repeating 
character at each position in the stream. Return a new string where each character represents the 
first non-repeating character up to that point; if no non-repeating character exists, use '#'.

Example:

Input: "aabc"
Output: "a#bb" 
*/

class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<char, int> count;
		    queue<char> q;
		    string ans="";
		    
		    for(int i=0; i<A.length(); i++){
		        char ch = A[i];
		        
		        count[ch]++; // if element is not present then it automatically initialze's with zero in map
		        q.push(ch);
		        while(!q.empty()){
		            if(count[q.front()]>1){
		                q.pop();
		            }else{
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty()){
		            ans.push_back('#');
		        }
		        
		    }
		    
		    return ans;
		}

};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}