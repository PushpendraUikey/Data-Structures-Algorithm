#include<bits/stdc++.h>
using namespace std;


class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i=0; i<26; i++){
                children[i] = nullptr;
            }
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
            if(word.length() == 0){
                root->isTerminal = true;        /// last node's isterminal's true to show the words end;
                return;
            }

            //// assuming all the words are small letter
            int index = word[0] - 'a';

            TrieNode* child;
            /// present 
            if(root->children[index] != nullptr){
                child = root->children[index];
            }else{
                /// absent , then make one 
                child = new TrieNode(word[0]);
                root -> children[index] = child;
            }

            //// Recursion
            insertUtil(child, word.substr(1));
        }

        void  insertWord(string word){
            insertUtil(root, word);
        }


        //// Searching 
        bool searchUtil(TrieNode* root, string word){
            // base case
            if(word.length() == 0){
                return root->isTerminal;
            }
            int index = word[0] - 'a';
            TrieNode* child;

            //// present
            if(root->children[index] != nullptr){
                child = root -> children[index];
            }else{
                /// absent 
                return false;
            }

            /// Recursion
            return searchUtil(child, word.substr(1));

        }
        bool searchWord(string word){
            return searchUtil(root, word);
        }


        ///// Removal
        bool removeUtil(TrieNode* root, string word){
            //// base case
            if(word.length() == 0){     /// indicates that the word is found 
                /// unmark the terminal node
                if(root->isTerminal){   //// indicates word is found and is Present in the Trie
                    root->isTerminal = false;
                }
                
                /// Check if the node can be deleted(i.e. not terminal and no children are there)
                for(int i=0; i<26; i++){
                    if(root->children[i] != nullptr){
                        return false;       ///// cannot be deleted.
                    }
                }

                // can be deleted
                return true;

            }
            int index = word[0] - 'a';
            TrieNode* child;
            if(root->children[index] != nullptr){
                //// child is present
                child = root->children[index];
            }else{
                /// word not present
                return false;
            }

            bool shouldBeDelted = removeUtil(child, word.substr(1));

            if(shouldBeDelted){
                delete root->children[index];
                root->children[index] = nullptr;
            }

            //// check if current node can be deleted
            if(root->isTerminal){
                //// can't be deleted as it is a teminal
                return false;
            }

            //// check if it has any children(if it has can't be deleted)

            for(int i=0; i<26; i++){
                if(root->children[i] != nullptr){
                    // it has children 
                    return false;
                }
            }

            /// no chilren found as well as it is not an terminal(i.e. not part of any word) can be delted easily
            return true;
        }

        void removeWord(string word){
            removeUtil(root, word);
        }
};

int main(){
    Trie *t = new Trie();
    t->insertWord("abcdefghighkal");
    t->insertWord("abdc");
    t->insertWord("pushpendra");
    t->insertWord("uikerlj");
    t->insertWord("uipqres");
    t->insertWord("uikey");

    if(t->searchWord("uikey")){
        cout << "My sirname is present in the Trie" << endl;
    }
    t->removeWord("uikey");
    if(t->searchWord("uikey")){
        cout << "My sirname is present in the Trie" << endl;
    }else{
        cout << "Naam to nhi hai bhai!" << endl;
    }
    if(t->searchWord("uipqres")){
        cout << "word found!" << endl;
    }else{
        cout << "word not found!" << endl;
    }
}