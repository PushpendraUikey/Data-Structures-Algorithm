#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

/*
Given two binary trees with head reference as T and S having at most N nodes. The task is to check 
if S is present as subtree in T.
A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.
*/

class Solution {
    bool solve(Node* t, Node* s){
        if(!t && !s) return true;
        if(!t || !s) return false;
        
        if(t->data != s->data) return false;
        return (solve(t->left, s->left) && solve(t->right, s->right));
    }
  public:

    bool isSubTree(Node* T, Node* S) {
        if(!S) return true;
        if(!T) return false;
        
        if(solve(T, S)) return true;
        return (isSubTree(T->left, S) || isSubTree(T->right, S));
    }
};