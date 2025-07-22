#include <bits/stdc++.h>
using namespace std;

/*
https://www.naukri.com/code360/guided-paths/data-structures-algorithms/content/118521/offering/1380978
*/

bool diagonalAnagram(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    unordered_map<int, vector<int>> mp1, mp2;
    queue<pair<int, BinaryTreeNode<int>*>> q;

    q.push({0, root1});
    while(!q.empty()){
        pair<int, BinaryTreeNode<int>*> top = q.front();
        q.pop();
        int val = top.first;
        BinaryTreeNode<int>* node = top.second;


        mp1[val].push_back(node->data);
        if(node->left){
            q.push({val-1, node->left});
        }
        if(node->right){
            q.push({val, node->right});
        }
    }

    q.push({0, root2});
    while(!q.empty()){
        pair<int, BinaryTreeNode<int>*> top = q.front();
        q.pop();
        int val = top.first;
        BinaryTreeNode<int>* node = top.second;


        mp2[val].push_back(node->data);
        if(node->left){
            q.push({val-1, node->left});
        }
        if(node->right){
            q.push({val, node->right});
        }
    }

    int i=0; 
    while(mp1.find(i)!=mp1.end()){
        if(mp2.find(i) == mp2.end()) return false;

        if(mp1[i].size() != mp2[i].size()) return false;

        sort(mp1[i].begin(), mp1[i].end());
        sort(mp2[i].begin(), mp2[i].end());
        for(int j=0; j<mp1[i].size(); j++){
            if(mp1[i][j] != mp2[i][j]) return false;
        }
        i--;
    }
    if(mp2.find(i) != mp2.end()) return false;

    return true;

}