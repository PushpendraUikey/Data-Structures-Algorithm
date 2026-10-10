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