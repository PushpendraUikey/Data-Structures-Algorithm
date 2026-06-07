#include<bits/stdc++.h>
using namespace std;

///  solution to find longest common prefix

class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;
    
    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = nullptr;
        }
        childCount = 0;
        isTerminal = false;
    }
};
class Trie {
    public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string word){
        /// base case
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }
        int ind = word[0] - 'a';
        TrieNode* child;
        
        if(root->children[ind] != nullptr){
            child = root->children[ind];
        }else{
            child = new TrieNode(word[0]);
            root -> childCount++;
            root -> children[ind] = child;
        }
        
        insertUtil(child, word.substr(1));
    }
    void insert(string word){
        insertUtil(root, word);
    }
    
    void lcp(string str, string &ans){
        TrieNode* temp = root;
        
        for(int i=0; i<str.length(); i++){
            char ch = str[i];
            
            if(temp->childCount == 1){  
                ans = ans + ch;
                int ind = ch - 'a';
                temp = temp -> children[ind];   /// it is definite that word is present
            }else{
                break;
            }
            
            if(temp -> isTerminal){
                break;
            }
        }
        
    }
};
class Solution{
public:
    string LCP(string arr[], int n)
    {
        // code here
        Trie* t = new Trie();
        string ans = "";
        string first = arr[0];
        //// insert all the strings into trie
        
        for(int i=0; i<n; i++){
            t->insert(arr[i]);
        }
        
        t->lcp(first, ans);
        
        if(ans.empty()) ans = "-1";
        return ans;
    }
};