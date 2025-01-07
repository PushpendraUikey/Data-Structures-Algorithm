#include <bits/stdc++.h>

// from a vector of strings, we are removing the multiline and single line comments.

using namespace std;


vector<string> removeComments(vector<string> &text)
{
	vector<string> ans;
	int l = text.size();
	bool multiline = false;
	string a="";
	for(int i=0; i<l; i++){
		string tmp = text[i];
		
		for(int j=0; j<tmp.length(); j++){
			if(multiline && tmp[j] == '*'){
				if(tmp[j+1] == '/'){
					multiline = false;
					j++;
					continue;
				}
			}
			if(multiline) continue;
			if(tmp[j] == '/'){
				if(tmp[j+1]=='/'){
					break;
				}else if (tmp[j+1] == '*'){
					multiline = true;
					j++;
					continue;
				}
			}
			a += tmp[j];
		}
                if (!multiline && a != "") {
                        ans.push_back(a);
						a = "";
                }
        }
	return ans;
}