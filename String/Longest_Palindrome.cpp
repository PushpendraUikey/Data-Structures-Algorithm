#include<iostream>
using namespace std;

/*
Here is the solution to the problem of finding the maximum length palindrome
that can be formed using the given word.
The idea is to basically count frequency of each letter of alphabet, capital & small
in the word and calculate palindrome accordingly
*/

class Solution {
public:
    void count_letter(char letter[][26], char c){
        for(int i{0}; i<26; i++){
            if(letter[0][i] == c){
                letter[1][i]++;
                break;
            }
        }
    }
    bool is_lowercase(char c){
        return (c >='a' && c <= 'z');
    }
    bool is_uppercase(char c){
        return (c >= 'A'&& c <= 'Z');
    }
    int longestPalindrome(string s) {
        int size = s.length();
        if(size==0) return 0;
        int count{0}, ones{0};
        char letterUp[2][26] = {{0}};
        char letterLow[2][26] = {{0}};

        for(char c = 'A',i = 0; c <= 'Z' && i < 26; c++,i++){
            letterUp[0][i] = c;
            letterUp[1][i] = 0;
        }
        for(char c = 'a',i = 0; c <= 'z' && i < 26; c++,i++){
            letterLow[0][i] = c;
            letterLow[1][i] = 0;
        }
        for(int i{0}; i<size; i++){
            if(is_uppercase(s[i])) count_letter(letterUp,s[i]);
            else count_letter(letterLow,s[i]);
        }
        for(int i{0}; i<26; i++){
            if(letterUp[1][i]%2==0){
                count += letterUp[1][i];
            }
            else{
                count += (letterUp[1][i]-1);
                ones++;
            } 
            if(letterLow[1][i]%2==0){
                count += letterLow[1][i];
            }
            else{
                count += (letterLow[1][i]-1);
                ones++;
            }          
        }
        if(ones > 0) count++;
        return count;
    }
};

// Alternative 1: Expand across a center
class Solution {
    string expand(string s, int l, int r){
        while(l>=0 && r<s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }
public:
    string longestPalindrome(string s) {
        string res = "";
        for(int i=0; i<s.size(); i++) {
            string odd = expand(s, i, i);
            string even = expand(s, i, i+1);
            if(odd.size() > res.size()) res = odd;
            if(even.size() > res.size()) res = even;
        }

        return res;
    }
};

int main(){
    string s;
    cin >> s;
    Solution sb;
    cout << sb.longestPalindrome(s) << endl;
}
