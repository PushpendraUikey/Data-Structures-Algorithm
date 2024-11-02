#include<bits/stdc++.h>
using namespace std;

/// @brief Among all possible prefixes of given words, find the common prefixes to all(maximul)


// this solution works in O(|strs[0]|*strs.size())
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.empty()) return "";

        // taken the base string and use it to compute
        string str =strs[0];    
        string ans = "";
        int n = strs.size();

        bool found = true;
        for(int i{0}; i < str.size(); i++){

            int j = 0;

            while(j < n){
                if( i >= strs[j].size()){
                    found = false;
                    break;
                }
                if( str[i] != strs[j][i] ){      // comparing with each words current index.
                    found = false;
                    break;
                }
                j++;
            }

            // from this point onward common prefix is not possible hence break.
            if(!found) break;
            ans += str[i];
        }

        return ans;
    }
};

// Better Solution
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) {
            return ""; // Return empty string if input vector is empty
        }

        std::string prefix = strs[0]; // Start with the first string as the initial prefix

        for (int i = 1; i < strs.size(); ++i) {
            // While the current string does not start with the prefix
            while (strs[i].find(prefix) != 0) {     // if curr string starts from the prefix, no need to process it, we're done with that string
                // Shorten the prefix by one character from the end
                prefix = prefix.substr(0, prefix.length() - 1);

                // If the prefix becomes empty, return an empty string
                if (prefix.empty()) {
                    return "";
                }
            }
        }

        return prefix;
    }
};