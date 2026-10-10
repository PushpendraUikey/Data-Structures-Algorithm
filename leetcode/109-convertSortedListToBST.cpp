#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
    TreeNode* build(vector<int>&arr, int b, int e) {
        if(b > e) return nullptr;
        int mid = b + (e - b)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = build(arr, b, mid-1);
        root->right = build(arr, mid+1, e);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }

        return build(arr, 0, arr.size()-1);
    }
};


// Bottom Up Approach - Building According to the Inorder Traversal
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // 1. Count total nodes to determine the bounds
        int size = 0;
        ListNode* curr = head;
        while (curr) {
            size++;
            curr = curr->next;
        }
        
        // 2. Build the tree recursively
        return buildTree(head, 0, size - 1);
    }

private:
    // Pass 'head' by reference so it advances globally as the recursion unwinds
    TreeNode* buildTree(ListNode*& head, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;

        // Build the left subtree first (this simulates the "Left" in in-order traversal)
        TreeNode* leftChild = buildTree(head, left, mid - 1);

        // Process the current node (the "Root")
        TreeNode* root = new TreeNode(head->val);
        root->left = leftChild;
        
        // Advance the linked list pointer
        head = head->next;

        // Build the right subtree (the "Right")
        root->right = buildTree(head, mid + 1, right);

        return root;
    }
};