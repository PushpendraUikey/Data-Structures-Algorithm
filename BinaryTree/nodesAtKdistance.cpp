#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

void printNodeatDistK(Node* root, int k){
    if(!root) return;
    if(k==0){
        cout << root->data << endl;
        return;
    }
    printNodeatDistK(root->left, k-1);
    printNodeatDistK(root->right, k-1);
}