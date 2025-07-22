#include<bits/stdc++.h>

using namespace std;

///  words are attached via dot, so we have to reverse the order of the words out there.
class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string ans="";
        
        int j=0;
        while(j<S.length()){
            string word = "";
            while(j < S.length() && S[j] != '.'){
                word += S[j];
                j++;
            }
            if(!ans.empty())
            ans = word + '.' + ans;
            else{
                ans = word + ans;
            }
            j++;
        }
        return ans;
    } 
};

void rearrange(vector<char> &str, int start, int e){    
    while(e > start){
        swap(str[start] , str[e]);      // In place swapping to rearrange words.
        start++;
        e--;
    }
}
void reverseString(vector<char> &str){
    int start = 0;
    int n = str.size();

    for(int i{0}; i<=n; i++){
        if( i == n || str[i] == ' '){
            rearrange(str,start, i-1);
            start = i+1;
        }
    }
}

int main(){
    vector<char> str;
    char ch;
    for(int i{0}; ; i++){
        cin.get(ch);
        if(ch == '*') break;
        str.push_back(ch);
    }
    reverseString(str);
    for(auto i:str){
        cout << '"' << i << '"' <<' ';
    }
    cout  << endl;
}

// Here's slightly modified approach to reverse the words in string and the words are space separated.
void reversepart(string&s, int b, int e){
    while(b<e) swap(s[b++], s[e--]);
}
void reversestring2(string&s){
    int start=0;
    for(int end=0; end<s.length(); end++){
        if(s[end]==' '){
            reversepart(s, start, end-1);
            start=end+1;
        }
        reversepart(s, start, s.length()-1);
        reversepart(s, 0, s.length()-1);
    }
}

// There could be multiple dots between two words and in the beginning and in the end
class Solution {
  public:
    string reverseWords(string &s) {
        int start=0;
        int end=0;
        string ans="";
        int n = s.length();
        
        while(s[start]=='.')start++;
        end = start;
        while(s[n-1]=='.')n--;
        
        for( ; end<n; end++){
            if(s[end]=='.'){
                ans = "." + s.substr(start, end-start) + ans;
                while(end < n && s[end]=='.') end++;
                start = end;
                end--;
            }
        }
        ans = s.substr(start, end-start) + ans;
        return ans;
    }
};