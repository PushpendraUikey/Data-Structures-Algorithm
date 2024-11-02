#include<bits/stdc++.h>
using namespace std;

/*
Here is the algorithm to compute the compressed string from given input
*/


/// The following algorithm computes the compressed string alongwith
/// the length of compressed string

// int compress(vector<char>&  chars){
//     int i = 0;
//     int ansIndex = 0;
//     int n = chars.size();

//     while( i < n){
//         int j = i+1;
//         while(j < n && chars[i] == chars[j]){
//             j++;
//         }

//         chars[ansIndex++] = chars[i];

//         int count = j-i;
//         if(count > 1){
//             string cnt = to_string(count);
//             for(auto it : cnt){
//                 chars[ansIndex++] = it;
//             }
//         }
//         i = j;
//     }
//     return ansIndex;
// }

string getCompressedString(string &input) {
    int j = 0;
    int n = input.size();
    string ans;

    for (int i{0}; i<n; ){

        j = i+1;

        // counting the frequency of that character
        while( j < n && input[j] == input[i]){
            j++;
        }

        // insert the character
        ans.push_back(input[i]);

        // insert the character's frequency.
        int count = j-i;
        if(count > 1){
            char ch = '0' + count;
            ans.push_back(ch);
        }
        // start from the next character
        i = j;
    }
    return ans;
}

int main(){
    string s; cin >> s;
    string ans = getCompressedString(s);
    cout << ans << endl;
}