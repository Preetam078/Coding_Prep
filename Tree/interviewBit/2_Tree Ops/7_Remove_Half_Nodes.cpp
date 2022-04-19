TreeNode* Solution::solve(TreeNode* root) {

   if(!root){
       return root;
   }

   //checking the leave node
   if(!root->left && !root->right){
       return root;
   }

   // hereif the left == null then skip then right and return next or vice versa
   if(!root->left) return solve(root->right);
   if(!root->right) return solve(root->left);

   root->left = solve(root->left);
   root->right = solve(root->right);

   return root;
}
