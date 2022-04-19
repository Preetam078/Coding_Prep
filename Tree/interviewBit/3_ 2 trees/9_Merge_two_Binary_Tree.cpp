/*
  TC - O(n) for the traversal
  Axuiliary SC = O(n) because of the recursion
  SC = O(1)
*/
TreeNode* Solution::solve(TreeNode* root1, TreeNode* root2) {


    if(root1 == NULL){
        return root2;
    }

    if(root2 == NULL){
        return root1;
    }
    
    // in order to merge the tree just add the both tree value and proceed further.
    root1->val = root1->val + root2->val;

    root1->left = solve(root1->left, root2->left);
    root1->right = solve(root1->right, root2->right);

    return root1;
}
