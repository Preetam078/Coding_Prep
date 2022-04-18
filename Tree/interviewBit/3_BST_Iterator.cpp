//https://www.interviewbit.com/problems/bst-iterator/


//initailly add the left elements in the stack because we are taking intution of INORDER
//inorder is sorted in BST

/*
 TC = O(n)
 SC = O(H) -> height of the tree

 optional SC = O(n) if we use inorder array wala approach
*/


stack<TreeNode*>st;

//pushing all the left element 
void pushAll(TreeNode* root){
    if(root == NULL){
        return;
    }
    st.push(root);
    pushAll(root->left);
}

BSTIterator::BSTIterator(TreeNode *root) {

    //initially added left element 
    pushAll(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
     return !st.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    

    // after getting the next traverse to the right and again left because the node just be greater than current node but it must be smaller than the root.

    TreeNode* temp = st.top();
    st.pop();

    pushAll(temp->right);
    return temp->val;
}
