int Solution::isSameTree(TreeNode* root1, TreeNode* root2) {
    
    if(!root1 && !root2){
        return 1;
    }

    if((!root1 && root2) || (root1 && !root2) || (root1->val != root2->val)){
        return 0;
    }
    // same as quesiton 10 only here is the twist
    return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}
