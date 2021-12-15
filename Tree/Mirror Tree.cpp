stack<Node *> st;
    Node *temp,*curr = node;
    while(curr->left!=NULL){
        st.push(curr);
        curr=curr->left;
    }
    while(st.empty()==false){
        temp = st.top;
        st.pop();
        curr = temp->left;
        temp->left = temp->right;
        temp->right = curr;
    }
    curr = node;
    while(curr->right!=NULL){
        st.push(curr);
        curr=curr->right;
    }
    while(st.empty()==false){
        temp = st.top;
        st.pop();
        curr = temp->left;
        temp->left = temp->right;
        temp->right = curr;
    }
