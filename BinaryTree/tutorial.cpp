#include<bits/stdc++.h>
using namespace std;

/*
Basic implemntation of Binary tree and some algorithms to Traverse Binary Tree
*/
class node{
        
    public:
        int data;
        node* left;
        node* right;
        node(int d): data(d), left(NULL), right(NULL) { }
};

node* buildBinaryTree(node* root){
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root -> left = buildBinaryTree(root->left);
    cout << "Enter data for inserting in the right of " << data << endl;
    root -> right = buildBinaryTree(root->right);
    return root;
}

void levelOrdertraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
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

void reverselevelOrdertraversal(node* root){
    queue<node*> q;
    stack<int> st;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            st.push(-1);
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            st.push(temp->data);
            if(temp -> left){
                q.push(temp->left);
            }
            if(temp -> right){
                q.push(temp->right);
            }
        }
    }
    st.pop();       //// removing top -1
    
    while(!st.empty()){
        if(st.top() == -1) cout << endl;
        else {
            cout << st.top() << ' ' ;
        }
        st.pop();
    }
    cout << endl;
}

////// Inorder ( L N R )

void inorder(node* root){
    if(root == nullptr) return;

    inorder(root->left);
    cout << root->data << ' ';
    inorder(root -> right);

}

////// Preorder (N L R)

void preorder(node* root){
    if(root == nullptr) return;

    cout << root->data << ' ';
    preorder(root->left);
    preorder(root -> right);

}

////// Postorder ( L R N )

void postorder(node* root){
    if(root == nullptr) return;

    postorder(root->left);
    postorder(root -> right);
    cout << root->data << ' ';
    
}

///////// Inorder iteration
void itinorder(node* root){

}

///// build tree from level order
void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout << "Enter data for root " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp -> data << endl;
        int leftData; cin >> leftData;
        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp->left);
        }
        cout << "Enter right node for: " << temp->data << endl;
        int rightData; cin >> rightData;
        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
}   

int main(){
     node* root = NULL;

    // /// creating a Tree
    // root = buildBinaryTree(root);
    // /// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // cout << "Printing the level traversal output! " << endl;
    // levelOrdertraversal(root);
    // cout << "printing the reverse level traversal output! " << endl;
    // reverselevelOrdertraversal(root);

    // cout << "Inorder traversal of tree is : " << endl;
    // inorder(root);
    // cout << endl;

    buildFromLevelOrder(root);
    levelOrdertraversal(root);

    

}