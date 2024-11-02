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