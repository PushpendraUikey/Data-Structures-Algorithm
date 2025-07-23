#include "allnodeDef.h"


/// @brief Here is the alogithm for iterative inorder traversal
/// @param  Idea is to first push all the left subtree's node in stack then when left's leef reached, then pop, then process then go to.
/// @return right subtree, repeat the process of left node pushing in right subtree
vector<int> inOrder(node* root)
    {
        //code here
        stack<node*> st;
        vector<int> ans;
        
        node* temp = root;
        
        while(temp){            // first push all the left-most nodes
            st.push(temp);
            temp = temp -> left;
        }
        
        while(!st.empty()){     // till all the nodes processed 
            node* top = st.top();
            st.pop();
            ans.push_back(top->data);
            
            if(top->right) {    // start pushing the right subtree of tree.
                top = top -> right;
                while(top){
                    st.push(top);
                    top = top -> left;
                }
            }
        }
        
        return ans;
    }