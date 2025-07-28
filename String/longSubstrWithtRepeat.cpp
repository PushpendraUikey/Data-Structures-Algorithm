#include <bits/stdc++.h> 
using namespace std;

/*
Algorithm to find the unique substring in the given input string(maximum)
Return: maximum possible unique substring length(that does not have any repeating charac)

This problem is also referred as finding longest substring with distinct characters
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


// First O(n^3) solution
bool Aredistinct(const string&str, int i, int j){
    vector<bool> visited(256, false);
    for(int k=i; k<=j; k++){
        if(visited[str[k]]==true){
            return false;
        }
        visited[str[k]] = true;
    }
    return true;
}
int longestDistinct(const string& str){
    int n = str.length();
    int res = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(Aredistinct(str, i, j)){
                res = max(res, j-i+1);
            }
        }
    }
    return res;
}

// Here is O(n^2) solution to the above problem of longest Distinct substring
int longestDistinct_eff(const string& str){
    int n = str.length();
    int res = 0;

    for(int i=0; i<n; i++){
        vector<bool> visited(256, false);
        for(int j=i; j<n; j++){
            if( visited[str[j]] == true) break;
            else{
                res = max(res, j-i+1);
                visited[str[j]] = true;
            }
        }
    }
}

// Here's the O(n) Optimized solution like the first solution in this file
int longestDistinct_opt(const string& str){
    int n = str.length();
    int i = 0;
    int res = 0;
    vector<int> lastidx(256, -1);
    for(int j=0; j<n; j++){
        i = max(i, lastidx[str[j]]+1);
        int maxend = j-i+1;
        res = max(res, maxend);
        lastidx[str[j]] = j;
    }
    return res;
}


// Credit: GfG
/*
Method 5 (Linear time):   In this method we will apply  KMP Algorithm technique, to solve the problem. 
We maintain an Unordered Set to keep track of the maximum non repeating char sub string (Instead of 
standard LPS array of KMP). When ever we find a repeating char, then we clear the Set and reset len 
to zero. Rest everything is almost similar to KMP.
*/
int longestSubstrDistinctChars(string s)
{
	if (s.length() == 0)
		return 0;
	int n = s.length();
	set<char> st;
	int len = 1;
	st.insert(s[0]);
	int i = 1;
	int maxLen = 0;
	while (i < n)
	{
		if (s[i] != s[i - 1] && st.find(s[i]) == st.end())
		{
			st.insert(s[i]);
			len++;
			i++;
			if (len > maxLen)
			{
				maxLen = len;
			}
		}
		else
		{
			if (len == 1)
			{
				i++;
			}
			else
			{
				st.clear();
				i = i - len + 1;
				len = 0;
			}
		}
	}
	return max(maxLen, len);
}


int main()
{
	string str = "abcabcbb";
	cout << "The input string is " << str << endl;
	int len = longestSubstrDistinctChars(str);
	cout << "The length of the longest non-repeating character substring " << len;
	return 0;
}