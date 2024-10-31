#include "tutorial.cpp"

vector<int> postOrder(node* n) {
        stack<node*> st;
        vector<int> ans;
        
        st.push(n);
        
        //// Logic is based on post order requires left right root, so do reverse it and then 
        //// first do root-right-left, then reverse it and done
        /// problem becomes similar to preorder traversal
        
        while(!st.empty()){
            node* top = st.top();
            st.pop();
            ans.push_back(top->data);
            
            // we're pushing right later because we wanna process right first when it'll be popped from the stack

            if(top -> left) st.push(top -> left);
            if(top -> right) st.push(top -> right);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }