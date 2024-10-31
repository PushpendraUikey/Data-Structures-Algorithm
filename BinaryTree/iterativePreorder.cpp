#include "tutorial.cpp"

/*
Here is the code to find preorder traversal iteratively
*/
vector<int> preOrder(node* root)
    {
        vector<int> ans;
        
        stack<node*> st;
        st.push(root);
        
        while(!st.empty()){
            node* top = st.top();
            st.pop();
            ans.push_back(top->data);
            
            // Idea is to push left later so that it will be processed first when extracted from stack.
            if(top->right) st.push(top->right);
            if(top->left) st.push(top->left);
        }
        
        return ans;
    }