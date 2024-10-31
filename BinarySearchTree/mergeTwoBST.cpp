#include<bits/stdc++.h>
using namespace std;

/*
Following here are given two algorithms to merge two BST's
*/
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

/* 
//// This is the fisrt solution to merge two BST's 

void inorder(TreeNode* root, vector<int> &input){
    if(root == NULL) return;

    inorder(root->left, input);
    input.push_back(root->data);
    inorder(root->right, input);
}
vector<int> mergeTwoarr(vector<int>& arr1, vector<int>& arr2){
    int i=0; int j=0;
    vector<int> ans;
    while(i<arr1.size() || j < arr2.size()){
        if(i < arr1.size() && j < arr2.size()){
            if(arr1[i] < arr2[j]){
                ans.push_back(arr1[i]);
                i++;
            }else{
                ans.push_back(arr2[j]);
                j++;
            }
        }
        else if(i<arr1.size()){
            ans.push_back(arr1[i]);
            i++;
        }
        else if(j < arr2.size()){
            ans.push_back(arr2[j]);
            j++;
        }
    }
    return ans;
}
*/

/// you will pass head = nullptr; then this head will keep updating till you finally reach the lowest value node.
// *This will convert BST to a sorted DLL*<Dry Run>
void convertTosortedDLL(TreeNode* root, TreeNode* &head){
    // base case
    if(root == nullptr) return ;
    convertTosortedDLL(root->right, head);

    root -> right = head;

    if(head != nullptr){
        head -> left = root;
    }
    head = root;

    convertTosortedDLL(root->left, head);

}

//// It'll count nodes in DLL
int countNodes(TreeNode* root){
    int cnt = 0;
    while(root){
        cnt++;
        root = root -> right;
    }
    return cnt;
}

//// This will convert sorted DLL to a BST
TreeNode* SorteddLLtoBST(TreeNode* &head, int n){
    if(n<=0 || head == nullptr){
        return nullptr;
    }
    TreeNode* left = SorteddLLtoBST(head, n/2);

    TreeNode* root = head;
    root -> left = left;

    head = head -> right;

    root->right = SorteddLLtoBST(head, n - n/2 -1);

    return root;
}

TreeNode* mergeToDLL(TreeNode* head1, TreeNode* head2){
    TreeNode* head = nullptr;
    TreeNode* tail = nullptr;

    while(head1 && head2){
        if(head1->data > head2->data){
            if(head == nullptr){
                tail = head2;
                head = head2;
                head2 = head2->right;
            }else{
                head -> right = head2;
                head2 -> left = head;
                head = head2;
                head2 = head2 -> right;
            }
        }else{
            if(head == nullptr){
                tail = head1;
                head = head1;
                head1 = head1->right;
            }else{
                head -> right = head1;
                head1 -> left = head;
                head = head1;
                head1 = head1 -> right;
            }
        }
    }
        if(head1){
            if(head == nullptr){
                tail = head1;
                head = head1;
                head1 = head1->right;
            }else{
                head -> right = head1;
                head1 -> left = head;
                head = head1;
                head1 = head1 -> right;
            }
        }
        if(head2){
            if(head == nullptr){
                tail = head2;
                head = head2;
                head2 = head2->right;
            }else{
                head -> right = head2;
                head2 -> left = head;
                head = head2;
                head2 = head2 -> right;
            }
        }

        head -> right = nullptr;
        return tail;
}

// vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
// {
//     vector<int> arr1;
//     vector<int> arr2;
//     inorder(root1, arr1);
//     inorder(root2, arr2);
//     return mergeTwoarr(arr1, arr2);

// }

int main(){}