#include "tutorial.cpp"

// Ceil(X) is a number that is either equal to X or is immediately greater than X.
// if ceil is not found then return -1;

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int poten = -1;
    
    while(root){
        if(root->data == input){
            return input;
        }
        if(root->data > input){
            poten = root->data;
            root = root->left;
        }else{
            root = root -> right;   //// once became greater than input it will go on right till exhaust
        }
    }
    return poten;
}