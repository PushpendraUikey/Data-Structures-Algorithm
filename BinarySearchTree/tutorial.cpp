#include<bits/stdc++.h>
using namespace std;

/*
Basic Tree constructions and standard algorithms run on BST
*/
class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d=0):data(d), left(nullptr), right(nullptr) { }
};

Node* insertintoBST(Node* root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if(d > root -> data){
        root -> right = insertintoBST(root->right, d);
    }else{
        root -> left = insertintoBST(root->left, d);
    }
    // cout << "Final Root reached!" << endl;
    return root;
}

void takeInput(Node* &root){
    int d;
    cin >> d;
    while(d != -1){
        root = insertintoBST(root, d);
        cin >> d;
    }
}
Node* minVal(Node* root){
    if( root == NULL ) return root;
    Node* curr = root;
    while(curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}
Node* deleteFromBST(Node* root, int val){
    if(root == NULL) return root;

    if(root->data == val){
        // 0 child
        if(root->left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        // 1 child
        // Left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        // 2 child
        if(root->left != NULL && root -> right != NULL){
            /// Either find out the mini of right-side or maxi of left side and replace it with the root, and delete the node from where did you get it
            int mini = minVal(root->right)->data;
            root -> data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if(root ->data > val){
        //// left side has the value.
        root->left = deleteFromBST(root->left, val);
        return root;
    }else{
        //// Right side has the value
        root -> right = deleteFromBST(root->right, val);
        return root;
    }
}

void levelOrdertraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << temp -> data << ' ';
            if(temp -> left){
                q.push(temp->left);
            }
            if(temp -> right){
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node* root){
    if(root == nullptr) return;

    inorder(root->left);
    cout << root->data << ' ';
    inorder(root -> right);

}

int main(){
    Node* root = NULL;

    cout << "Enter data to create BST: " << endl;
    takeInput(root);

    cout << "Printing BST. " << endl;
    levelOrdertraversal(root);
    cout << endl;

    cout << "Printing BST in inordered traversal: " << endl;
    inorder(root);
    cout << endl;

    root = deleteFromBST(root, 33);
    cout << "After deletion: " << endl;
    levelOrdertraversal(root); cout << endl;
    inorder(root);
}

//829 139 545 1389 1993 134891 5489 3881 3920 38419 483 -1