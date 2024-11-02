#include <bits/stdc++.h> 
using namespace std;

/*
Algorithm to find the unique substring in the given input string(maximum)
Return: maximum possible unique substring length(that does not have any repeating charac)
*/
int uniqueSubstrings(string input)
{
    map<char, int> mp;

    int len = input.length();
    int maxLen = -1;
    int first = 0;

    for(int i=0; i<len; i++){
        char ch = input[i];

        if(mp.find(ch) != mp.end() && mp[ch] >= first){ 
            //// if some index have already the ch then it is repeatation of ch in that substr i.e. update
            first = mp[ch] + 1; 
        }
        
        mp[ch] = i;     //// keep the most recent index of the character in the map.

        maxLen = max(maxLen, i-first+1);        //// update max in each iteration
    }

    return maxLen;
}