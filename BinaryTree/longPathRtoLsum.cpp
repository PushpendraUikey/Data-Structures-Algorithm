#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

/*
Here is the code to find the maximum sum of longest 
root to root to leaf path
path given priority
*/
class Solution
{
    void solve(Node* root, int sum, int&maxSum, int len, int &maxlen){
        if(root == NULL){
            if(len>maxlen){
                maxSum = sum;
                maxlen = len;
            }else if(len == maxlen){
                maxSum = max(sum, maxSum);
            }
            return;
        }
        sum += root -> data;
        
        solve(root -> left , sum, maxSum, len+1, maxlen);
        solve(root -> right , sum, maxSum, len+1, maxlen);
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0;
        int maxLen = 0;
        int sum = 0;
        int maxSum = 0;
        
        solve(root, sum, maxSum, len, maxLen);
        
        return maxSum;
    }
};