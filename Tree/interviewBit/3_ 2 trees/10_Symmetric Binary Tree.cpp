int compare(TreeNode* root1, TreeNode* root2){

     if(!root1 && !root2) return 1;

    if((!root1 && root2) || (root1 && !root2) || (root1->val != root2->val)) return 0;

    // compare both alternative left and right for symmetry
    return compare(root1->left, root2->right)&&compare(root1->right, root2->left);
}
int Solution::isSymmetric(TreeNode* root) {

    return compare(root, root);
}
