#include<bits/stdc++.h>

using namespace std;


/// @brief below here is the implementation, of what suggestions will come we start typying some words in 
/// our phone's contact list.

class TrieNode {
    public:
        char data;
        bool isTerminal;
        TrieNode* children[26];
        
        TrieNode(char ch){
            data = ch;
            isTerminal = false;
            for(int i=0; i<26; i++){
                children[i] = nullptr;
            }
        }
};
class Trie {
    public:
        TrieNode* root;
        
        Trie(){
            root = new TrieNode('\0');
        }
        
        void insertUtil(TrieNode* root, string word){
            if(word.length()==0){
                root->isTerminal = true;
                return;
            }
            
            int ind = word[0] - 'a';
            TrieNode* child;
            if(root->children[ind] != nullptr){
                child = root->children[ind];
            }else{
                child = new TrieNode(word[0]);
                root->children[ind] = child;
            }
            
            insertUtil(child, word.substr(1));
        }
        void insert(string word){
            insertUtil(root, word);
        }
        
        void printSuggestion(TrieNode* curr, vector<string>&temp, string prefix){
            if(curr -> isTerminal){
                temp.push_back(prefix);
            }
            
            for(char ch = 'a'; ch <= 'z'; ch++){
                TrieNode* next = curr->children[ch-'a'];
                
                if(next != nullptr){
                    prefix.push_back(ch);
                    printSuggestion(next, temp, prefix);
                    prefix.pop_back(); /// backTrack
                }
            }
        }
        
        vector<vector<string>> getSuggestion(string str){
            TrieNode* prev = root;
            vector<vector<string>> output;
            string prefix = "";
            bool wordnotFound = false;
            
            for(int i=0; i<str.length(); i++){
                char lastch = str[i];
                
                prefix.push_back(lastch);
                
                //// check for lastcharacter 
                TrieNode* curr = prev->children[lastch - 'a'];
                vector<string> temp;
                
                if(wordnotFound){
                    temp.push_back("0");
                    output.push_back(temp);
                    temp.clear();
                    continue;
                }
                /// if not found
                if(curr == nullptr){
                    // break;
                    wordnotFound = true;
                    temp.clear();
                    temp.push_back("0");
                    output.push_back(temp);
                    temp.clear();
                    continue;
                }
                
                // if found
                
                printSuggestion(curr, temp, prefix);
                
                output.push_back(temp);
                temp.clear();
                prev = curr;
            }
            
            return output;
        }
};
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie* t = new Trie();
        
        for(int i=0; i<n; i++){
            string str = contact[i];
            t->insert(str);
        }
        
        return t->getSuggestion(s);
    }
};