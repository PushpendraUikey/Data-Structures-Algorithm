#include <bits/stdc++.h>

//  calculate for every node in the tree the maximum length
//  of a path that begins at the node. This can be seen as a generalization of the tree
//  diameter problem, because the largest of those lengths equals the diameter of
//  the tree. Also this problem can be solved in O(n) time.
class Node{
    public:
    int data;
    Node* right;
    Node(int d):data(d){}
    Node* childrens;
};
void __Max_Path_FromChild(Node* root, std::unordered_map<Node*, int>&childDist){
    if(root==nullptr) return ;

    Node* child = root->childrens;
    while(child){
        __Max_Path_FromChild(child, childDist);
        childDist[root] = std::max(childDist[child]+1, childDist[root]);
        child = child->right;
    }
}